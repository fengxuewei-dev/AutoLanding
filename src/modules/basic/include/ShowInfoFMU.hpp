/* this software is developed by the CGNC_LAB BIT, all rights reserved.*/
/* 作者：CGNC_LAB,BIT
 * 时间：2019.11.09
 */

// ros程序必备头文件
#pragma once

#include <ros/ros.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include "fw_sub_pub.hpp"
#include "../../../lib/mathlib/vector/vector.hpp"
#include "../../../lib/mathlib/mathlib.h"

using namespace std;

class FIXED_WING_INFORMATION_DISPLAY
{

private:
	ros::Time begin_time;

	FW_SUB_PUB fixed_wing_sub_pub;

	float current_time{0};

	ros::NodeHandle nh;

	ros::Subscriber fw_battrey_state;

	ros::Subscriber fw_wind_estimate;

	ros::Subscriber fw_acc_ned;

	ros::Subscriber fw_velocity_ned_fused;

	ros::Subscriber fw_local_position;

	ros::Subscriber fw_velocity_global_fused;

	ros::Subscriber fw_umt_position;

	ros::Subscriber fw_global_rel_alt;

	ros::Subscriber fw_global_position;

	ros::Subscriber fw_imu;

	ros::Subscriber fw_states;

	ros::Subscriber fw_waypoints;

	ros::Subscriber fw_waypointsreach;

	ros::Subscriber fw_altitude;

	ros::Subscriber fw_air_ground_speed;

public:

	bool run(int argc, char **argv);
	void ros_sub_and_pub(string, FW_SUB_PUB*);
};
