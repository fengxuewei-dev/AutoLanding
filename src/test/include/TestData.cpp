#include "TestData.hpp"

TestData::TestData(std::string uavName_){
    uavName = uavName_;
    // ros::Subscriber home_sub
    // boost::bind(&TestData::newHomePosition_0, this, _1));
    home_sub_0 = nh.subscribe<mavros_msgs::HomePosition> 
            (uavName + "mavros/home_position/home", 1,boost::bind(&TestData::newHomePosition_0, this, _1));
	home_sub_1 = nh.subscribe<mavros_msgs::HomePosition> 
            (uavName + "mavros/home_position/home", 1,boost::bind(&TestData::newHomePosition_1, this, _1));
    home_sub_2 = nh.subscribe<mavros_msgs::HomePosition> 
            (uavName + "mavros/home_position/home", 1,boost::bind(&TestData::newHomePosition_2, this, _1));
    home_sub_3 = nh.subscribe<mavros_msgs::HomePosition> 
            (uavName + "mavros/home_position/home", 1,boost::bind(&TestData::newHomePosition_3, this, _1));
    home_sub_4 = nh.subscribe<mavros_msgs::HomePosition> 
            (uavName + "mavros/home_position/home", 1,boost::bind(&TestData::newHomePosition_4, this, _1));

    

    mission_reached_sub = nh.subscribe<mavros_msgs::WaypointReached> 
            (uavName + "mavros/mission/reached", 1,boost::bind(&TestData::missionReached, this, _1));
    mission_waypointList_sub = nh.subscribe<mavros_msgs::WaypointList> 
            (uavName + "mavros/mission/waypoints", 1,boost::bind(&TestData::missionWaypointList, this, _1));

	leader_state_sub = nh.subscribe<mavros_msgs::VFR_HUD>  (uavName + "msgsFromPx4/vfr_hud", 1, boost::bind(&TestData::newLeaderState, this, _1));
	leader_localPos_sub = nh.subscribe<geometry_msgs::PoseStamped> (uavName + "msgsFromPx4/local_position/pose",1,boost::bind(&TestData::new_leaderPose, this, _1));

    timer = nh.createTimer(ros::Duration(0.1), boost::bind(&TestData::timerCallback, this, _1));//定时0.1s

    uav_exitflag_pub = nh.advertise<fw_msgs::EXITflag>
        (uavName + "communication/exitFlag/exitflag", 1);

}
TestData::~TestData(){

}
void TestData::timerCallback(const ros::TimerEvent& e){
    timerEvent = e;
}
void TestData::newLeaderState(const mavros_msgs::VFR_HUD::ConstPtr& msg){
    current_Leader_state = *msg;
    std::cout<<"send heading        is:"<<current_Leader_state.heading<<std::endl;
    std::cout<<"send velocity    is:"<<current_Leader_state.airspeed<<std::endl;
}
void TestData::new_leaderPose(const geometry_msgs::PoseStamped::ConstPtr& msg){
	current_leaderPose = *msg;
    std::cout<<"x is:"<<current_leaderPose.pose.position.x<<std::endl;
    std::cout<<"y is:"<<current_leaderPose.pose.position.y<<std::endl;
    std::cout<<"z is:"<<current_leaderPose.pose.position.z<<std::endl;
}
void TestData::newHomePosition_0(const mavros_msgs::HomePosition::ConstPtr& msg)
{
	leader_home = *msg; 
}
void TestData::newHomePosition_1(const mavros_msgs::HomePosition::ConstPtr& msg)
{
	follower1_home = *msg; 
}
void TestData::newHomePosition_2(const mavros_msgs::HomePosition::ConstPtr& msg)
{
	follower2_home = *msg; 
}
void TestData::newHomePosition_3(const mavros_msgs::HomePosition::ConstPtr& msg)
{
	follower3_home = *msg; 
}
void TestData::newHomePosition_4(const mavros_msgs::HomePosition::ConstPtr& msg)
{
	follower4_home = *msg; 
}



void TestData::missionReached(const mavros_msgs::WaypointReached::ConstPtr& msg){
    _waypointReached_ = *msg;
}
void TestData::missionWaypointList(const mavros_msgs::WaypointList::ConstPtr& msg){
    _waypointLists_ = *msg;
}

void TestData::print_dists(){
    ROS_ERROR("the distance comes from the uavs!");
    cout << "uav1 --- uav0 : "; dist_0_1.print();
    cout << "uav2 --- uav0 : "; dist_0_2.print();
    cout << "uav3 --- uav0 : "; dist_0_3.print();
    cout << "uav4 --- uav0 : "; dist_0_4.print();
}
void TestData::getENUoffset(mavros_msgs::Waypoint startlistposition, mavros_msgs::Waypoint endlistposition, Eigen::Vector3d* enu_offset){
    
    GeographicLib::Geocentric earth(GeographicLib::Constants::WGS84_a(), GeographicLib::Constants::WGS84_f());
			
    Eigen::Vector3d goal_gps(endlistposition.x_lat, endlistposition.y_long, endlistposition.z_alt);
	Eigen::Vector3d point_gps(startlistposition.x_lat, startlistposition.y_long, startlistposition.z_alt);
			
	Eigen::Vector3d goal_ecef;
	Eigen::Vector3d position_ecef;

	earth.Forward(goal_gps.x(), goal_gps.y(), goal_gps.z(),goal_ecef.x(), goal_ecef.y(), goal_ecef.z());
	earth.Forward(point_gps.x(), point_gps.y(), point_gps.z(),position_ecef.x(), position_ecef.y(), position_ecef.z());

	Eigen::Vector3d offset_ecef = goal_ecef - position_ecef;
	*enu_offset = mavros::ftf::transform_frame_ecef_enu(offset_ecef, point_gps);
}
Point TestData::calculate_configuration_error(mavros_msgs::HomePosition follower_home){
    // 1. get the home position about the leader and follower
    Point error{0, 0};
    Eigen::Vector3d enu_offset;

    mavros_msgs::Waypoint current_home_;
    mavros_msgs::Waypoint leader_home_;

    current_home_.x_lat = follower_home.geo.latitude;
    current_home_.y_long = follower_home.geo.longitude;
    current_home_.z_alt = follower_home.geo.altitude;
    

    leader_home_.x_lat = leader_home.geo.latitude;
    leader_home_.y_long = leader_home.geo.longitude;
    leader_home_.z_alt = leader_home.geo.altitude;

    // 2. calculate the configuration error from the home position --- dist.x dist.y 方向角
    getENUoffset(current_home_, leader_home_, &enu_offset); // enu

    error.update(enu_offset.x(), enu_offset.y());

    return error;
}
void TestData::run(){
    // 计算距离
    dist_0_1 = calculate_configuration_error(follower1_home);
    dist_0_2 = calculate_configuration_error(follower2_home);
    dist_0_3 = calculate_configuration_error(follower3_home);
    dist_0_4 = calculate_configuration_error(follower4_home);

    // 打印距离
    print_dists();
}
