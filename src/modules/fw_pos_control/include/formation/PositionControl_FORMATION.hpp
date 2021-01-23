#pragma once


#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Point.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/WaypointList.h>
#include "fw_msgs/commands.h"
#include "fw_msgs/formations.h"
#include <mavros_msgs/ParamValue.h>
#include <mavros_msgs/HomePosition.h>

#include <mavros_msgs/VFR_HUD.h>
#include "../../../../lib/GPS2Distance/GPS2Distance.hpp"
#include "../../../../lib/ReadIniFiles/RrConfig.hpp"
#include "formationControl/formationControl.hpp"

#include <signal.h>

#ifndef PI
#define PI 3.14159265359
#endif

#define RATE_EXE 50

using namespace std;

typedef struct Distance_X_Y
{
    double dist_x;
    double dist_y;
}distType;
typedef struct Pt {
    double lat;
    double lon;
}homePoint;

double getDistance(double lon1, double lat1, double lon2, double lat2);

class PositionControl_FORMATION{
	private:
		Point leaderPosition{0.0, 0.0};
		Point followerPosition{0.0, 0.0};
		Point gap{0.0, 0.0};

		formationControl formationcontrol;
		rr::RrConfig config;
		ros::ServiceClient set_parameter;

		long long msec_;									// The time error
		distType dist_offset;								// the offest error

       
		/* come from the follower */
		mavros_msgs::HomePosition current_follower_home;
		mavros_msgs::VFR_HUD current_follower_state;
		geometry_msgs::PoseStamped current_followerPose; 		// the follower vehicle's position

		/* come frome the leader */
		fw_msgs::commands current_leaderCommand;
		mavros_msgs::VFR_HUD current_Leader_state;
		homePoint current_leaderHome;
		geometry_msgs::PoseStamped current_leaderPose;

		mavros_msgs::Waypoint Final_waypoint;

		char current_leaderFormation;

		double leaderHeading;
		double followerHeading;
		Point followerFinalPoint;

	public:
		PositionControl_FORMATION();
		~PositionControl_FORMATION();

		ros::NodeHandle nh;
		/* subscribe */
		ros::Subscriber uav_state_sub;
		ros::Subscriber home_pos_sub ;
		ros::Subscriber follower_localPos_sub;

		void new_followerHome(const mavros_msgs::HomePosition::ConstPtr& msg);
		void newUAVState(const mavros_msgs::VFR_HUD::ConstPtr& msg);
		void new_followerPose(const geometry_msgs::PoseStamped::ConstPtr& msg);

		distType calOffset_frome_Home_position();
		void setDistoffset();
		
		void run(mavros_msgs::Waypoint, mavros_msgs::VFR_HUD, geometry_msgs::PoseStamped,double, double,double);
		
		// get the gaps
		void getGap();
		void cal_headings();
		void cal_timeError();
		long getCurrentTime();

		Point calDelay(double Heading_);

		float getYaw();
		float getThrottle();
		float getPitch();
};
