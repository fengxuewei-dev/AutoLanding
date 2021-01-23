// ros程序必备头文件
#pragma once

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include "std_msgs/String.h"


class enableAltctl{
    public:
        enableAltctl();
        ~enableAltctl();

        ros::NodeHandle nh;

        
        void exe_multi_ALTCTL();
        void exe_single_ALTCTL();

        void state_cb(const mavros_msgs::State::ConstPtr& msg);
};
enableAltctl::enableAltctl(){
}

enableAltctl::~enableAltctl(){

}




void enableAltctl::exe_multi_ALTCTL(){

}
void enableAltctl::exe_single_ALTCTL(){

    ros::NodeHandle nh;

 


   
}




