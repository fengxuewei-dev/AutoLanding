/**
 * @file OneClickLanding.cpp
 * @brief one_click landing
 * @author fengxuewei
 * 
 * 命令行参数: lat, long, slope_angle, distance  ==> 5个参数
 * 手动给定 降落点的位置 和 方位角 , 以及设定 距离 ===> 可以计算出来 approach wp 的距离
*/
#include "OneClickLanding.hpp"

int main(int argc, char **argv)
{
    if(argc < 5){
        ROS_INFO("Missing command line arguments, please check them");
        return 0;
    }
    ros::init(argc, argv, "OneClickLanding");

    ros::NodeHandle nh;

    ROS_INFO("The OneClickLanding node is opened!");

    // 获取命令参数:
    // 命令行参数: lat, long, slope_angle, distance  ==> 5个参数
    point Land_wp; // 着落点
    point approact_wp; // 降落点
    point approact_pre_wp; // 降落点之前的航点  === land start
    point approact_pre2_wp; // 降落点之前的航点 === 第一个航点
    
    // 47.3981894 8.5485312 45 140
    double Dir_angle;     // 轨道的角度
    double dist_appWP_landWP;
    

    std::string uavName;
    if(argc == 5){ // 没有命令行参数
        ROS_INFO("The vehicle that you will control is single!");
        uavName = "";
        //atoll(argv[1]);
        Land_wp.lat = atof(argv[1]);
        Land_wp.lon = atof(argv[2]);
        Dir_angle = atof(argv[3]);
        dist_appWP_landWP = atof(argv[4]);
    } else if(argc == 6){ // 存在命令行参数, 则 指定操作的飞机
        uavName = argv[1];
        if('/' != uavName[0]){// 如果第一个字符不是 '/'
            uavName = "/" + uavName;
        }
        // ROS_ERROR("You need to input the vehicle the ");
        ROS_INFO(("selected uav:"));	
		ROS_INFO("%s",(uavName.c_str()));
        Land_wp.lat = atof(argv[2]);
        Land_wp.lon = atof(argv[3]);
        Dir_angle = atof(argv[4]);
        dist_appWP_landWP = atof(argv[5]);
    } else {
        ROS_ERROR("Incorrect number of parameters!");
        return 0;
    }

    ROS_INFO("Land_wp.lat = %f", Land_wp.lat);
    ROS_INFO("Land_wp.lon = %f", Land_wp.lon);
    ROS_INFO("Dir_angle = %f", Dir_angle);
    ROS_INFO("dist_appWP_landWP = %f", dist_appWP_landWP);
    
    if(dist_appWP_landWP <= (int)MIN_DISTANCE_BET_WPS){
        ROS_ERROR("The distance setted is not vaild, it should higher than %d m", (int)MIN_DISTANCE_BET_WPS);
        return 0;
    } 
    
    // 计算 approach wp 的经纬度
    // point getDestPoint(point lonlat, double brng, int dist);
    approact_wp = getDestPoint(Land_wp, Dir_angle, dist_appWP_landWP);

    // 计算 approach previous wp 的经纬度: 方位角 Dir_angle, 距离 DIST_BET_WPS 起始点: approach wp
    approact_pre_wp = getDestPoint(approact_wp, Dir_angle, DIST_BET_WPS);
    approact_pre2_wp = getDestPoint(approact_pre_wp, Dir_angle, DIST_BET_WPS);

    // 1. 获取home点的位置 ==> 着陆点的位置
    ros::Subscriber home_sub = nh.subscribe<mavros_msgs::HomePosition> 
            ("mavros/home_position/home", 10, homePosition_cb); 

    // 订阅 无人机的航点位置
    ros::Subscriber waypoints_list_sub = nh.subscribe<mavros_msgs::WaypointList>
            ("mavros/mission/waypoints", 10, &waypointlist_from_px4_sub);
    
    // 发送 新的航点组 的服务
    ros::ServiceClient sendWps = nh.serviceClient<mavros_msgs::WaypointPush>
            ("mavros/mission/push");

    // 清空航点    
    ros::ServiceClient clearWps = nh.serviceClient<mavros_msgs::WaypointClear>
            ("mavros/mission/clear");

    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
            ("mavros/state", 10, state_cb);

    ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>
            ("mavros/setpoint_position/local", 10);

    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>
            ("mavros/cmd/arming");
            
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
            ("mavros/set_mode");

    // 发送 land_start 指令
    ros::ServiceClient command_long_client = nh.serviceClient<mavros_msgs::CommandLong>
            ("mavros/cmd/command");        

    //Rate MUST be faster than 2Hz
    ros::Rate rate(10.0);
     
    // bool flag = Y_N();

    // if(flag == false)
    // {
    //     return 0;
    // }

    mavros_msgs::WaypointPush waypointpush;
    mavros_msgs::WaypointClear waypointclear;

    // 3. 清空航点
    if(clearWps.call(waypointclear) && waypointclear.response.success){
        ROS_INFO("Waypointers have been cleared! SUCCEED");
    }

    mavros_msgs::Waypoint wps;
   
    {
     	wps.frame = MAV_FRAME_GLOBAL_RELATIVE_ALT;
        wps.command = MAV_CMD_NAV_WAYPOINT;
	
        wps.is_current = 1;
        wps.autocontinue = 1;
        wps.param1 = 0; 
        wps.param2 = 0;
        wps.param3 = 0; 
        
        wps.x_lat = approact_pre2_wp.lat;
        wps.y_long = approact_pre2_wp.lon;
        wps.z_alt = 50;
        
	    waypointpush.request.waypoints.push_back(wps);
    }
    // mavros_msgs::CommandLong cmd{};
    // cmd.request.command = MAV_CMD_DO_LAND_START;
    // cmd.request.confirmation = false;
    // cmd.request.broadcast = false;
    // cmd.request.param1 = NAN;
    // cmd.request.param2 = NAN;
    // cmd.request.param3 = NAN;
    // cmd.request.param4 = NAN;
    // cmd.request.param5 = approact_pre_wp.lat;
    // cmd.request.param6 = approact_pre_wp.lon;
    // cmd.request.param7 = NAN;

    // if(command_long_client.call(cmd) && cmd.response.success){
    //     ROS_INFO("The command, MAV_CMD_DO_LAND_START, has be send successfully!");
    // }

    // mission item - wp (direct to land)
    {
     	wps.frame = MAV_FRAME_GLOBAL_RELATIVE_ALT;
        wps.command = MAV_CMD_NAV_WAYPOINT;
	
        wps.is_current = 0;
        wps.autocontinue = 1;

        wps.param1 = 0;
        wps.param2 = 0;
        wps.param3 = 0; // empty
        wps.param4 = 0;
        
        wps.x_lat = approact_wp.lat; 
		wps.y_long = approact_wp.lon;
        
        wps.z_alt = 20.0000000; // 改动高度, 需要重新调节 最小距离的值
        
	    waypointpush.request.waypoints.push_back(wps);
    }

    // mission item - wp (Land)
    {
        wps.frame = MAV_FRAME_GLOBAL_RELATIVE_ALT;
        wps.command = MAV_CMD_NAV_LAND;
	
	    wps.is_current = 0;
	    wps.autocontinue = 1;
        
        wps.x_lat = Land_wp.lat;
		wps.y_long = Land_wp.lon;
        wps.z_alt = 0.00;  // 这里需要手动给定 值为0, 不然出现: Mission rejected: landing above last waypoint. 
	    waypointpush.request.waypoints.push_back(wps);
    }
    
    
    ros::Time last_request = ros::Time::now();

    // 4. 上传数据
    if(sendWps.call(waypointpush) &&
        // Returns success status and transfered count
        waypointpush.response.success){
        
        ROS_INFO("The node has pushed new waypoints!\t\t SUCCEED");
        ROS_INFO("the transfered count is %d", waypointpush.response.wp_transfered);
        
    }else{
        ROS_INFO("upload is failed!");
    }
    
    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    mavros_msgs::SetMode takeoff_set_mode;
    takeoff_set_mode.request.custom_mode = "AUTO.TAKEOFF";

    mavros_msgs::SetMode mission_set_mode;
    mission_set_mode.request.custom_mode = "AUTO.MISSION";

    // 上传成功之后需要进入 mission armed 模式
    while (ros::ok()){
        if( current_state.mode != "AUTO.RTL" && current_state.mode != "AUTO.TAKEOFF" && current_state.mode != "AUTO.MISSION" &&
            (ros::Time::now() - last_request > ros::Duration(5.0))){
            if( set_mode_client.call(mission_set_mode) &&
                mission_set_mode.response.mode_sent){
                ROS_INFO("mission enabled");
            }
            last_request = ros::Time::now();
        } else {
            if( !current_state.armed &&
                (ros::Time::now() - last_request > ros::Duration(5.0))){
                if( arming_client.call(arm_cmd) &&
                    arm_cmd.response.success){
                    ROS_INFO("Vehicle armed");
                }
                last_request = ros::Time::now();
            }
        }
        if(current_state.mode == "AUTO.MISSION" && current_state.armed)
        {
            break;
        }
        ros::spinOnce();
        rate.sleep();
    }   
    
    return 0;
}