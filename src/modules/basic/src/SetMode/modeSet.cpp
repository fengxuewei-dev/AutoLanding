/**
 * @file modeSet.cpp
 */
#include "modeSet.hpp"

int main(int argc, char **argv)
{
    int ch;
    bool flag = false;

    ros::init(argc, argv, "mode_setting");
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

    ROS_INFO("mode_setting node is opened , please wait .... ");

    ros::NodeHandle nh;

    // ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 1000);
    
    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
            (uavName + "/mavros/state", 10, state_cb);
    ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>
            (uavName + "/mavros/setpoint_position/local", 10);
    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>
            (uavName + "/mavros/cmd/arming");
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
            (uavName + "/mavros/set_mode");

    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(20.0);

    geometry_msgs::PoseStamped pose;
    pose.pose.position.x = 0;
    pose.pose.position.y = 0;
    pose.pose.position.z = 2;

    // wait for FCU connection
    // 等待 和 px4 的节点连接上
    while(ros::ok() && !current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }

    mavros_msgs::SetMode set_mode_name;
   
    while(!flag){

        menu_choose(ch);
        switch(ch){
            case 0: 
                return 0;
            case MANUAL:
                set_mode_name.request.custom_mode = "MANUAL";
                flag = 1;
                break;
            case ACRO:
                set_mode_name.request.custom_mode = "ACRO";
                flag = 1;
                break;
            case ALTCTL:
                set_mode_name.request.custom_mode = "ALTCTL";
                flag = 1;
                break;
            case POSCTL:
                set_mode_name.request.custom_mode = "POSCTL";
                flag = 1;
                break; 
            case OFFBOARD:
                set_mode_name.request.custom_mode = "OFFBOARD";
                //send a few setpoints before starting
                for(int i = 100; ros::ok() && i > 0; --i){
                    local_pos_pub.publish(pose);
                    ros::spinOnce();
                    rate.sleep();
                }
                flag = 1;
                break; 
            case STABILIZED:
                set_mode_name.request.custom_mode = "STABILIZED";
                flag = 1;
                break; 
            case RATTITUDE:
                set_mode_name.request.custom_mode = "RATTITUDE";
                flag = 1;
                break; 
            case AUTO_MISSION:
                set_mode_name.request.custom_mode = "AUTO.MISSION";
                flag = 1;
                break; 
            case AUTO_LOITER:
                set_mode_name.request.custom_mode = "AUTO.LOITER";
                flag = 1;
                break; 
            case AUTO_RTL:
                set_mode_name.request.custom_mode = "AUTO.RTL";
                flag = 1;
                break; 
            case AUTO_LAND:
                set_mode_name.request.custom_mode = "AUTO.LAND";
                flag = 1;
                break;        
            case AUTO_RTGS:
                set_mode_name.request.custom_mode = "AUTO.RTGS";
                flag = 1;
                break;        
            case AUTO_READY:
                set_mode_name.request.custom_mode = "AUTO.READY";
                flag = 1;
                break;   
            case AUTO_TAKEOFF:
                set_mode_name.request.custom_mode = "AUTO.TAKEOFF";
                flag = 1;
                break;                    
            default:
                cout << "The number is error, please close the node to rosrun it again!" << endl;
        }
    }

    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();
    
    while(ros::ok()){

        if( current_state.mode.compare( set_mode_name.request.custom_mode ) &&
            (ros::Time::now() - last_request > ros::Duration(5.0))){
            if( set_mode_client.call(set_mode_name) &&
                set_mode_name.response.mode_sent){
                
                ROS_INFO("\n\t %s enabled", set_mode_name.request.custom_mode.c_str());
               
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
        if(set_mode_name.request.custom_mode == "OFFBOARD")
            local_pos_pub.publish(pose);
            
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}
