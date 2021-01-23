/**
 * @file takeoff_mission_uav0.cpp
 * @brief Offboard control example node, written with MAVROS version 0.19.x, PX4 Pro Flight
 * Stack and tested in Gazebo SITL
 */

#include "takeoff_mission.hpp"

int main(int argc, char **argv)
{
    std::string uavName;
    std::string pre_node = "takeoff_mission";

    if(argc == 1){ // 没有命令行参数
        ROS_INFO("The vehicle that you will control is single!");
        uavName = "";
    } else if(argc == 2){ // 存在命令行参数, 则 指定操作的飞机
        uavName = argv[1];
        if('/' != uavName[0]){// 如果第一个字符不是 '/'
            uavName = "/" + uavName;
        }
        pre_node = pre_node.append(uavName, 4, 1);
        // ROS_ERROR("You need to input the vehicle the ");
        ROS_INFO(("selected uav:"));	
		ROS_INFO("%s",(uavName.c_str()));
    } else {
        ROS_ERROR("Incorrect number of parameters!");
        return false;
    }
	
	std::cout << "the node's name =  " << pre_node << std::endl;
	ros::init(argc, argv, pre_node);
    ros::NodeHandle nh;

    ROS_INFO("The %s node is opened!", pre_node.c_str());

    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
            (uavName + "/mavros/state", 10, state_cb);
    ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>
            (uavName + "/mavros/setpoint_position/local", 10);
    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>
            (uavName + "/mavros/cmd/arming");
            
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
            (uavName + "/mavros/set_mode");
    
    // 获得 航点组
    ros::Subscriber waypoints_list_sub = nh.subscribe<mavros_msgs::WaypointList>
            (uavName + "/mavros/mission/waypoints", 10, &waypointlist_from_px4_sub);

    // ros::ServiceClient client = nh.serviceClient<mavros_msgs::SetMode>("set_mode_myself");

    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(20.0);

    // bool flag = Y_N();

    // if(flag == false)
    // {
    //     return 0;
    // }
    
    // wait for FCU connection 
    while(ros::ok() && !current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }


    geometry_msgs::PoseStamped pose;
    pose.pose.position.x = 0;
    pose.pose.position.y = 0;
    pose.pose.position.z = 2;

    //send a few setpoints before starting
    // for(int i = 100; ros::ok() && i > 0; --i){
    //     local_pos_pub.publish(pose);
    //     ros::spinOnce();
    //     rate.sleep();
    // }

    mavros_msgs::SetMode takeoff_set_mode;
    takeoff_set_mode.request.custom_mode = "AUTO.TAKEOFF";

    mavros_msgs::SetMode mission_set_mode;
    mission_set_mode.request.custom_mode = "AUTO.MISSION";

    mavros_msgs::SetMode loiter_set_mode;
    loiter_set_mode.request.custom_mode = "AUTO.LOITER";


    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();

    while(ros::ok()){
        
        // 不是 飞行状态 则起飞 且使能
       if( current_state.mode != "AUTO.TAKEOFF" && current_state.mode != "AUTO.MISSION" &&
            (ros::Time::now() - last_request > ros::Duration(5.0))){
            if( set_mode_client.call(takeoff_set_mode) &&
                takeoff_set_mode.response.mode_sent){
                ROS_INFO("Takeoff enabled");
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
        
        local_pos_pub.publish(pose);

        // 若是 单机 或者是 第一架飞机： UAV0 进去mission模式
        // if(uavName == "" || uavName[4] == '0')
        // {
        //         if( current_state.mode == "AUTO.TAKEOFF" && current_state.armed && 
        //         (ros::Time::now() - last_request > ros::Duration(5.0))){
        //         if( set_mode_client.call(mission_set_mode) &&
        //             mission_set_mode.response.mode_sent){
        //                 ROS_INFO("MISSION enabled");
        //                 sleep(8);
        //                 break;
        //         }
        //         last_request = ros::Time::now();
        //     }
        // }
        // else
        // {
            if( current_state.mode == "AUTO.TAKEOFF" && current_state.armed && 
                (ros::Time::now() - last_request > ros::Duration(5.0))){
                    sleep(8);
                    break;
            }

        // }
        
        
        
        

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
