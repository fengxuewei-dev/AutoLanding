#pragma once

// ros程序必备头文件
#include <ros/ros.h>
//mavros相关头文件
#include <mavros_msgs/State.h>
#include <mavros_msgs/SetMode.h>
#include <nav_msgs/Odometry.h> 
#include <mavros_msgs/WaypointList.h>
#include <mavros_msgs/WaypointReached.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/WaypointSetCurrent.h>
#include <mavros_msgs/WaypointPull.h>
#include <mavros_msgs/WaypointPush.h>
#include <mavros_msgs/WaypointClear.h>
#include <mavros_msgs/Altitude.h>
#include <mavros_msgs/VFR_HUD.h>

#include <sensor_msgs/Imu.h>
#include <sensor_msgs/NavSatFix.h> //GPS Fix.
#include <std_msgs/Float64.h>
#include <sensor_msgs/BatteryState.h>

#include <geometry_msgs/PoseWithCovarianceStamped.h> //UTM coords
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h> //Velocity fused by FCU
#include <geometry_msgs/AccelWithCovarianceStamped.h>
#include <geometry_msgs/TwistWithCovarianceStamped.h>

//setpoint_raw:在这个底下，全都有，SET_ATTITUDE_TARGET++SET_POSITION_TARGET_LOCAL_NED
#include <mavros_msgs/AttitudeTarget.h>
#include <mavros_msgs/PositionTarget.h>
#include <mavros_msgs/GlobalPositionTarget.h>

#include <mavros_msgs/Formation_fixed_wing.h> //自定义的传输消息
#include "../../../lib/mathlib/fw_mathlib/fixed_wing_mathlib.hpp"
#include "../../../lib/logger/LogStream.hpp"

#include <iostream>
using namespace std;
#define the_space_between_lines 1  //为了打印中间空格
#define the_space_between_blocks 3 //为了打印中间空格

class FW_SUB_PUB
{
private:
public:

    _FIXED_WING_MATHLIB mathlib; //数学类

    //订阅的数据暂时容器
    mavros_msgs::State current_state; //无人机当前状态[包含上锁状态 模式] (从飞控中读取)

    sensor_msgs::Imu imu;

    sensor_msgs::NavSatFix global_position_form_px4;

    std_msgs::Float64 global_rel_alt_from_px4;

    nav_msgs::Odometry umt_position_from_px4;

    geometry_msgs::TwistStamped velocity_global_fused_from_px4;

    geometry_msgs::TwistStamped velocity_ned_fused_from_px4;

    geometry_msgs::PoseStamped local_position_from_px4;

    geometry_msgs::AccelWithCovarianceStamped acc_ned_from_px4;

    geometry_msgs::TwistWithCovarianceStamped wind_estimate_from_px4;

    sensor_msgs::BatteryState battrey_state_from_px4;

    mavros_msgs::WaypointList waypoint_list;

    mavros_msgs::WaypointReached waypoint_reached;

    mavros_msgs::Altitude altitude_from_px4;

    mavros_msgs::VFR_HUD air_ground_speed_from_px4;

    //服务项暂存容器
    mavros_msgs::SetMode mode_cmd;

    mavros_msgs::CommandBool arming_service;

    mavros_msgs::WaypointSetCurrent waypoint_set_current_service;

    mavros_msgs::WaypointPull waypoint_pull_service;

    mavros_msgs::WaypointPush waypoint_push_service;

    mavros_msgs::WaypointClear waypoint_clear_service;

    //发布的数据暂时容器
    mavros_msgs::PositionTarget local_pos_sp;

    mavros_msgs::GlobalPositionTarget global_pos_sp;

    mavros_msgs::AttitudeTarget att_sp;

    mavros_msgs::Formation_fixed_wing fixed_wing_states_tran; //这个是自定义的飞机状态消息

    float att_sp_Euler[3];
    float thrust_sp;

    float PIX_Euler_target[3]; //无人机 期望欧拉角(从飞控中读取)
    float att_angle_Euler[3];  //无人机当前欧拉角(从飞控中读取)

    float get_ros_time(ros::Time begin);

    void state_cb(const mavros_msgs::State::ConstPtr &msg);

    void imu_cb(const sensor_msgs::Imu::ConstPtr &msg);

    void global_position_form_px4_cb(const sensor_msgs::NavSatFix::ConstPtr &msg);
    void fixed_wing_global_rel_alt_from_px4_cb(const std_msgs::Float64::ConstPtr &msg);
    void umt_position_from_px4_cb(const nav_msgs::Odometry::ConstPtr &msg);

    void velocity_global_fused_from_px4_cb(const geometry_msgs::TwistStamped::ConstPtr &msg);
    void velocity_ned_fused_from_px4_cb(const geometry_msgs::TwistStamped::ConstPtr &msg);
    void local_position_from_px4_cb(const geometry_msgs::PoseStamped::ConstPtr &msg);

    void acc_ned_from_px4_cb(const geometry_msgs::AccelWithCovarianceStamped::ConstPtr &msg);
    void wind_estimate_from_px4_cb(const geometry_msgs::TwistWithCovarianceStamped::ConstPtr &msg);

    void battrey_state_from_px4_cb(const sensor_msgs::BatteryState::ConstPtr &msg);

    void waypoints_reached_from_px4_cb(const mavros_msgs::WaypointReached::ConstPtr &msg);
    void print_wp(const mavros_msgs::Waypoint& wp);

    bool lock_wps{false};
    void waypointlist_from_px4_cb(const mavros_msgs::WaypointList::ConstPtr &msg);

    void altitude_from_px4_cb(const mavros_msgs::Altitude::ConstPtr &msg);
    void air_ground_speed_from_px4_cb(const mavros_msgs::VFR_HUD::ConstPtr &msg);
    void fixed_wing_states_tran_cb(const mavros_msgs::Formation_fixed_wing::ConstPtr &msg);
};