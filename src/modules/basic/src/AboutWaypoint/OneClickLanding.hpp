#pragma once


#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>

#include <mavros_msgs/CommandBool.h>

#include <mavros_msgs/State.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/Waypoint.h>
#include <mavros_msgs/WaypointClear.h>
#include <mavros_msgs/WaypointReached.h>
#include <mavros_msgs/WaypointPush.h>
#include <mavros_msgs/WaypointList.h>
#include <mavros_msgs/CommandLong.h>
#include <mavros_msgs/HomePosition.h>
#include <cstdlib>

// 经纬度 转换为 距离
#include "../../../../lib/GPS2Distance/GPS2Distance.hpp"

// MAV_CMD
// /home/fengxuewei/C++_myself/catkin_ws/src/mavlink/common/mavlink.h
// #include <../include/mavlink/v2.0/common/mavlink.h>
#include "mavlink/v2.0/common/mavlink.h"
// #include <mavlink/v1.0/ardupilotmega/ardupilotmega.h>
// MAV_FRAME
// #include <mavlink/v1.0/common/common.h>
#include <iostream>


double getDistance(double lon1, double lat1, double lon2, double lat2);
point getDestPoint(point lonlat, double brng, int dist);
double getBearing(double lat_a, double lng_a, double lat_b, double lng_b);

using namespace std;
bool Y_N(){
    char ch;
    cout << "choose if continue (y/n): ";
    cin  >> ch;
    // 小写
    ch = tolower(ch);

    return (ch == 'y') ? true : false;
}


point home;
mavros_msgs::HomePosition home_position;
mavros_msgs::WaypointList waypoint_list;

void homePosition_cb(const mavros_msgs::HomePosition::ConstPtr& msg)
{
	home_position = *msg; 
    home.lat = home_position.geo.latitude;
    home.lon = home_position.geo.longitude;
}

void print_wp(const mavros_msgs::Waypoint& wp)
{
    ROS_INFO("waypoint: x_lat = %f y_long = %f z_alt = %f", wp.x_lat,wp.y_long,wp.z_alt);
    ROS_INFO("command = %d frame = %d autocontinue = %d is_current = %d",wp.command,wp.frame,wp.autocontinue,wp.is_current);
    ROS_INFO("param:%f %f %f %f", wp.param1,wp.param2,wp.param3,wp.param4);
}

void waypointlist_from_px4_sub(const mavros_msgs::WaypointList::ConstPtr &msg)
{
    waypoint_list = *msg;
}
mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}
