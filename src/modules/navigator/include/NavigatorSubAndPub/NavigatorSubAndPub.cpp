#include "NavigatorSubAndPub.hpp"

// uavName_ = uavX/
NavigatorSubAndPub::NavigatorSubAndPub(std::string uavName_):logger_Leader(uavName_), logger_Follower(uavName_){
    uavName = uavName_;
    
    // vfr_hud
    uav_state_sub = nh.subscribe<mavros_msgs::VFR_HUD>  
            (uavName + "msgsFromPx4/vfr_hud", 10, boost::bind(&NavigatorSubAndPub::newUAVState, this, _1));
    
    uav_gpsTime_sub = nh.subscribe<sensor_msgs::TimeReference>
            (uavName + "mavros/time_reference", 10, boost::bind(&NavigatorSubAndPub::newGpsTime, this, _1));

    // home position
    uav_home_sub = nh.subscribe<mavros_msgs::HomePosition> 
            (uavName + "msgsFromPx4/home_position/home", 10, boost::bind(&NavigatorSubAndPub::homePosition_cb, this, _1));

    // waypoints list
    uav_waypoints_sub = nh.subscribe<mavros_msgs::WaypointList>
            (uavName + "msgsFromPx4/mission/waypoints", 10, boost::bind(&NavigatorSubAndPub::waypointlist_sub, this, _1));

     // from the udp 
    formationNavigator_sub = nh.subscribe<fw_msgs::FormationNavigator>
            (uavName + "communication/formationData/navigator", 10, boost::bind(&NavigatorSubAndPub::formationNavigator_cb, this, _1));

    // local position
    uav_localPos_sub = nh.subscribe<geometry_msgs::PoseStamped> 
            (uavName + "msgsFromPx4/local_position/pose", 10, boost::bind(&NavigatorSubAndPub::new_localPose, this, _1));

    uavflag_sub = nh.subscribe<fw_msgs::uavflag> 
            (uavName + "processer/uavflag", 10, boost::bind(&NavigatorSubAndPub::uavflag_cb, this, _1));

    // publish the data to position controller
    position_setpoint_triplet_pub = nh.advertise<fw_msgs::position_setpoint_triplet>
            (uavName + "navigator/position_sp_triplet", 1);
}
NavigatorSubAndPub::~NavigatorSubAndPub(){

}
void NavigatorSubAndPub::uavflag_cb(const fw_msgs::uavflag::ConstPtr& msg){
    uavflag_state = *msg;
}

std::string NavigatorSubAndPub::getUavName(){
    return uavName;
}
void NavigatorSubAndPub::printInfo(){
    int i = 0;
    cout << "local position.x(E): " <<  current_localPose.pose.position.x << endl;
    cout << "local position.y(N): " <<  current_localPose.pose.position.y << endl;
    cout << "local position.z(U): " <<  current_localPose.pose.position.z << endl;
}

void NavigatorSubAndPub::newGpsTime(const sensor_msgs::TimeReference::ConstPtr& msg){
    Gps_time = *msg;
    now = Gps_time.time_ref;
}
void NavigatorSubAndPub::formationNavigator_cb(const fw_msgs::FormationNavigator::ConstPtr& msg){
    formationNavigator = *msg;
    
    leader_home.geo.altitude = formationNavigator.homeAlt;
    leader_home.geo.longitude = formationNavigator.homeLon;
    leader_home.geo.latitude = formationNavigator.homeLat;

    leader_position.pose.position.x = formationNavigator.position_x;
    leader_position.pose.position.y = formationNavigator.position_y;
    leader_position.pose.position.z = formationNavigator.position_z;
}
void NavigatorSubAndPub::setPoistionSetpoint_formation(){
    position_setpoint.enu_nextWaypoint.x_lat = leader_position.pose.position.x;
    position_setpoint.enu_nextWaypoint.y_long = leader_position.pose.position.y;
    position_setpoint.enu_nextWaypoint.z_alt = leader_position.pose.position.z;

    position_setpoint.enu_currentWaypoint.x_lat = NULLDATA;
    position_setpoint.enu_currentWaypoint.y_long = NULLDATA;
    position_setpoint.enu_currentWaypoint.z_alt = NULLDATA;

    position_setpoint.ExistNext = NULLDATA;
    position_setpoint.Throttle = NULLDATA;
    WriteLogFile();
}
void NavigatorSubAndPub::setGap(){
    gap.x = formationNavigator.gap_x;
    gap.y = formationNavigator.gap_y;
}
void NavigatorSubAndPub::getWaypoint_formation(){
    

    // debug
    std::cout << "leader_position(" << leader_position.pose.position.x << ", " << leader_position.pose.position.y << ")" << std::endl;

    double leaderHeading = (-(formationNavigator.leaderHeading) * (M_PI/180.0)) + M_PI/2.0;

    leader_position.pose.position.x += cos(atan2(gap.y,gap.x) + leaderHeading)* Point::norm(gap);
    leader_position.pose.position.y += sin(atan2(gap.y,gap.x) + leaderHeading)* Point::norm(gap);
  
    std::cout << "final_position(" << leader_position.pose.position.x << ", " << leader_position.pose.position.y << ")" << std::endl;
  
    leader_position.pose.position.x += calculate_configuration_error().x;
    leader_position.pose.position.y += calculate_configuration_error().y;
  
/*
    leader_position.pose.position.x += calculate_time_error().x;
    leader_position.pose.position.y += calculate_time_error().y;
*/
    formationWriteLogOthers();
}

Point NavigatorSubAndPub::calculate_configuration_error(){
    // 1. get the home position about the leader and follower
    Point error{0, 0};
    Eigen::Vector3d enu_offset;

    mavros_msgs::Waypoint current_home_;
    mavros_msgs::Waypoint leader_home_;

    current_home_.x_lat = current_home.geo.latitude;
    current_home_.y_long = current_home.geo.longitude;
    current_home_.z_alt = current_home.geo.altitude;
    

    leader_home_.x_lat = leader_home.geo.latitude;
    leader_home_.y_long = leader_home.geo.longitude;
    leader_home_.z_alt = leader_home.geo.altitude;

    // 2. calculate the configuration error from the home position --- dist.x dist.y 方向角
    getENUoffset(current_home_, leader_home_, &enu_offset);

    error.update(enu_offset.x(), enu_offset.y());

    return error;
}
Point NavigatorSubAndPub::calculate_time_error(){
    Point error{0, 0};
    double time_error = (now - formationNavigator.gps_time).toSec();
    cout << "now : (" << now.sec << ", " << now.nsec << ")" << endl;
    cout << "formationNavigator.time : (" << formationNavigator.gps_time.sec << ", " << formationNavigator.gps_time.nsec << ")" << endl;
    double distance_error = time_error * formationNavigator.leaderAirspeed;
    error.update(
        distance_error * sin(formationNavigator.leaderHeading * M_PI / 180.0), 
        distance_error * cos(formationNavigator.leaderHeading * M_PI / 180.0)
    );
    return error;
}
void NavigatorSubAndPub::homePosition_cb(const mavros_msgs::HomePosition::ConstPtr& msg){
    current_home = *msg;
}


void NavigatorSubAndPub::newUAVState(const mavros_msgs::VFR_HUD::ConstPtr& msg){
    current_UAV_state = *msg;
}

// 相同返回
bool NavigatorSubAndPub::isSameWaypointLists(const mavros_msgs::WaypointList wpsList1,const mavros_msgs::WaypointList wpsList2){
    bool conclu = true;
    if(wpsList1.waypoints.size() == wpsList2.waypoints.size()){ // 列表大小相同
        // 逐个进行比较
        size_t k = 0;
        for(; k < wpsList1.waypoints.size(); k++)
        {
            if(
                wpsList1.waypoints[k].command     == wpsList2.waypoints[k].command
                && wpsList1.waypoints[k].param1     == wpsList2.waypoints[k].param1
                && wpsList1.waypoints[k].param2     == wpsList2.waypoints[k].param2
                && wpsList1.waypoints[k].param3     == wpsList2.waypoints[k].param3
                // && wpsList1.waypoints[k].param4     == wpsList2.waypoints[k].param4 // 一般是nan
                && wpsList1.waypoints[k].x_lat      == wpsList2.waypoints[k].x_lat
                && wpsList1.waypoints[k].y_long     == wpsList2.waypoints[k].y_long
                && wpsList1.waypoints[k].z_alt      == wpsList2.waypoints[k].z_alt
            ){
                // std::cout << "k = " << k << std::endl;
            }
            else{
                conclu = false;
                break;
            }
        }
    }
    else 
        conclu = false;
    return conclu; // 相同
}
void NavigatorSubAndPub::waypointlist_sub(const mavros_msgs::WaypointList::ConstPtr &msg)
{
    waypoint_List = *msg;
    if(waypoint_List.waypoints.size() == 0){
        // std::cout << "航线列表大小为0" << std::endl;
        return; // 保证航线的航点列表不为0
    }
    if(i == 0){
        i++; // 第一次执行该列表
        pre_waypoint_List = waypoint_List; // 保留航线
    } 
    // else{ // 第二次进入, 判断航线列表是否相同
    //     if(isSameWaypointLists(pre_waypoint_List, waypoint_List)){ // 相同
    //         GetNewWaypointList = false;
    //         // std::cout << "航线列表一致, 继续执行该航线" << std::endl;
    //     }else{
    //         // 航线列表不一样, 执行新的航线
    //         GetNewWaypointList = true;
    //         pre_waypoint_List = waypoint_List; // 保留航线
    //         // std::cout << "航线列表刷新, 切换新航线执行" << std::endl;
    //     }
    // }
}
void NavigatorSubAndPub::new_localPose(const geometry_msgs::PoseStamped::ConstPtr& msg){
	current_localPose = *msg;
}

int NavigatorSubAndPub::getWaypointExecuted(){
    return new_previous_sq;
}
int NavigatorSubAndPub::getWaypointExecuting(){
    return new_current_sq;
}

bool NavigatorSubAndPub::isExitNextWaypoint(){
    return new_current_sq == enu_waypoint_List.waypoints.size() - 1 ? false : true;
}

void NavigatorSubAndPub::singleGPSWaypointListLog(const mavros_msgs::Waypoint gps_waypoint){
    logger_Leader.log_gps_waypointslist_x_lat.logPrint(gps_waypoint.x_lat);
    logger_Leader.log_gps_waypointslist_y_lon.logPrint(gps_waypoint.y_long);
    logger_Leader.log_gps_waypointslist_z_alt.logPrint(gps_waypoint.z_alt);
}

void NavigatorSubAndPub::singleENUWaypointListLog(const mavros_msgs::Waypoint enu_waypoint){
    logger_Leader.log_enu_waypointslist_x.logPrint(enu_waypoint.x_lat);
    logger_Leader.log_enu_waypointslist_y.logPrint(enu_waypoint.y_long);
    logger_Leader.log_enu_waypointslist_z.logPrint(enu_waypoint.z_alt);
}

void NavigatorSubAndPub::singleWriteLog(){
    NAVIGATOR("长机写日志: localPosition");
    logger_Leader.local_x.logPrint(current_localPose.pose.position.x);
    logger_Leader.local_y.logPrint(current_localPose.pose.position.y);
    logger_Leader.local_z.logPrint(current_localPose.pose.position.z);
}
void NavigatorSubAndPub::formationWriteLog(){
    NAVIGATOR("从机写日志: localPosition");
    logger_Follower.local_x.logPrint(current_localPose.pose.position.x);
    logger_Follower.local_y.logPrint(current_localPose.pose.position.y);
    logger_Follower.local_z.logPrint(current_localPose.pose.position.z);
}
void NavigatorSubAndPub::formationWriteLogOthers(){
    NAVIGATOR("从机写日志: gap_x, gap_y, FinalPosition");
    
    logger_Follower.gap_x.logPrint(gap.x);
    logger_Follower.gap_y.logPrint(gap.y);

    logger_Follower.finalPosition_x.logPrint(leader_position.pose.position.x);      // 期望位置
    logger_Follower.finalPosition_y.logPrint(leader_position.pose.position.y);      // 期望位置
    logger_Follower.finalPosition_z.logPrint(leader_position.pose.position.z);      // 期望位置

    
}

void NavigatorSubAndPub::Gerenal_2_General(){
    ROS_ERROR("start Gerenal_2_General");
    std::cout << "online : " << generalMission.getPositionOnLine(
        {current_localPose.pose.position.x, current_localPose.pose.position.y}, 
        {enu_waypoint_List.waypoints[new_previous_sq].x_lat, enu_waypoint_List.waypoints[new_previous_sq].y_long},
        {enu_waypoint_List.waypoints[new_current_sq ].x_lat, enu_waypoint_List.waypoints[new_current_sq ].y_long}
    ) << std::endl;
    if(generalMission.getPositionOnLine(
        {current_localPose.pose.position.x, current_localPose.pose.position.y}, 
        {enu_waypoint_List.waypoints[new_previous_sq].x_lat, enu_waypoint_List.waypoints[new_previous_sq].y_long},
        {enu_waypoint_List.waypoints[new_current_sq ].x_lat, enu_waypoint_List.waypoints[new_current_sq ].y_long}
    ) > DISTANCE_PERCENTAGE){
        ROS_ERROR("Will switch the waypoint");
        new_previous_sq = new_current_sq;
    }
    else{
        ROS_ERROR("not gotten the current waypoint");
    }
    if(new_previous_sq == new_current_sq && isExitNextWaypoint()){ // the sequence add one
        ++new_current_sq;
    } 
    cout << "new_previous_sq: " << new_previous_sq << endl;
    cout << "new_current_sq: " << new_current_sq << endl;
}
void NavigatorSubAndPub::Gerenal_2_Loiter(){

    // 1. 计算距离
    float dist = loiterMission.enu_get_distance_to_next_waypoint(
		current_localPose.pose.position.x, current_localPose.pose.position.y, current_localPose.pose.position.z,
		enu_waypoint_List.waypoints[new_current_sq].x_lat,
		enu_waypoint_List.waypoints[new_current_sq].y_long,
		enu_waypoint_List.waypoints[new_current_sq].z_alt
	);
    cout << "dist = " << dist << endl;
    
    // if the distance <= 1.2 * Radius and the time has gotten, then the vehicle has gotten the loiter waypoint and begin to loiter.
    loiterMission.is_loiter_mission_reached_no_2_yes( 
	    dist, 	 														// distance
		enu_waypoint_List.waypoints[new_current_sq],		            // loiter waypoint
		new_previous_sq													// 当前的位置下标
	); 
    if(new_previous_sq == new_current_sq && isExitNextWaypoint()){ // the sequence add one
        ++new_current_sq;
    } 
    cout << new_previous_sq << endl;
    cout << new_current_sq << endl;
}

void NavigatorSubAndPub::Loiter_2_Anything(float dist){
    std::cout << "Loiter_2_Anything " << std::endl;
    // 判断航点是否到达 loiter 航点(距离和time)
    loiterMission.is_loiter_mission_reached(
		dist, 	                                                            // distance
		enu_waypoint_List.waypoints[new_previous_sq].param3,		        // Radius
		new_previous_sq,												    // the waypoint sequence
		enu_waypoint_List.waypoints[new_previous_sq].param1  		        // loiter time
    ); 
    if(new_previous_sq == new_current_sq && isExitNextWaypoint()){          // the sequence add one
        enu_waypoint_List.waypoints[--new_previous_sq].command = NAV_CMD_WAYPOINT;          // 将 loiter time航点设置为 普通航点,为了 下一步使用 Fillet 进行航线切换
        // ++new_previous_sq;      // LOITER TO STRAIGHT
    } 
}
// param1: time
// param3: radius
void NavigatorSubAndPub::Loiter_2_General(){
    loiterMission.is_loiter_mission_reached_yes_2_no(
        new_previous_sq,
        enu_waypoint_List.waypoints[new_previous_sq].param1
    );
    if(new_previous_sq == new_current_sq && isExitNextWaypoint()){ // the sequence add one
        ++new_current_sq;
    } 
} 
void NavigatorSubAndPub::WriteLogFile(){
    logger_Leader.log_publish_Throttle.logPrint(int(position_setpoint.Throttle));
    logger_Leader.log_publish_ExistNext.logPrint(int(position_setpoint.ExistNext));
    
    if(!isRC){
        logger_Leader.log_publish_currentWaypoint_x.logPrint(position_setpoint.currentWaypoint.x_lat);
        logger_Leader.log_publish_currentWaypoint_y.logPrint(position_setpoint.currentWaypoint.y_long);
        logger_Leader.log_publish_currentWaypoint_z.logPrint(position_setpoint.currentWaypoint.z_alt);

        logger_Leader.log_publish_nextWaypoint_x.logPrint(position_setpoint.nextWaypoint.x_lat);
        logger_Leader.log_publish_nextWaypoint_y.logPrint(position_setpoint.nextWaypoint.y_long);
        logger_Leader.log_publish_nextWaypoint_z.logPrint(position_setpoint.nextWaypoint.z_alt);
    }
    logger_Leader.log_publish_enu_currentWaypoint_x.logPrint(position_setpoint.enu_currentWaypoint.x_lat);
    logger_Leader.log_publish_enu_currentWaypoint_y.logPrint(position_setpoint.enu_currentWaypoint.y_long);
    logger_Leader.log_publish_enu_currentWaypoint_z.logPrint(position_setpoint.enu_currentWaypoint.z_alt);

    logger_Leader.log_publish_enu_nextWaypoint_x.logPrint(position_setpoint.enu_nextWaypoint.x_lat);
    logger_Leader.log_publish_enu_nextWaypoint_y.logPrint(position_setpoint.enu_nextWaypoint.y_long);
    logger_Leader.log_publish_enu_nextWaypoint_z.logPrint(position_setpoint.enu_nextWaypoint.z_alt);
}
void NavigatorSubAndPub::choose_position_setpoints(){
    if(isOffboard){
        std::cout << "offboard control is true , will setPositionSetpoint!" << std::endl;
        setPoistionSetpoint_TECS();
    }
    else if(isRC){
        std::cout << "rc control is true , will setPositionSetpoint!" << std::endl;
        setPoistionSetpoint();
    }

}

void NavigatorSubAndPub::setPoistionSetpoint(){
    int8_t throttle = 17;
    position_setpoint.Throttle = throttle;

    /* for the fillet */
    if( 2 == algorithms.getState() ){
        position_setpoint.enu_currentWaypoint = algorithms.fillet_center;

        // 保存生成的loiter 航点
        logger_Leader.log_generate_loiter_waypoints_x.logPrint(position_setpoint.enu_currentWaypoint.x_lat);
        logger_Leader.log_generate_loiter_waypoints_y.logPrint(position_setpoint.enu_currentWaypoint.y_long);
        logger_Leader.log_generate_loiter_Radius.logPrint(position_setpoint.enu_currentWaypoint.param3);
    }
    else
        position_setpoint.enu_currentWaypoint = enu_waypoint_List.waypoints[getWaypointExecuted()];
    
    // 若 LastPath 为 true, 即 已经到达了最后一条航线, 我需要发送一个loiter航点, 为 current waypoint
    if(new_previous_sq != new_current_sq)
    {   
        /* exist the next waypoint than updata the content */
        position_setpoint.ExistNext = true;

        /* for the fillet */
        position_setpoint.enu_nextWaypoint = enu_waypoint_List.waypoints[getWaypointExecuting()];
    }
    else
        position_setpoint.ExistNext = false;

	WriteLogFile();
}
// void NavigatorSubAndPub::setPoistionSetpoint(){
//     int8_t throttle = 17;
//     position_setpoint.Throttle = throttle;

// // 到了 state1 发送一个 loiter 的航点; 到了 state2 也是发送相同的loiter航点, ;  nextwaypoint为下一个航点 new_current_sp
// // 到了平面H1的时候 我应该发布 current_waypoint 为z_1 下一个航点为z_2 ;  state == 3;
// // 到了 平面H2的时候, 我应该发布当前航点为loiter        state == 4
// // 到了平面H3 的时候, 我应该发布当前航点为 z_3 下一个航点是 (到了state1) state1的loiter航点

//     if( algorithms.getState() == 1 || algorithms.getState() == 2 || algorithms.getState() == 4 || algorithms.getState() == 5) // 发布loiter航点
//         position_setpoint.currentWaypoint = algorithms.fillet_center;
//     else if(algorithms.getState() == 3 ){
//         position_setpoint.currentWaypoint = algorithms.r;
//     }
//     // position_setpoint.currentWaypoint = enu_waypoint_List.waypoints[getWaypointExecuted()];
    
//     if(new_previous_sq != new_current_sq)
//     {   
//         /* exist the next waypoint then updata the content */
//         position_setpoint.ExistNext = true;

//         if(algorithms.getState() == 3){
//             position_setpoint.nextWaypoint.command = 16;
//             position_setpoint.nextWaypoint.x_lat = algorithms.z_2.getY();
//             position_setpoint.nextWaypoint.y_long = algorithms.z_2.getX();
//             position_setpoint.nextWaypoint.z_alt = -algorithms.z_2.getZ();
//         }else{
//             position_setpoint.nextWaypoint = enu_waypoint_List.waypoints[getWaypointExecuting()];
//         }
//         ROS_ERROR("has send new_current_sq");
//     }
//     else
//         position_setpoint.ExistNext = false;
    
//     cout << "next waypoint ";
//     print_wp(enu_waypoint_List.waypoints[getWaypointExecuting()]);
// }

void NavigatorSubAndPub::setPoistionSetpoint_TECS(){
    ROS_ERROR("setPoistionSetpoint_TECS() >>>>> ");
    int8_t throttle = 17;
    position_setpoint.Throttle = throttle;

    position_setpoint.currentWaypoint = gps_waypoint_List.waypoints[getWaypointExecuted()];
    position_setpoint.enu_currentWaypoint = enu_waypoint_List.waypoints[getWaypointExecuted()];

    if(new_previous_sq != new_current_sq)
    {   
        /* exist the next waypoint than updata the content */
        position_setpoint.ExistNext = true;
        position_setpoint.nextWaypoint = gps_waypoint_List.waypoints[getWaypointExecuting()];
        position_setpoint.enu_nextWaypoint = enu_waypoint_List.waypoints[getWaypointExecuting()];
    }
    else
        position_setpoint.ExistNext = false;
    WriteLogFile();
}

// mav_sys_id

double NavigatorSubAndPub::enu_get_distance_xy_to_next_waypoint(
    double cur_lat, double cur_lon,
    double nex_lat, double nex_lon
){
        return sqrt( 
            (cur_lat - nex_lat) * (cur_lat - nex_lat) + 
            (cur_lon - nex_lon) * (cur_lon - nex_lon) 
        );
}
void NavigatorSubAndPub::straight_2_straight(){
    ROS_ERROR("enter the straight 2 straight");

    // algorithms.StraightLineSwitching_Fillet(enu_waypoint_List, current_localPose, 20, new_current_sq); //半径为100
    // local position 距离下一个航点的的距离小于等于100 米进行切
    double dist_xy = enu_get_distance_xy_to_next_waypoint(
                current_localPose.pose.position.x, current_localPose.pose.position.y,
                enu_waypoint_List.waypoints[new_current_sq].x_lat,
                enu_waypoint_List.waypoints[new_current_sq].y_long
    );
    if(dist_xy>=0 && dist_xy <=100){
        new_current_sq++;
    }
    cout << "new_previous_sq: " << new_previous_sq << endl;
    cout << "new_current_sq: " << new_current_sq << endl;
    
    if( new_current_sq == new_previous_sq + 2){ // the sequence add one
        ++new_previous_sq;
    }
}

void NavigatorSubAndPub::WaypointSwitch(){ // 根据距离或者距离加时间来判断标志位

    ROS_ERROR("start navigator WaypointSwitch ...");
    
    cout << "enu_waypoint_List.waypoints[new_previous_sq].command: " << enu_waypoint_List.waypoints[new_previous_sq].command << endl;
    cout << "enu_waypoint_List.waypoints[new_current_sq].command: " << enu_waypoint_List.waypoints[new_current_sq].command << endl;
    // straight line & orbit circle
    if(enu_waypoint_List.waypoints[new_previous_sq].command != MAV_CMD_NAV_LOITER_TIME){
        if( new_previous_sq != new_current_sq ){
            if(
                enu_waypoint_List.waypoints[ new_current_sq ].command != MAV_CMD_NAV_LOITER_TIME &&
                enu_waypoint_List.waypoints[ new_current_sq ].command != MAV_CMD_NAV_LOITER_UNLIM
             ) // 不等于loiter中的每一种
            {
                NAVIGATOR_DOUBLE("RC is : ", isRC);

                // 使用的是RC信号, 那么, 使用的是 ENU 航点数据
                isRC ? straight_2_straight() : Gerenal_2_General();
            }
            else{
                Gerenal_2_Loiter();
            }
        }
    }
    if(enu_waypoint_List.waypoints[new_previous_sq].command == MAV_CMD_NAV_LOITER_TIME){
        if( new_previous_sq != new_current_sq ){
            
            // 现在计算出来的结果是和当前loiter航点的距离
            float dist = loiterMission.enu_get_distance_to_next_waypoint(
                current_localPose.pose.position.x, current_localPose.pose.position.y, current_localPose.pose.position.z,
                enu_waypoint_List.waypoints[new_previous_sq].x_lat,
                enu_waypoint_List.waypoints[new_previous_sq].y_long,
                enu_waypoint_List.waypoints[new_previous_sq].z_alt
            );
            cout << "dist: " << dist << endl;
            Loiter_2_Anything(dist);
        }
    }      
}

// void NavigatorSubAndPub::setPoistionSetpoint(){
//     ROS_ERROR("start navigator WaypointSwitch ...");
//     int8_t throttle = 17;
//     position_setpoint.Throttle = throttle;
//     ROS_ERROR("set navigator current waypoint ...");
//     position_setpoint.currentWaypoint = enu_waypoint_List.waypoints[getWaypointExecuted()];
//     cout << "new_previous_sq： " << new_previous_sq << endl;
//     cout << "new_current_sq： " << new_current_sq << endl;
//     if(new_previous_sq != new_current_sq)
//     {   
//         ROS_ERROR("set navigator next waypoint ...");
//         /* exist the next waypoint than updata the content */
//         position_setpoint.ExistNext = true;
//         position_setpoint.nextWaypoint = enu_waypoint_List.waypoints[getWaypointExecuting()];
//     }
//     else
//         position_setpoint.ExistNext = false;
// }
void NavigatorSubAndPub::showDataFrom_udp(){
    cout << "home alt : " << formationNavigator.homeAlt << endl;
    cout << "home lat : " << formationNavigator.homeLat << endl;
    cout << "home lon : " << formationNavigator.homeLon << endl;

    cout <<"gps_time.sec: " << formationNavigator.gps_time.sec << endl;
    cout << "position_z: " << formationNavigator.position_z << endl;
    cout << "position_x: " << formationNavigator.position_x <<endl;
    cout << "position_y : " << formationNavigator.position_y << endl;

    // gap的值
    cout << "gapx" << formationNavigator.gap_x << endl;
    cout << "gapy" << formationNavigator.gap_y << endl << endl; 
      

}
void NavigatorSubAndPub::showData(){
    NAVIGATOR("start to show Data ...");
    if(isOffboard){
        NAVIGATOR("offboard模式下, 发送GPS点以及对应的ENU点");
        std::cout << " --------------- GPS -------------" << std::endl;
        print_wp(position_setpoint.currentWaypoint);
        print_wp(position_setpoint.nextWaypoint);
        std::cout << " --------------- ENU -------------" << std::endl;
        print_wp(position_setpoint.enu_currentWaypoint);
        print_wp(position_setpoint.enu_nextWaypoint);
        NAVIGATOR_DOUBLE("油门大小: ", +position_setpoint.Throttle);
        cout << endl;
    }
    else if(isRC){
        NAVIGATOR("RC模式下, 只发送ENU点即可");
        std::cout << " --------------- ENU -------------" << std::endl;
        print_wp(position_setpoint.enu_currentWaypoint);
        print_wp(position_setpoint.enu_nextWaypoint);
        NAVIGATOR_DOUBLE("油门大小: ", +position_setpoint.Throttle);
        cout << endl;
    }
}
 void NavigatorSubAndPub::print_wp(const mavros_msgs::Waypoint& wp)
{
    ROS_INFO("waypoint: x_lat = %f y_long = %f z_alt = %f ", wp.x_lat,wp.y_long,wp.z_alt);
    // ROS_INFO("command = %d frame = %d autocontinue = %d is_current = %d",wp.command,wp.frame,wp.autocontinue,wp.is_current);
    ROS_INFO("command = %d frame = %d autocontinue = %d ",wp.command,wp.frame,wp.autocontinue);
    ROS_INFO("param:%f %f %f %f", wp.param1,wp.param2,wp.param3,wp.param4);
}
void NavigatorSubAndPub::getENUoffset(
    mavros_msgs::Waypoint startlistposition, 
    mavros_msgs::Waypoint endlistposition, 
    Eigen::Vector3d *enu_offset
){
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


void NavigatorSubAndPub::GPS_update(){                // 更新航点列表 为了给offboard使用
    // 第一个航点 home 点
    ROS_ERROR("GPS_update>>>>");

    gps_waypoint_List.waypoints.push_back(mavros_msgs::Waypoint());

    gps_waypoint_List.waypoints[0].x_lat = current_home.geo.latitude;
	gps_waypoint_List.waypoints[0].y_long = current_home.geo.longitude;
    gps_waypoint_List.waypoints[0].z_alt = 100;    

    size_t i = 0;
    for( i = 1; i < waypoint_List.waypoints.size() + 1 ; i++){
		gps_waypoint_List.waypoints.push_back(mavros_msgs::Waypoint());

		gps_waypoint_List.waypoints[i].command = waypoint_List.waypoints[i - 1].command;

		gps_waypoint_List.waypoints[i].param1 = waypoint_List.waypoints[i - 1].param1;
		gps_waypoint_List.waypoints[i].param2 = waypoint_List.waypoints[i - 1].param2;
		gps_waypoint_List.waypoints[i].param3 = waypoint_List.waypoints[i - 1].param3;
		gps_waypoint_List.waypoints[i].param4 = waypoint_List.waypoints[i - 1].param4;

		gps_waypoint_List.waypoints[i].x_lat = waypoint_List.waypoints[i - 1].x_lat;
		gps_waypoint_List.waypoints[i].y_long = waypoint_List.waypoints[i - 1].y_long;
		gps_waypoint_List.waypoints[i].z_alt = waypoint_List.waypoints[i - 1].z_alt;
	}

    // 添加 home 点到最后一个位置
    gps_waypoint_List.waypoints.push_back(mavros_msgs::Waypoint());
	gps_waypoint_List.waypoints[i].command = MAV_CMD_NAV_LOITER_UNLIM;
	gps_waypoint_List.waypoints[i].x_lat = current_home.geo.latitude;
	gps_waypoint_List.waypoints[i].y_long = current_home.geo.longitude;
	gps_waypoint_List.waypoints[i].z_alt = 100;
    gps_waypoint_List.waypoints[i].param3 = 30;
    
    // 打印GPS航点信息
    NAVIGATOR("打印 GPS 航点信息的值");
    size_t k = 0;
    for(k = 0; k < waypoint_List.waypoints.size(); k++){
        print_wp(waypoint_List.waypoints[k]);
    }
}
/*ENU的转化*/
// ENU: 是 home + 航点列表 + home
void NavigatorSubAndPub::GPS_transform_ENU(){
    ROS_ERROR("GPS_transform_ENU >>>>");
    
    enu_waypoint_List.waypoints.clear(); // 清空 vector
    std::cout << "清空航点列表, 睡眠1秒钟" << std::endl;
    sleep(1); // 0.05s 卡不住; 0.5s 卡不知
    
    // 需要前 startwaypoint 的 ENU 的值， 和计算之后的 enu_Offset
    enu_waypoint_List.waypoints.push_back(mavros_msgs::Waypoint());
	enu_waypoint_List.waypoints[0].command = 16;
	enu_waypoint_List.waypoints[0].x_lat = 0;
	enu_waypoint_List.waypoints[0].y_long = 0;
	enu_waypoint_List.waypoints[0].z_alt = 50.0;
	
    singleENUWaypointListLog(enu_waypoint_List.waypoints[0]);

    mavros_msgs::Waypoint home_point;

    // ********************************************************************
    // 测试
    // ********************************************************************
    home_point.x_lat = current_home.geo.latitude;
	home_point.y_long = current_home.geo.longitude;
    home_point.z_alt = 100;
    singleGPSWaypointListLog(home_point);
    
    enu_waypoint_List.waypoints.push_back(mavros_msgs::Waypoint());
    
    Eigen::Vector3d enu_offset;
    getENUoffset(home_point, waypoint_List.waypoints[0], &enu_offset);
    enu_waypoint_List.waypoints[1].command = 16;
	// GPS: 获得航线: 第一个航点是
	enu_waypoint_List.waypoints[1].param1 = waypoint_List.waypoints[0].param1;
	enu_waypoint_List.waypoints[1].param2 = waypoint_List.waypoints[0].param2;
	enu_waypoint_List.waypoints[1].param3 = waypoint_List.waypoints[0].param3;
	enu_waypoint_List.waypoints[1].param4 = waypoint_List.waypoints[0].param4;
	
    enu_waypoint_List.waypoints[1].x_lat = enu_offset.x();
	enu_waypoint_List.waypoints[1].y_long = enu_offset.y();

#ifdef _USE_THREE_DIMENSION_VF_
    enu_waypoint_List.waypoints[1].z_alt = waypoint_List.waypoints[0].z_alt;
#else
	enu_waypoint_List.waypoints[1].z_alt = 100;
#endif

    singleENUWaypointListLog(enu_waypoint_List.waypoints[1]);
	
    size_t i = 0;
    for( i = 2; i < waypoint_List.waypoints.size() + 1; i++){
        // enu 2 ==> enu 1 + offset（waypoint 
		getENUoffset(waypoint_List.waypoints[i-2], waypoint_List.waypoints[i-1], &enu_offset);
		enu_waypoint_List.waypoints.push_back(mavros_msgs::Waypoint());

		enu_waypoint_List.waypoints[i].command = waypoint_List.waypoints[i - 1].command;
		enu_waypoint_List.waypoints[i].param1 = waypoint_List.waypoints[i - 1].param1;
		enu_waypoint_List.waypoints[i].param2 = waypoint_List.waypoints[i - 1].param2;
		enu_waypoint_List.waypoints[i].param3 = waypoint_List.waypoints[i - 1].param3;
		enu_waypoint_List.waypoints[i].param4 = waypoint_List.waypoints[i - 1].param4;

		enu_waypoint_List.waypoints[i].x_lat = enu_waypoint_List.waypoints[i-1].x_lat + enu_offset.x();

		enu_waypoint_List.waypoints[i].y_long = enu_waypoint_List.waypoints[i-1].y_long + enu_offset.y();

#ifdef _USE_THREE_DIMENSION_VF_
        enu_waypoint_List.waypoints[i].z_alt = waypoint_List.waypoints[i - 1].z_alt;
#else
		enu_waypoint_List.waypoints[i].z_alt = enu_waypoint_List.waypoints[i-1].z_alt + enu_offset.z();
#endif


        singleENUWaypointListLog(enu_waypoint_List.waypoints[i]);
        singleGPSWaypointListLog(waypoint_List.waypoints[i-1]);
	}

    // 添加 home 点到最后一个位置
    enu_waypoint_List.waypoints.push_back(mavros_msgs::Waypoint());
	enu_waypoint_List.waypoints[i].command = MAV_CMD_NAV_LOITER_UNLIM;
	enu_waypoint_List.waypoints[i].x_lat = enu_waypoint_List.waypoints[0].x_lat;
	enu_waypoint_List.waypoints[i].y_long = enu_waypoint_List.waypoints[0].y_long;
	enu_waypoint_List.waypoints[i].z_alt = enu_waypoint_List.waypoints[0].z_alt;
    enu_waypoint_List.waypoints[i].param3 = 30;
    
    singleENUWaypointListLog(enu_waypoint_List.waypoints[i]);
    singleGPSWaypointListLog(waypoint_List.waypoints[i-1]);

    new_previous_sq = 0;
    new_current_sq = 1;
    cout << "new_current_sq: " << new_current_sq << endl;
    cout << "new_previous_sq: " << new_previous_sq << endl;
}

void NavigatorSubAndPub::publishPositionTriplet(){
    ROS_ERROR("start navigator publishPositionTriplet ...");
    position_setpoint_triplet_pub.publish(position_setpoint);
}
