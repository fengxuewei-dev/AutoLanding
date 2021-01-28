#include "PositionControl_VF.hpp"

PositionControl_VF::PositionControl_VF(){
    previous_waypoint.x_lat = 0.0f;
    previous_waypoint.y_long = 0.0f;
    previous_waypoint.z_alt = 0.0f;
    
    wayPointEnd.update(0, 0);
    wayPointStart.update(0, 0);
    currentPosition.update(0, 0);

    update_parameters();
}

PositionControl_VF::~PositionControl_VF(){
    param_save();
}
void PositionControl_VF::update_parameters(){
    param_load();
}
void PositionControl_VF::setPositionSetpoint( fw_msgs::position_setpoint_triplet position_sp ){
    position_setpoint = position_sp;
}

void PositionControl_VF::setTriplePoint(){
    // #ifdef _USE_THREE_DIMENSION_VF_
        std::cout << "执行 三维 VF 的航点位置信息赋值操作" << std::endl;
        TDVF_localPosition.update(
                current_local_position.pose.position.x, 
                current_local_position.pose.position.y, 
                current_local_position.pose.position.z
        );
        TDVF_wayPointStart.update(
            position_setpoint.enu_currentWaypoint.x_lat, 
            position_setpoint.enu_currentWaypoint.y_long, 
            position_setpoint.enu_currentWaypoint.z_alt
        );
        TDVF_wayPointEnd.update(
            position_setpoint.enu_nextWaypoint.x_lat, 
            position_setpoint.enu_nextWaypoint.y_long, 
            position_setpoint.enu_nextWaypoint.z_alt
        );
        currentPosition.update(
            current_local_position.pose.position.x, 
            current_local_position.pose.position.y
        );
        wayPointStart.update(
            position_setpoint.enu_currentWaypoint.x_lat, 
            position_setpoint.enu_currentWaypoint.y_long
        );
        wayPointEnd.update(
            position_setpoint.enu_nextWaypoint.x_lat, 
            position_setpoint.enu_nextWaypoint.y_long
        );
    // #else
        // currentPosition.update(current_local_position.pose.position.x, current_local_position.pose.position.y);
        // wayPointStart.update(position_setpoint.enu_currentWaypoint.x_lat, position_setpoint.enu_currentWaypoint.y_long);
        // wayPointEnd.update(position_setpoint.enu_nextWaypoint.x_lat, position_setpoint.enu_nextWaypoint.y_long);
    // #endif
}


// 这个函数是配合 TECS 来计算 yaw，所实现的逻辑为 书上的 公式 10.7
int PositionControl_VF::run_TECS(
    mavros_msgs::HomePosition homePosition,  
    geometry_msgs::PoseStamped currentLocalPosition, 
    mavros_msgs::VFR_HUD currentVFRHUD,
    fw_msgs::position_setpoint_triplet position_sp,
    float airspeed
){
    /* 1. confirguration */
    /* get the data about the UAV */
    home = homePosition;
    current_local_position = currentLocalPosition;
    current_vfr_hud = currentVFRHUD;
    Throttle = airspeed;

    setPositionSetpoint(position_sp);

    /* 2. Processing logic */ 
    setTriplePoint();
    Yaw = vectorField.getHeading_10_8(
		currentPosition,
		wayPointStart,
		wayPointEnd,
		M_PI/100.0,
		current_vfr_hud.heading * (M_PI / 180.0),
		current_vfr_hud.airspeed
	)-(M_PI/2.0); // chi_c

    /* 3. update the previous_waypoint for calculating the enu waypoint */
    previous_waypoint = position_setpoint.currentWaypoint;

    return 0;
}


int PositionControl_VF::run(
    mavros_msgs::HomePosition homePosition,  
    geometry_msgs::PoseStamped currentLocalPosition, 
    mavros_msgs::VFR_HUD currentVFRHUD,
    fw_msgs::position_setpoint_triplet position_sp,
    sensor_msgs::Imu imu,
    float airspeed
){
    /* 1. confirguration */
    /* get the data about the UAV */
    current_imu = imu;
    home = homePosition;
    current_local_position = currentLocalPosition;
    current_vfr_hud = currentVFRHUD;
    Throttle = airspeed;

    setPositionSetpoint(position_sp);

    /* 2. Processing logic */ 
    ChooseHandler();

    /* 3. update the previous_waypoint for calculating the enu waypoint */
    previous_waypoint = position_setpoint.enu_currentWaypoint;

    return 0;
}

void PositionControl_VF::ChooseHandler(){
    POSITIONCONTROLLER("进入选择执行逻辑的函数内部");

    if( position_setpoint.enu_currentWaypoint.command != LOITERING_TIME && 
        position_setpoint.enu_currentWaypoint.command != LOITER_UNLIM){  // 当前要执行的航点任务
        if(position_setpoint.ExistNext) 
        {   
            setTriplePoint();
            straight_();
        } 
        else{
            POSITIONCONTROLLER("1");
            setRadius(RADIUS_DEFAULTS); // 最后的航点盘旋半径为 200
            currentPosition.update(
                current_local_position.pose.position.x, 
                current_local_position.pose.position.y
            );
            orbit_();
        }
    }
    else if( position_setpoint.enu_currentWaypoint.command == LOITERING_TIME &&
        position_setpoint.enu_currentWaypoint.command != LOITER_UNLIM){ // 当前航点是loiter
        if(position_setpoint.ExistNext) // loiter 存在下一个航点
        {
            setTriplePoint();
            
            setRadius(position_setpoint.enu_currentWaypoint.param3); 

            orbit_();       // 巡航任务的半径跟着航点的信息走的
        }
        else{
            setRadius(RADIUS_DEFAULTS);
            currentPosition.update(
                current_local_position.pose.position.x, 
                current_local_position.pose.position.y
            );
            orbit_();
        }
    }
    else if(position_setpoint.enu_currentWaypoint.command != LOITERING_TIME &&
        position_setpoint.enu_currentWaypoint.command == LOITER_UNLIM){
        
        setRadius(position_setpoint.enu_currentWaypoint.param3); 
        currentPosition.update(
            current_local_position.pose.position.x, 
            current_local_position.pose.position.y
        );
        POSITIONCONTROLLER("4");
        orbit_();
    }
}

void PositionControl_VF::straight_(){
    POSITIONCONTROLLER("进入VF的直线控制逻辑");
    vectorField.getEuler(current_imu, psi, theta, phi);        // get radians
    vectorField.getErrorXYZ( 
        TDVF_localPosition,
        TDVF_wayPointStart,
        TDVF_wayPointEnd,
        horizontalDistance,
        verticalDistance
    ); // 计算三维的距离误差 
    vectorField.getMAV_side( 
        TDVF_localPosition,
        TDVF_wayPointStart,
        TDVF_wayPointEnd,
        horizontalSide,
        verticalSide
    ); // 计算水平平面上和垂直平面上无人机的位置
    
    verticalSide = verticalDistance > 0 ? -1 : 1;

	Yaw = vectorField.getHeading(   // 水平上的
		currentPosition,
		wayPointStart,
		wayPointEnd,
		M_PI/100.0, 
		psi,                    // 调节 3D VF 的时候改动
        theta,
		current_vfr_hud.airspeed
        , horizontalDistance
        , horizontalSide
	)-(M_PI/2.0); 

#ifdef _USE_THREE_DIMENSION_VF_

    Pitch = vectorField.getPitch(
        TDVF_localPosition,
        TDVF_wayPointStart,
        TDVF_wayPointEnd,
		current_vfr_hud.groundspeed,
        theta,
        psi
        , abs(verticalDistance)
        , verticalSide
    );

#endif 

}

void PositionControl_VF::ThreeDVF_run(){
    POSITIONCONTROLLER("进入三维 VF 的控制逻辑");
    double psi;
    double phi;
    TDVF.getEuler(
        current_imu,
        psi,
        phi
    );
    TDVF.THREEDVF(
		TDVF_wayPointStart,
		TDVF_wayPointEnd,
		TDVF_localPosition,
		psi,
        phi,
		current_vfr_hud.airspeed
    );
}

void PositionControl_VF::orbit_(){
    POSITIONCONTROLLER("进入VF的盘旋控制逻辑");
	Yaw = vectorField.getHeadingOrbit(
		currentPosition, 
		Point(position_setpoint.enu_currentWaypoint.x_lat,position_setpoint.enu_currentWaypoint.y_long),
		fabs(radius), 
		current_vfr_hud.groundspeed, 
		(-current_vfr_hud.heading)/(M_PI/2.0),
        radius > 0 ? 1.0f : -1.0f,
		current_vfr_hud.airspeed
	)-(M_PI/2.0);

}

void PositionControl_VF::getENUoffset(mavros_msgs::Waypoint startlistposition, mavros_msgs::Waypoint endlistposition, Eigen::Vector3d* enu_offset){
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

void PositionControl_VF::setRadius(int R){
    radius = R;
}
float PositionControl_VF::getPitch(){
#ifdef _USE_THREE_DIMENSION_VF_
    return Pitch;
    // std::cout << "获取 3D vf 的 pitch 设定值" << std::endl;

    // return TDVF.getPitch_sp();
#else
    return position_setpoint.enu_nextWaypoint.z_alt;
#endif
}
float PositionControl_VF::getYaw(){
    return Yaw; 
}
float PositionControl_VF::getThrottle(){
    Throttle = getLongiThrottle(static_cast<double>(GROUNDSPEED_DESIRED));
    return Throttle;
}
// float PositionControl_VF::getLongiThrottle(
//     double S_groundSpeed
// ){
//     double i_p = 1.5;
//     double i_i = 1.5;
//     double X_e = S_groundSpeed - current_vfr_hud.groundspeed;
//     std::cout << "S_groundSpeed: " << S_groundSpeed << std::endl;
//     std::cout << "current_vfr_hud.groundspeed: " << current_vfr_hud.groundspeed << std::endl;
//     PrevErr += X_e;
//     double groundSpeedSetpoint = i_p * X_e + S_groundSpeed + i_i *  PrevErr;
//     return groundSpeedSetpoint;
// }

float PositionControl_VF::getLongiThrottle( double S_groundSpeed){

    Err = S_groundSpeed - current_vfr_hud.groundspeed;
    std::cout << "速度偏差：　" << Err << std::endl;
    
    double param_p = kp * Err;
    double param_i = ki * (Err - PrevErr);
    double param_d = kd * (Err - 2 * PrevErr + Prev2Err);

    double groundSpeedSetpoint = current_vfr_hud.groundspeed 
        + param_p    
        + param_i 
        + param_d;

    Prev2Err = PrevErr;
    PrevErr = Err;
    return groundSpeedSetpoint;
}
