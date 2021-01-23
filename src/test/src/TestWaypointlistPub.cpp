#include "TestWaypointlistPub.hpp"

mavros_msgs::WaypointList waypoint_List;
void print_wp(const mavros_msgs::Waypoint& wp)
{
    ROS_INFO("gps:x_lat = %f y_long = %f z_alt = %f ", wp.x_lat,wp.y_long,wp.z_alt);
    // ROS_INFO("command = %d frame = %d autocontinue = %d is_current = %d",wp.command,wp.frame,wp.autocontinue,wp.is_current);
    ROS_INFO("command = %d frame = %d autocontinue = %d ",wp.command,wp.frame,wp.autocontinue);
    ROS_INFO("param:%f %f %f %f", wp.param1,wp.param2,wp.param3,wp.param4);
}
void waypointlist_from_px4_sub(const mavros_msgs::WaypointList::ConstPtr &msg)
{
    waypoint_List = *msg;
    for(size_t i = 0; i < waypoint_List.waypoints.size(); i++)
        print_wp(waypoint_List.waypoints[i]);
}
mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}
int main(int argc, char **argv){

    ros::init(argc, argv, "TestWaypointlistPub");
    ros::NodeHandle nh;
    ros::Rate rate(20);
    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
            ("mavros/state", 1,state_cb);
    ros::Publisher state_pub = nh.advertise<mavros_msgs::State>
            ("msgsFromPx4/state",1);
    ros::Subscriber uav_waypoints_sub = nh.subscribe<mavros_msgs::WaypointList>
            ("mavros/mission/waypoints", 1,waypointlist_from_px4_sub);
    ros::Publisher uav_waypoints_pub =  nh.advertise<mavros_msgs::WaypointList>
            ("msgsFromPx4/mission/waypoints", 1); 

    while(ros::ok()){
        uav_waypoints_pub.publish(waypoint_List);
        state_pub.publish(current_state);
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}