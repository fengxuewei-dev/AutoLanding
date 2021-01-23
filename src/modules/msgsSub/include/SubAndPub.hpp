#pragma once

#include <iostream>
#include <iomanip>

#include <ros/ros.h>

#include <mavros_msgs/State.h>
#include <mavros_msgs/AttitudeTarget.h>
#include <mavros_msgs/VFR_HUD.h>
#include <mavros_msgs/OverrideRCIn.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/ParamSet.h>
#include <mavros_msgs/WaypointList.h>
#include <mavros_msgs/WaypointReached.h>
#include <mavros_msgs/HomePosition.h>

#include <sensor_msgs/Imu.h>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/TimeReference.h>

#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/TwistWithCovarianceStamped.h>
#include <geometry_msgs/AccelWithCovarianceStamped.h>

#include "msgsSub_output.hpp"
#include "../../../lib/logger/LogStream.hpp"

using std::cout;
using std::endl;

class SubAndPub{
    private:
        std::string uavName;

    public:
        SubAndPub(std::string);
        ~SubAndPub();

        void setUavName(std::string);
        std::string getUavName();

        void publishData();

        /* 1. the publishers and subscribers */
        ros::NodeHandle nh;

        ros::Subscriber home_sub;                           // the home position 
        ros::Subscriber state_sub;                          // the vehicle state
        ros::Subscriber uav_imu_sub;                        // the imu information 
        ros::Subscriber GPStime_sub;
        ros::Subscriber uav_state_sub;                      // Data for HUD.
        ros::Subscriber uav_localPos_sub;                   // Local position from FCU.
        ros::Subscriber uav_localVel_sub;                   // ned_vel_x, ned_vel_y, ned_vel_z
        ros::Subscriber uav_globelPos_sub;                  // global position
        ros::Subscriber uav_windEstimation_sub;             // the wind estimation
        ros::Subscriber uav_localAccel_sub;                 // the local accel
        ros::Subscriber uav_waypoints_sub;                  // the waypoints list
        ros::Subscriber velocity_global_fused_sub; 
        ros::Subscriber uav_waypoints_reached_sub; 

        /* publish */
        ros::Publisher home_pub;                           // the home position 
        ros::Publisher state_pub;                           // publish the state from the vehicle
        ros::Publisher GPStime_pub;
        ros::Publisher uav_imu_pub;                        // the imu information 
        ros::Publisher uav_state_pub;                       // Data for HUD.
        ros::Publisher uav_localVel_pub;                   // ned_vel_x, ned_vel_y, ned_vel_z
        ros::Publisher uav_localPos_pub;                    // Local position from FCU.
        ros::Publisher uav_waypoints_pub;                  // the waypoints list
        ros::Publisher uav_globelPos_pub;                  // global position
        ros::Publisher uav_localAccel_pub;                 // the local accel
        ros::Publisher uav_windEstimation_pub;             // the wind estimation
        ros::Publisher velocity_global_fused_pub;
        ros::Publisher uav_waypoints_reached_pub; 
        
        /* 2. the Variables declaration */
        mavros_msgs::State current_state;
        mavros_msgs::HomePosition current_home;
        mavros_msgs::VFR_HUD current_UAV_state;
        mavros_msgs::WaypointList waypoint_List;      
        mavros_msgs::WaypointReached waypoint_reached;

        geometry_msgs::PoseStamped pose;
        geometry_msgs::PoseStamped current_localPose;                       
        geometry_msgs::TwistStamped velocity_ned_fused_from_px4;
        geometry_msgs::AccelWithCovarianceStamped acc_ned_from_px4;                   
        geometry_msgs::TwistWithCovarianceStamped wind_estimate_from_px4;
        geometry_msgs::TwistStamped velocity_global_fused_from_px4;

        sensor_msgs::Imu imu;
        sensor_msgs::TimeReference gpsTime;
        sensor_msgs::NavSatFix global_position_form_px4;

        /* 3. the handle function */
        void imu_cb(const sensor_msgs::Imu::ConstPtr &msg);
        void state_cb(const mavros_msgs::State::ConstPtr& msg);
        void newUAVState(const mavros_msgs::VFR_HUD::ConstPtr& msg);
        void new_GPSTime(const sensor_msgs::TimeReference::ConstPtr& msg);
        void new_localPose(const geometry_msgs::PoseStamped::ConstPtr& msg);
        void homePosition_cb(const mavros_msgs::HomePosition::ConstPtr& msg);
        void acc_ned_from_px4_cb(const geometry_msgs::AccelWithCovarianceStamped::ConstPtr &msg);
        void waypointlist_from_px4_sub(const mavros_msgs::WaypointList::ConstPtr &msg);
        void waypointReached_from_px4_sub(const mavros_msgs::WaypointReached::ConstPtr &msg);
        void wind_estimate_from_px4_cb(const geometry_msgs::TwistWithCovarianceStamped::ConstPtr &msg);
        void global_position_form_px4_cb(const sensor_msgs::NavSatFix::ConstPtr &msg);
        void velocity_ned_fused_from_px4_cb(const geometry_msgs::TwistStamped::ConstPtr &msg);
        void velocity_global_fused_from_px4_cb(const geometry_msgs::TwistStamped::ConstPtr &msg);

        void print_wp(const mavros_msgs::Waypoint& wp);
        void printInfo();
};
