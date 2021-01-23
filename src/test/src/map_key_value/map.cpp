/**
 * @file protect.cpp
 */

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/OverrideRCIn.h>
#include "fw_msgs/EXITflag.h"

mavros_msgs::State current_state;
mavros_msgs::State before_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}

mavros_msgs::OverrideRCIn newRCIn;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "offb_node");
    ros::NodeHandle nh;
    std::string uavName = "";
    if(argc == 1){

    }
    else if(argc == 2){
        uavName = argv[1];
        uavName = uavName + "/";
    }else{
        ROS_ERROR("need arguments");
    }
    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
            (uavName + "mavros/state", 10, state_cb);
    ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>
            (uavName + "mavros/setpoint_position/local", 10);
    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>
            (uavName + "mavros/cmd/arming");
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
            (uavName + "mavros/set_mode");
    ros::Publisher rc_control = nh.advertise<mavros_msgs::OverrideRCIn>  
            (uavName + "mavros/rc/override", 1);
    ros::Publisher uav_exitFlag_pub = nh.advertise<fw_msgs::EXITflag>
            (uavName + "communication/exitFlag/exitflag", 1);
   
    ros::Rate rate(100);

    // wait for FCU connection
    while(ros::ok() && !current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }

    fw_msgs::EXITflag exitflag;

    int before = 0;;

    while(ros::ok() && before != 1){
        std::cout << "current_state.mode: " << current_state.mode << std::endl;

        if(current_state.mode == "ALTCTL" && current_state.armed){ // 已经使能
            ROS_ERROR("mode is setting successful!");
            before = 1;
            before_state = current_state;
            break;  // 退出当前循环
        }
        
        ros::spinOnce();
        rate.sleep();
    }
    while(ros::ok() && before == 1){
        ROS_INFO("the mode has changed!");
        std::cout << "before mode " << before_state.mode << std::endl;
        std::cout << "curren mode " << current_state.mode << std::endl;
        if( before_state.mode.compare(current_state.mode) ){ // 模式已经变化
            ROS_ERROR("mode has been changed, should exit attitude controller");
            break;  // 退出当前循环
        }
        ros::spinOnce();
        rate.sleep();
    }
    while(ros::ok()){
        exitflag.EXIT_FLAG = 1;
        uav_exitFlag_pub.publish(exitflag);
        ROS_INFO("sending the exit flag, and flag = 1");
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}