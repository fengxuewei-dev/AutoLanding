#include "SendNewWaypoints.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "SendNewWaypoints");
    ros::NodeHandle nh;

	int j = 0;
	bool has_exit_signal{false};
    bool is_conti_waylist{false};

    ROS_INFO("The send_waypoints node is opened!");
    ROS_INFO("It will upload the waypointList to the vehicle: ");


    std::string uavName = argv[1]; // 获取 uav1
    if(uavName[0] != '/' && uavName[0] != 'u'){ // 没有命令行参数
        ROS_INFO("The vehicle that you will control is single!");
        uavName = "";
    } else { // 存在命令行参数, 则 指定操作的飞机
        uavName = argv[1];
        if('/' != uavName[0]){// 如果第一个字符不是 '/'
            uavName = "/" + uavName;
        }
        ROS_INFO("You need to input the vehicle the ");
        ROS_INFO(("selected uav:"));	
		ROS_INFO("%s",(uavName.c_str()));
    } 

    // 获得 航点组
    ros::Subscriber waypoints_list_sub = nh.subscribe<mavros_msgs::WaypointList>
            (uavName + "/mavros/mission/waypoints", 10, &waypointlist_from_px4_sub);

    // 发送 新的航点组 的服务
    ros::ServiceClient sendWps = nh.serviceClient<mavros_msgs::WaypointPush>
            (uavName + "/mavros/mission/push");

    // 发送 request
    ros::ServiceClient waypoint_pull_client = nh.serviceClient<mavros_msgs::WaypointPull>
            (uavName + "/mavros/mission/pull");

    // 清空航点    
    ros::ServiceClient clearWps = nh.serviceClient<mavros_msgs::WaypointClear>
            (uavName + "/mavros/mission/clear");

    // 获得 home 点的位置
    ros::Subscriber home_sub = nh.subscribe<mavros_msgs::HomePosition> 
        (uavName + "/mavros/home_position/home", 10, homePosition_cb);


    mavros_msgs::WaypointPush waypointpush;
    mavros_msgs::WaypointPull waypointpull;
    mavros_msgs::WaypointClear waypointclear;

    // 1. 寻找结束标志符号
	size_t num = 0;
	for(size_t i = 0; i < argc; i++)
	{
		string _argv = argv[i];
		if(!(_argv.compare("EXIT") && _argv.compare("exit"))) // 0 == 相等
		{// 存在结束标志位
			has_exit_signal = true;
			num = i; // 前面的 num 从1开始的
		}
	}
    is_conti_waylist = atoi(argv[2]);

    // 2. 获取 exit signal 前一个的位置
	if(has_exit_signal){
        size_t i = 2;
        size_t k = 3;
		if((num - k) % WAYPOINT_STATE_NUMBER == 0) // 航点的信息为完整的!
		{	
            //the setpoint publishing rate MUST be faster than 2Hz
            ros::Rate rate(20.0);

            // bool flag = Y_N();

            // if(flag == false)
            // {
            //     return 0;
            // }

            // 调用后不会再返回，也就是你的主程序到这儿就不往下执行了
            // 0. 先执行回调函数, 执行了之后后面的程序仍会执行
            while(ros::ok() && home_position.geo.latitude == 0.000000 )
            {
                // 当home点的值不为0的时候, 继续往下执行, 
                // 当home点的值为0(默认初始值) 的时候, 继续等待
                cout << "waiting..." << endl;
                ros::spinOnce();
                rate.sleep();
            }

            if(is_conti_waylist){
                // 获得航点
                waypointpush.request.waypoints = waypoint_list.waypoints;
            }
            // 2. 清空航点: 
            if(clearWps.call(waypointclear) && waypointclear.response.success){
                ROS_INFO("Waypointers have been cleared! \t\t SUCCEED");
            }
			for(j = 1; i + 5 < num; j++){
                mavros_msgs::Waypoint wps;

                wps.frame = atoi(argv[++i]);
                wps.command = atoi(argv[++i]);
                
                wps.param1 = atof(argv[++i]);
                wps.param2 = atof(argv[++i]);
                wps.param3 = atof(argv[++i]);
                wps.param4 = atof(argv[++i]);

                wps.x_lat =  atof(argv[++i]);
                wps.y_long =  atof(argv[++i]);
                wps.z_alt =  atof(argv[++i]);
                
                waypointpush.request.waypoints.push_back(wps);
				
                // 打印输出
                print_wp(wps);
			}
            // 4. 上传数据
            if(sendWps.call(waypointpush) &&
                // Returns success status and transfered count
                waypointpush.response.success){
                
                ROS_INFO("The node has pushed new waypoints!\t\t SUCCEED");
                ROS_INFO("the transfered count is %d", waypointpush.response.wp_transfered);
                
            }
		}
		else{
			cout << "Incorrect the argv: Waypoint information is incomplete" << endl;
		}
	}else{
		cout << "Please make sure the exit signal -- \"EXIT\"!" << endl;
	} 
    // 程序运行到这里暂停运行, 执行回调函数
    ros::spin();
}