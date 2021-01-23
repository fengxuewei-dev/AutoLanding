#pragma once

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/WaypointClear.h>

#include <mavros_msgs/WaypointPush.h>
#include <mavros_msgs/WaypointPull.h>
#include <mavros_msgs/State.h>

#include <mavros_msgs/Waypoint.h>
#include <mavros_msgs/WaypointReached.h>
#include <mavros_msgs/WaypointList.h>
#include <mavros_msgs/HomePosition.h>
#include <cstdlib>

#include <iostream>
using namespace std;
bool Y_N(){
    char ch;
    cout << "choose if continue (y/n): ";
    cin  >> ch;
    // 小写
    ch = tolower(ch);

    return (ch == 'y') ? true : false;
}

mavros_msgs::WaypointList waypoint_list;

void waypointlist_from_px4_sub(const mavros_msgs::WaypointList::ConstPtr &msg)
{
    waypoint_list = *msg;
}

mavros_msgs::HomePosition home_position;
void homePosition_cb(const mavros_msgs::HomePosition::ConstPtr& msg)
{
	home_position = *msg;
    ROS_INFO("home geo: (altitude = %f,latitude = %f, longitude = %f)", home_position.geo.altitude, home_position.geo.latitude, home_position.geo.longitude);
    ROS_INFO("home position: (%f, %f, %f) \n", home_position.position.x, home_position.position.y, home_position.position.z);
}
