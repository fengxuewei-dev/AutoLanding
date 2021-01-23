#include "mavros_msgs/Mavlink.h"

#include "../TestWaypointlistPub.hpp"

#include "../../../lib/logger/LogStream.hpp"
#include "../../../lib/mathlib/vector/three_dimensional_vector.hpp"

mavros_msgs::Mavlink sysid;

mavros_msgs::HomePosition current_home;
void print_wp(const mavros_msgs::Waypoint& wp)
{
    ROS_INFO("gps:x_lat = %f y_long = %f z_alt = %f ", wp.x_lat,wp.y_long,wp.z_alt);
    ROS_INFO("command = %d frame = %d autocontinue = %d ",wp.command,wp.frame,wp.autocontinue);
    ROS_INFO("param:%f %f %f yaw = %f", wp.param1,wp.param2,wp.param3,wp.param4);
}
void sysid_cb(const mavros_msgs::Mavlink::ConstPtr &msg)
{
    sysid = *msg;
}
void homePosition_cb(const mavros_msgs::HomePosition::ConstPtr& msg){
    current_home = *msg;
}

int main(int argc, char **argv){

    map<int, double> waypointYaw;
    std::string uavName = "";
    std::string nodeName = "TestSysid";
    if(argc == 2){
        uavName = argv[1];
        uavName = uavName + "/";
        nodeName.append(uavName, 3, 1);
    }
    ros::init(argc, argv, nodeName);
    ros::NodeHandle nh;
    ros::Rate rate(20);
    

    // 1, 获得航点
    ros::Subscriber uav_sysid_sub = nh.subscribe<mavros_msgs::Mavlink>
            (uavName + "mavlink/from", 1, sysid_cb);
    ros::Subscriber uav_home_sub = nh.subscribe<mavros_msgs::HomePosition> 
            (uavName + "mavros/home_position/home", 1, homePosition_cb);


    while(ros::ok()){
        ros::spinOnce();
        rate.sleep();

        cout << "home.altitude  = " << current_home.geo.altitude << endl;
        cout << "home.latitude  = " << current_home.geo.latitude << endl;
        cout << "home.longitude = " << current_home.geo.longitude << endl;

        cout << uavName << "sysid: " << sysid << endl;
    }

    return 0;
}