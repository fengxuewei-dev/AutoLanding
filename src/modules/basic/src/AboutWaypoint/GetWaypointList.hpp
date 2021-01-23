#pragma once

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/WaypointClear.h>

#include <mavros_msgs/WaypointPush.h>
#include <mavros_msgs/State.h>

#include <mavros_msgs/Waypoint.h>
#include <mavros_msgs/WaypointList.h>
#include <mavros_msgs/WaypointReached.h>
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

int jj = 0;

mavros_msgs::WaypointList waypoint_list;

void print_wp(const mavros_msgs::Waypoint& wp)
{
    // 设置输出精度
    cout.precision(10);
    cout << "gps: frame command param1 param2 param3 param4 x_lat y_long z_alt" << endl;
    cout << wp.frame << " " << wp.command << " " << wp.param1 << " " << wp.param2 << " " << wp.param3 << " " << wp.param4 << " " << wp.x_lat << " " << wp.y_long << " " <<wp.z_alt << endl;
   
    // ROS_INFO("x_lat = %f y_long = %f z_alt = %f", wp.x_lat,wp.y_long,wp.z_alt);
    // ROS_INFO("command = %d frame = %d autocontinue = %d is_current = %d",wp.command,wp.frame,wp.autocontinue,wp.is_current);
    // ROS_INFO("param:%f %f %f %f", wp.param1,wp.param2,wp.param3,wp.param4);
}

void waypointlist_from_px4_sub(const mavros_msgs::WaypointList::ConstPtr &msg)
{
    waypoint_list = *msg;
    
    cout << "current_sq: " << waypoint_list.current_seq << endl;
    
    // 打印 航点的位置
    // waypoint_list.waypoints.size(): 航点的个数
    for (size_t i = 0; i < waypoint_list.waypoints.size(); i++)
    {
        ROS_INFO("WP: %d",int(i));
        print_wp(waypoint_list.waypoints[i]);
    }

    // ROS_INFO("\t Time: %d", jj++);
}
