#pragma once

#include <iostream>
#include <ros/ros.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/AttitudeTarget.h>
#include <mavros_msgs/VFR_HUD.h>
#include <mavros_msgs/OverrideRCIn.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/ParamSet.h>
#include <geometry_msgs/PoseStamped.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/NavSatFix.h>

#include "fw_msgs/commands.h"
#include "fw_msgs/processer.h"

#include "fw_msgs/uavflag.h"

#include "../../../../lib/mathlib/math/mathlib.hpp"
#include "../../../../lib/logger/LogStream.hpp"
#include "../../../../lib/mathlib/vector/vector.hpp"


using std::cout;
using std::end;

#ifndef PITCH_CHANNEL
    #define PITCH_CHANNEL 		1
#endif

#ifndef ROLL_CHANNEL
    #define ROLL_CHANNEL 		2
#endif

#ifndef YAW_CHANNEL
    #define YAW_CHANNEL 		3
#endif

#ifndef THROTTLE_CHANNEL
    #define THROTTLE_CHANNEL 	4
#endif

class FixedwingAttitudeSubAndPub{
    private:
        // 日志保存: 接收的姿态数据值(四个) 和 发布下去的数据(offboard & RC)
        /*
            : currentWaypoint(_alloc)
            , nextWaypoint(_alloc)
            , Throttle(0)
            , ExistNext(0)  
        */
        logStream<float>   log_subscribe_roll_setpoint;
        logStream<float>   log_subscribe_yaw_setpoint;
        logStream<float>   log_subscribe_pitch_setpoint;
        logStream<float>   log_subscribe_throttle_setpoint;

        logStream<float>   log_publish_rc_roll_sp;
        logStream<float>   log_publish_rc_yaw_sp;
        logStream<float>   log_publish_rc_pitch_sp;
        logStream<float>   log_publish_rc_throttle_sp;

        logStream<float>   log_publish_offboard_roll_sp;
        logStream<float>   log_publish_offboard_yaw_sp;
        logStream<float>   log_publish_offboard_pitch_sp;
        logStream<float>   log_publish_offboard_throttle_sp;

        std::string uavName;

        float att_angle_Euler[3];

    public:
        FixedwingAttitudeSubAndPub(std::string);
        ~FixedwingAttitudeSubAndPub();
        
        bool isOffboardAttiControl;


        ros::NodeHandle nh;

        /* 1. the publishers and subscribers */
        /* subscribe */ 
        ros::Subscriber state_sub;                          // the vehicle state
        ros::Subscriber offboard_sub;                       // commands from the position controller
        ros::Subscriber uav_state_sub;                      // Data for HUD.
        ros::Subscriber uav_localPos_sub;                   // Local position from FCU.

        ros::Subscriber processer_sub;
        ros::Subscriber uav_imu_sub;
        
        /* publish */
        ros::Publisher offb_att_sp_pub;                     // publish the setpoint to firmware by offboard
        ros::Publisher rc_control;                          // the Joystick Control
        ros::Publisher local_pos_pub;

        /* sevice */
        ros::ServiceClient set_mode_client;                 // set modes of vehicle
        ros::ServiceClient set_parameter;
        
        /* 2. the Variables declaration */
        mavros_msgs::State current_state;
        fw_msgs::commands commands;                  // the commands for offboard or rc
        fw_msgs::processer processer;
        geometry_msgs::PoseStamped pose;
        mavros_msgs::AttitudeTarget attitude_setpoint;      // used to reserve the setpoints

        mavros_msgs::VFR_HUD current_UAV_state;
        geometry_msgs::PoseStamped current_localPose;

        sensor_msgs::Imu imu;
        mavros_msgs::SetMode set_mode;                      // set up the mode

        ros::Subscriber uavflag_sub;
        fw_msgs::uavflag uavflag_state;
        void uavflag_cb(const fw_msgs::uavflag::ConstPtr& msg);

        /* 3. the handle function */
        void state_cb(const mavros_msgs::State::ConstPtr& msg);
        void command_cb(const fw_msgs::commands::ConstPtr& msg);
        void newUAVState(const mavros_msgs::VFR_HUD::ConstPtr& msg);
        void new_localPose(const geometry_msgs::PoseStamped::ConstPtr& msg);

        void imu_cb(const sensor_msgs::Imu::ConstPtr &msg);
        void processer_cb(const fw_msgs::processer::ConstPtr& msg);

        void getEuler(float *_Euler_);

        /* 4. the sending logic */
        void turnAngle2Quaternion();
        void offPublishSetpoints();
        void pos_publish();

        /* 5. others */
        void showSetpoints();                               // show the information which will be sended
        bool CommandsIsNull();

        void logSubConfig();
        void logRCPubConfig();
        void logOFFBOARDPubConfig();

        void WriteLogFile_Subscribe();
        void WriteLogFile_RC_Publish(float *);
        void WriteLogFile_OFFBOARD_Publish(fw_msgs::commands);
};

