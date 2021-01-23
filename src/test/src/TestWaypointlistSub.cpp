#include "TestWaypointlistSub.hpp"

mavros_msgs::WaypointList waypoint_List;
ros::Publisher uav_waypoints_pub;

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
    std::cout << "state: " << current_state.mode.c_str() << std::endl;
}
int main(int argc, char **argv){

    ros::init(argc, argv, "TestWaypointlistSub");
    ros::NodeHandle nh;
    ros::Rate rate(20);

    ros::Subscriber uav_waypoints_sub = nh.subscribe<mavros_msgs::WaypointList>
            ("msgsFromPx4/mission/waypoints", 1,waypointlist_from_px4_sub); 

    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
            ("msgsFromPx4/state", 1,state_cb);
    while(ros::ok()){
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}