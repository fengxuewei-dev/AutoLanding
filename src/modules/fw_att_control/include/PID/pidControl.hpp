#pragma once

#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/VFR_HUD.h>
#include "fw_msgs/commands.h"
#include "../../../../lib/Macro.hpp"

#define PITCH_CHANNEL 		1
#define ROLL_CHANNEL 		2
#define YAW_CHANNEL 		3
#define THROTTLE_CHANNEL 	4

#define CONSTANTS_ONE_G 9.80665

// #define RC_MAX 1700
// #define RC_MIN 1200

#define RC_MAX 		2000
#define RC_MIN 		1000


#define KP_ALT 		4
#define KP_YAW 		0.1
#define KP_ROLL 	2
#define KP_PITCH 	4


#ifndef PI
#define PI 			3.14159265359
#endif

class pidControl{
	private:
	public:
		geometry_msgs::PoseStamped current_localPose;

		mavros_msgs::VFR_HUD current_UAV_state;

		fw_msgs::commands current_commands;

		// error
		float altitudeError;
		float yawErrorDegree;
		float rollErrorDegree;
		float throttleErrorDegree;

		float map(float x, float in_min, float in_max, float out_min, float out_max);
		void Calculate(float *, float *);
		void cal_Error(int z, double command_alt, int heading, float yaw);
		void cal_Error();
};
