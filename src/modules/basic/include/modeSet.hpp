// ros程序必备头文件
#pragma once

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include "std_msgs/String.h"

#include <iostream>
using namespace std;

typedef enum Mode_Set_Cmd
{
    MANUAL = 1,
    ACRO = 2,
    ALTCTL = 3,
    POSCTL = 4,
    OFFBOARD = 5,
    STABILIZED,
    RATTITUDE,
    AUTO_MISSION,
    AUTO_LOITER ,
    AUTO_RTL ,
    AUTO_LAND ,
    AUTO_RTGS ,
    AUTO_READY,
    AUTO_TAKEOFF

}Mode_Set_Cmd;