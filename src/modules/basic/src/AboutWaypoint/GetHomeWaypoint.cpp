#include "GetHomeWaypoint.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "GetHomePosition");
    ros::NodeHandle nh;

    ROS_INFO("The GetHomePosition node is opened!");
    ROS_INFO("It will get the home position from the px4 and show it!");

    std::string uavName;
    if(argc == 1){ // 没有命令行参数
        ROS_INFO("The vehicle that you will control is single!");
        uavName = "";
    } else if(argc == 2){ // 存在命令行参数, 则 指定操作的飞机
        uavName = argv[1];
        if('/' != uavName[0]){// 如果第一个字符不是 '/'
            uavName = "/" + uavName;
        }
        // ROS_ERROR("You need to input the vehicle the ");
        ROS_INFO(("selected uav:"));	
		ROS_INFO("%s",(uavName.c_str()));
    } else {
        ROS_ERROR("Incorrect number of parameters!");
        return 0;
    }

    // 获得 home 点的位置
    ros::Subscriber home_sub = nh.subscribe<mavros_msgs::HomePosition> 
        (uavName + "/mavros/home_position/home", 10, homePosition_cb);

    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(20.0);

    // bool flag = Y_N();

    // if(flag == false)
    // {
    //     return 0;
    // }

    // 调用后不会再返回，也就是你的主程序到这儿就不往下执行了
    ros::spin();
}