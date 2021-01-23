#pragma once

 // ros程序必备头文件
#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h> //GPS Fix.
#include <sensor_msgs/Imu.h>

#include <geometry_msgs/TwistStamped.h> //Velocity fused by FCU
#include <geometry_msgs/TwistWithCovarianceStamped.h>
#include <geometry_msgs/AccelWithCovarianceStamped.h>

#include <mavros_msgs/VFR_HUD.h>
#include <mavros_msgs/AttitudeTarget.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/Waypoint.h>
#include <mavros_msgs/WaypointList.h>
#include <mavros_msgs/WaypointReached.h>
#include <mavros_msgs/WaypointPush.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/CommandBool.h>

#include "fw_msgs/commands.h"
#include "../../../../lib/GPS2Distance/GPS2Distance.hpp"
#include "positionControl/L1_TECS.hpp"



class PositionControl_L1_TECS{
    private:
        L1_TECS l1_tecs;                                 // l1 && TECS
        mavros_msgs::Waypoint wp;
        float roll;
        float pitch;
        float yaw;
    public:
        PositionControl_L1_TECS();
        int run(
            mavros_msgs::Waypoint,
            sensor_msgs::NavSatFix global_position,
            geometry_msgs::TwistStamped velocity_ned,
            sensor_msgs::Imu imu_,
            geometry_msgs::TwistWithCovarianceStamped wind_estimate,
            mavros_msgs::VFR_HUD air_ground_speed,
            float airspeed
        );
        float getRoll();
        float getPitch();
        float getYaw();
        float getThrottle();
};
