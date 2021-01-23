#include "GetWaypointList.hpp"

// 航点 列表对象
int main(int argc, char **argv)
{
    ros::init(argc, argv, "GetWaypointList");

    ros::NodeHandle nh;

    ROS_INFO("The GetWaypointList node is opened!");
    ROS_INFO("It will get the waypointList from the px4 that is flying: ");


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


    // 【订阅】无人机当前航点
    ros::Subscriber waypoints_list_sub = nh.subscribe<mavros_msgs::WaypointList>(uavName + "/mavros/mission/waypoints", 10, &waypointlist_from_px4_sub);

    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(20.0);

    // bool flag = Y_N();

    // if(flag == false)
    // {
    //     return 0;
    // }

    ros::Time last_request = ros::Time::now();

    while(ros::ok()){
        
        // 进入调度函数
        ros::spinOnce();

        rate.sleep();

        if ( waypoint_list.waypoints.size() == 0 )
        {
            continue;
        }

        // 判断是否到达最后一个航点
        if ( waypoint_list.waypoints[waypoint_list.waypoints.size() - 1].is_current )
        {
            break;
        }
    }

    return 0;
}