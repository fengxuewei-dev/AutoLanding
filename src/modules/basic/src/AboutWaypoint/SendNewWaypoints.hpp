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
#include <mavros_msgs/WaypointPush.h>
#include <mavros_msgs/WaypointList.h>
#include <mavros_msgs/HomePosition.h>

#include <cstdlib>


#include <iostream>
using namespace std;

// 传入的航点的属性个数
#define WAYPOINT_STATE_NUMBER 9   
bool Y_N(){
    char ch;
    cout << "choose if continue (y/n): ";
    cin  >> ch;
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
    
    // ROS_INFO("home geo: (altitude = %f,latitude = %f, longitude = %f)", home_position.geo.altitude, home_position.geo.latitude, home_position.geo.longitude);
    // ROS_INFO("home position: (%f, %f, %f) \n", home_position.position.x, home_position.position.y, home_position.position.z);

}
void print_wp(const mavros_msgs::Waypoint& wp)
{
    ROS_INFO("waypoint: x_lat = %f y_long = %f z_alt = %f", wp.x_lat,wp.y_long,wp.z_alt);
    ROS_INFO("command = %d frame = %d autocontinue = %d is_current = %d",wp.command,wp.frame,wp.autocontinue,wp.is_current);
    ROS_INFO("param:%f %f %f %f", wp.param1,wp.param2,wp.param3,wp.param4);
}
