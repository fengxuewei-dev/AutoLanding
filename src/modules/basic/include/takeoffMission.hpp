#pragma once

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/WaypointList.h>
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

mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}

mavros_msgs::WaypointList waypoint_list;

void waypointlist_from_px4_sub(const mavros_msgs::WaypointList::ConstPtr &msg)
{
    waypoint_list = *msg;
}
