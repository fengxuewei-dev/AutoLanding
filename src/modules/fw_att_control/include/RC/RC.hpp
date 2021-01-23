#pragma once

// 为四个管道赋值
#include <iostream>
#include <mavros_msgs/OverrideRCIn.h>
#include <mavros_msgs/ParamSet.h>
#include "../PID/pidControl.hpp"

class rc{
    private:
    public:
        
        ros::NodeHandle nh;

        ros::ServiceClient set_parameter;
        mavros_msgs::OverrideRCIn newRCIn;
        mavros_msgs::ParamSet settingParameter;
        
        void Assignment(float *);
        void setParameters();
        rc();
};
