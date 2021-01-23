#include "SubAndPub.hpp"

SubAndPub::SubAndPub(std::string uavName_){
        
    uavName = uavName_;
    std::cout << "uavName: " << uavName << std::endl;
    
    // subscriber
    home_sub = nh.subscribe<mavros_msgs::HomePosition> 
            (uavName + "mavros/home_position/home", 10, boost::bind(&SubAndPub::homePosition_cb, this, _1));
    state_sub = nh.subscribe<mavros_msgs::State>
            (uavName + "mavros/state", 10, boost::bind(&SubAndPub::state_cb, this, _1));
    uav_state_sub = nh.subscribe<mavros_msgs::VFR_HUD>  
            (uavName + "mavros/vfr_hud", 10, boost::bind(&SubAndPub::newUAVState, this, _1));
    uav_localPos_sub = nh.subscribe<geometry_msgs::PoseStamped>
            (uavName + "mavros/local_position/pose",10,boost::bind(&SubAndPub::new_localPose, this, _1));
    uav_globelPos_sub = nh.subscribe<sensor_msgs::NavSatFix>
            (uavName + "mavros/global_position/global", 10, boost::bind(&SubAndPub::global_position_form_px4_cb, this, _1));

    uav_localVel_sub = nh.subscribe<geometry_msgs::TwistStamped>
            (uavName + "mavros/local_position/velocity_local", 10, boost::bind(&SubAndPub::velocity_ned_fused_from_px4_cb, this, _1));

    uav_imu_sub = nh.subscribe<sensor_msgs::Imu>
            (uavName + "mavros/imu/data", 10,  boost::bind(&SubAndPub::imu_cb, this, _1));

    uav_windEstimation_sub = nh.subscribe<geometry_msgs::TwistWithCovarianceStamped>
            (uavName + "mavros/wind_estimation", 10, boost::bind(&SubAndPub::wind_estimate_from_px4_cb, this, _1));

    uav_localAccel_sub = nh.subscribe<geometry_msgs::AccelWithCovarianceStamped> //
            (uavName + "mavros/local_position/accel", 10, boost::bind(&SubAndPub::acc_ned_from_px4_cb, this, _1));
    
    uav_waypoints_sub = nh.subscribe<mavros_msgs::WaypointList>
            (uavName + "mavros/mission/waypoints", 10, boost::bind(&SubAndPub::waypointlist_from_px4_sub, this, _1));

    uav_waypoints_reached_sub = nh.subscribe<mavros_msgs::WaypointReached>
            (uavName + "mavros/mission/reached", 10, boost::bind(&SubAndPub::waypointReached_from_px4_sub, this, _1));
            
    GPStime_sub = nh.subscribe<sensor_msgs::TimeReference>
            (uavName + "mavros/time_reference",1,boost::bind(&SubAndPub::new_GPSTime, this, _1));

    velocity_global_fused_sub = nh.subscribe<geometry_msgs::TwistStamped>
            (uavName + "mavros/global_position/raw/gps_vel",1,boost::bind(&SubAndPub::velocity_global_fused_from_px4_cb, this, _1));


    // publisher
    home_pub = nh.advertise<mavros_msgs::HomePosition> 
            (uavName + "msgsFromPx4/home_position/home", 1);
    state_pub = nh.advertise<mavros_msgs::State>
            (uavName + "msgsFromPx4/state",1);
    uav_state_pub = nh.advertise<mavros_msgs::VFR_HUD>
            (uavName + "msgsFromPx4/vfr_hud",1);
    uav_localPos_pub = nh.advertise<geometry_msgs::PoseStamped>
            (uavName + "msgsFromPx4/local_position/pose",1);

    uav_globelPos_pub =  nh.advertise<sensor_msgs::NavSatFix>
            (uavName + "msgsFromPx4/global_position/global", 1);
        
    uav_localVel_pub =  nh.advertise<geometry_msgs::TwistStamped>
            (uavName + "msgsFromPx4/local_position/velocity_local", 1);   
    uav_imu_pub = nh.advertise<sensor_msgs::Imu>
            (uavName + "msgsFromPx4/imu/data", 1); 

    uav_windEstimation_pub =  nh.advertise<geometry_msgs::TwistWithCovarianceStamped>
            (uavName + "msgsFromPx4/wind_estimation", 1); 
    uav_localAccel_pub =  nh.advertise<geometry_msgs::AccelWithCovarianceStamped> //
            (uavName + "msgsFromPx4/local_position/accel", 1);                // the local accel
    uav_waypoints_pub =  nh.advertise<mavros_msgs::WaypointList>
            (uavName + "msgsFromPx4/mission/waypoints", 1);

    GPStime_pub = nh.advertise<sensor_msgs::TimeReference>
                (uavName + "msgsFromPx4/time_reference", 1);

    velocity_global_fused_pub = nh.advertise<geometry_msgs::TwistStamped>
            (uavName + "msgsFromPx4/global_position/raw/gps_vel",1);

}

SubAndPub::~SubAndPub(){}


void SubAndPub::waypointReached_from_px4_sub(const mavros_msgs::WaypointReached::ConstPtr &msg){
    waypoint_reached = *msg;
}

void SubAndPub::velocity_global_fused_from_px4_cb(const geometry_msgs::TwistStamped::ConstPtr &msg)
{
    velocity_global_fused_from_px4 = *msg;
}

void SubAndPub::new_GPSTime(const sensor_msgs::TimeReference::ConstPtr& msg){
   gpsTime = *msg;
}
void SubAndPub::setUavName(std::string uavName_){
    uavName = uavName_;
}
std::string SubAndPub::getUavName(){
        return uavName;
}

void SubAndPub::publishData(){
    state_pub.publish(current_state);
    uav_state_pub.publish(current_UAV_state);
    uav_localPos_pub.publish(current_localPose);
    uav_globelPos_pub.publish(global_position_form_px4);
    uav_localAccel_pub.publish(acc_ned_from_px4);
    uav_imu_pub.publish(imu);
    uav_localVel_pub.publish(velocity_ned_fused_from_px4);
    uav_windEstimation_pub.publish(wind_estimate_from_px4);
    uav_waypoints_pub.publish(waypoint_List);
    home_pub.publish(current_home);
    GPStime_pub.publish(gpsTime);
    velocity_global_fused_pub.publish(velocity_global_fused_from_px4);
}

void SubAndPub::printInfo(){
    MSGSSUBADNPUB("--------------------------------------------------------");
    MSGSSUBADNPUB_DOUBLE("airspeed: ", current_UAV_state.airspeed);
    MSGSSUBADNPUB_DOUBLE("groundSpeed: ", current_UAV_state.groundspeed);
    MSGSSUBADNPUB_DOUBLE("heading: ", current_UAV_state.heading);
    MSGSSUBADNPUB_DOUBLE("current_state: ", current_state.mode.c_str());
    MSGSSUBADNPUB_DOUBLE("waypoint reached seq: ", waypoint_reached.wp_seq);
    std::cout << "home altitude(84): " << std::setprecision(10) << current_home.geo.altitude << std::endl;
    std::cout << "home longitude(84): " << std::setprecision(10) << current_home.geo.longitude << std::endl;
    std::cout << "home latitude(84): " << std::setprecision(10) << current_home.geo.latitude << std::endl;
    MSGSSUBADNPUB_DOUBLE("global_position altitude(84)", global_position_form_px4.altitude);
    MSGSSUBADNPUB_DOUBLE("global_position longtitude(84)", global_position_form_px4.longitude);
    MSGSSUBADNPUB_DOUBLE("global_position latitude(84)", global_position_form_px4.latitude);
    MSGSSUBADNPUB_DOUBLE("current local position x(E): ", current_localPose.pose.position.x);
    MSGSSUBADNPUB_DOUBLE("current local position y(N): ", current_localPose.pose.position.y);
    MSGSSUBADNPUB_DOUBLE("current local position z(U): ", current_localPose.pose.position.z);
}

void SubAndPub::state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}
// airspeed etc.
void SubAndPub::newUAVState(const mavros_msgs::VFR_HUD::ConstPtr& msg){   
    current_UAV_state = *msg;
}
void SubAndPub::new_localPose(const geometry_msgs::PoseStamped::ConstPtr& msg){
    current_localPose = *msg;
}
void SubAndPub::global_position_form_px4_cb(const sensor_msgs::NavSatFix::ConstPtr &msg)
{
    global_position_form_px4 = *msg;

}
void SubAndPub::acc_ned_from_px4_cb(const geometry_msgs::AccelWithCovarianceStamped::ConstPtr &msg)
{
    acc_ned_from_px4 = *msg;
}
void SubAndPub::imu_cb(const sensor_msgs::Imu::ConstPtr &msg)
{
    imu = *msg;
}
void SubAndPub::velocity_ned_fused_from_px4_cb(const geometry_msgs::TwistStamped::ConstPtr &msg)
{
    velocity_ned_fused_from_px4 = *msg;
    
}
void SubAndPub::wind_estimate_from_px4_cb(const geometry_msgs::TwistWithCovarianceStamped::ConstPtr &msg)
{
    wind_estimate_from_px4 = *msg;
}
void SubAndPub::waypointlist_from_px4_sub(const mavros_msgs::WaypointList::ConstPtr &msg)
{
    waypoint_List = *msg;
    for(size_t i = 0; i < waypoint_List.waypoints.size(); i++)
        print_wp(waypoint_List.waypoints[i]);
}

void SubAndPub::print_wp(const mavros_msgs::Waypoint& wp)
{
    MSGSSUBANDPUB_INFO("gps:x_lat = %f y_long = %f z_alt = %f \n", wp.x_lat,wp.y_long,wp.z_alt);
    MSGSSUBANDPUB_INFO("command = %d frame = %d autocontinue = %d \n",wp.command,wp.frame,wp.autocontinue);
    MSGSSUBANDPUB_INFO("param:%f %f %f %f \n", wp.param1,wp.param2,wp.param3,wp.param4);
}

void SubAndPub::homePosition_cb(const mavros_msgs::HomePosition::ConstPtr& msg){
    current_home = *msg;
}
