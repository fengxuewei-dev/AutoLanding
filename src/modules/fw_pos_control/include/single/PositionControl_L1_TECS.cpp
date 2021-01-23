#include "PositionControl_L1_TECS.hpp"

PositionControl_L1_TECS::PositionControl_L1_TECS(){
    roll = 0;
    pitch = 0;
    yaw = 0;
}
/*
 Control_L1_TECS.run(
        position_setpoint.nextWaypoint, 
        global_position_form_px4, 
        velocity_ned_fused_from_px4, 
        imu, 
        wind_estimate_from_px4, 
        current_UAV_state, 
        airspeed_tecs
    );
*/
int PositionControl_L1_TECS::run(
    mavros_msgs::Waypoint waypoint,             // 目标航点
    sensor_msgs::NavSatFix global_position,     // 全局位置
    geometry_msgs::TwistStamped velocity_ned,   
    sensor_msgs::Imu imu_,
    geometry_msgs::TwistWithCovarianceStamped wind_estimate,
    mavros_msgs::VFR_HUD air_ground_speed,      // 空速和地速度
    float airspeed                              // 17 常数         
){
    ROS_ERROR("Run the l1 and tecs");
    l1_tecs.run(
        waypoint, 
        global_position, 
        velocity_ned, 
        imu_, 
        wind_estimate, 
        air_ground_speed, 
        airspeed
    );
    return 0;
}
float PositionControl_L1_TECS::getRoll(){
    return l1_tecs.vehicle_setpoint.roll_angle;
}
float PositionControl_L1_TECS::getPitch(){
    return -l1_tecs.vehicle_setpoint.pitch_angle;
}
float PositionControl_L1_TECS::getYaw(){
    return -l1_tecs.vehicle_setpoint.yaw_angle + deg_2_rad(90.0);                // 0 + PI/2
}
float PositionControl_L1_TECS::getThrottle(){
    return l1_tecs.vehicle_setpoint.thrust;
}
