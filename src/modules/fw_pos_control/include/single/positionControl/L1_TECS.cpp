#include "L1_TECS.hpp"

L1_TECS::L1_TECS(){
    begin_time = ros::Time::now(); // 记录启控时间
}
void L1_TECS::dataConfirguration(mavros_msgs::Waypoint waypoint, float airspeed){

    vehicle_setpoint.air_speed = airspeed;          // 17

    vehicle_setpoint.altitude = waypoint.z_alt + 50;
    vehicle_setpoint.latitude = waypoint.x_lat;
    vehicle_setpoint.longtitude = waypoint.y_long;
}

void L1_TECS::run(
    mavros_msgs::Waypoint waypoint,             // 目标航点
    sensor_msgs::NavSatFix global_position,     // 全局位置
    geometry_msgs::TwistStamped velocity_ned,   // ned 的速度
    sensor_msgs::Imu imu_,                      // imu_ 的速度
    geometry_msgs::TwistWithCovarianceStamped wind_estimate,    // 风的预估
    mavros_msgs::VFR_HUD air_ground_speed,      // 空速和地速度
    float airspeed                              // 17 常数         
){
    /* 1. configuration */ 
    setImu(imu_);
    setVelocityNed(velocity_ned);
    setWindEstimate(wind_estimate);
    setGlobalPosition(global_position);
    setAirGroundSpeed(air_ground_speed);

    // 把位置信息给 到 l1 和 tecs 
    dataConfirguration(waypoint, airspeed);

    // 2. TECS ==> vehicle_setpoint.pitch_angle; vehicle_setpoint.thrust
    current_time = get_ros_time(begin_time);
    control_vertical(current_time);

    // 3. L1 ==> vehicle_setpoint.roll_angle
    current_time = get_ros_time(begin_time);
    control_lateral(current_time); 
}
float L1_TECS::get_ros_time(ros::Time begin) // 1
{
    ros::Time time_now = ros::Time::now();
    float currTimeSec = time_now.sec - begin.sec;
    float currTimenSec = time_now.nsec / 1e9 - begin.nsec / 1e9;
    return (currTimeSec + currTimenSec);
}
void L1_TECS::control_vertical(float current_time)
{
    //不同模式切换的时候需要进行重置tecs
    control_mode_current = vehicle_status.mode;

    //从领机状态获得飞机的期望高度与期望空速
    if (control_mode_current != control_mode_prev)
    {
        _tecs.reset_state();
    }

    //设置参数,真实的飞机还需要另外调参
    _tecs.set_speed_weight(params.speed_weight);
    _tecs.set_time_const_throt(params.time_const_throt); //这个值影响到总能量-》油门的（相当于Kp，他越大，kp越小）
    _tecs.set_time_const(params.time_const);             //这个值影响到能量分配-》俯仰角他越大，kp越小
    _tecs.enable_airspeed(true);

    if (vehicle_setpoint.altitude - vehicle_status.altitude >= 5) //判断一下是否要进入爬升
    {
        params.climboutdem = true;
    }
    else
    {
        params.climboutdem = false;
    }
    ROS_ERROR("show the information: ");
    cout << "vehicle vehicle_status airspeed: " << vehicle_status.air_speed << endl;
    cout << "vehicle vehicle_status rotmat: (" << vehicle_status.rotmat[0][1] << ", " << vehicle_status.rotmat[0][0] << ", " << vehicle_status.rotmat[0][2] << ")" << endl;

    _tecs.update_state(current_time, vehicle_status.altitude,
                       vehicle_status.air_speed, vehicle_status.rotmat,
                       vehicle_status.body_acc, vehicle_status.ned_acc, vehicle_status.altitude_lock, vehicle_status.in_air);
    ROS_ERROR("show the vehicle_status: ");
    cout << "vehicle_status altitude: " << vehicle_setpoint.air_speed << endl;
    cout << "vehicle_status pitch_angle: " << vehicle_status.pitch_angle << endl;
    
    cout << "params: " << params.EAS2TAS << endl;
    cout << "params climboutdem: " << params.climboutdem << endl;
    cout << "params: " << params.climbout_pitch_min_rad << endl;
    cout << "params: " << params.throttle_min << endl;

    cout << "params: " << params.throttle_max << endl;
    cout << "params: " << params.throttle_cruise << endl;
    cout << "params: " << params.pitch_min_rad << endl;
    cout << "params: " << params.pitch_max_rad << endl;

    cout << "current_time: " << current_time << endl;  // e+09
    _tecs.update_pitch_throttle(current_time, 
                                vehicle_status.rotmat, vehicle_status.pitch_angle,
                                vehicle_status.altitude, 
                                vehicle_setpoint.altitude, vehicle_setpoint.air_speed,
                                vehicle_status.air_speed, 
                                params.EAS2TAS, params.climboutdem,
                                params.climbout_pitch_min_rad, params.throttle_min, params.throttle_max,
                                params.throttle_cruise, params.pitch_min_rad, params.pitch_max_rad);

    // _tecs.get_tecs_state(tecs_outputs); // 这个是状态，可以作为调试的窗口用

    vehicle_setpoint.pitch_angle = _tecs.get_pitch_demand(); //添加负号保证,
    vehicle_setpoint.thrust = _tecs.get_throttle_demand();

    control_mode_prev = control_mode_current;
}

Point L1_TECS::get_local_planar_vector(Point origin, Point target)
{
    /* this is an approximation for small angles, proposed by [2] */
    Point out(deg_2_rad((target.x - origin.x)), deg_2_rad((target.y - origin.y) * cosf(deg_2_rad(origin.x))));

    return out * double(CONSTANTS_RADIUS_OF_EARTH);
}

// * 输入: 僚机的当前位置, 地速(x, y, z), 空速, 掌机 给定的期望位置点  == > 这个期望位置是计算得到的
// * 输出: roll setpoint
float L1_TECS::lateral_L1_modified(Point curr_pos, Point sp_pos, Point ground_speed_2d)
{
    float eta;
    float xtrack_vel;
    float ltrack_vel;

    Point vector_curr_position = curr_pos;
    Point vector_A = sp_pos; // 期望位置设定值

    float ground_speed = max(ground_speed_2d.len(), 0.1f);

    _L1_distance = _L1_ratio * ground_speed;

    // 当前位置到期望位置之间的向量
    Point vector_A_to_airplane = get_local_planar_vector(vector_A, vector_curr_position);

    /* unit vector from waypoint A to current position */
    // 当前位置到期望位置的方向向量
    Point vector_A_to_airplane_unit = vector_A_to_airplane.normalized();

    /* velocity across(交叉) / orthogonal(正交) to line */
    xtrack_vel = ground_speed_2d ^ (-vector_A_to_airplane_unit);  // 叉积  a * b * sin(etha)

    /* velocity along line 沿线的速度 */
    ltrack_vel = ground_speed_2d * (-vector_A_to_airplane_unit);  // 点积  a * b * cos{etha}

    // 地速度和期望方向的夹角
    eta = atan2f(xtrack_vel, ltrack_vel);
    /* bearing from current position to L1(当前位置和期望位置之间的连线距离) point */
    _nav_bearing = atan2f(-vector_A_to_airplane_unit.y, -vector_A_to_airplane_unit.x);

    /* limit angle to +-90 degrees */
    eta = constrain(eta, (-PI) / 2.0f, +PI / 2.0f);
    /* 计算切向加速度 */
    _lateral_accel = _K_L1 * ground_speed * ground_speed / _L1_distance * sinf(eta);  // 0.4 * Vg * sin(eta): 将速度投影到方向上, 取 0.4 倍

    // 得到期望roll值, 后面是一些规范化
    float ret = atanf(_lateral_accel * 1.0f / CONSTANTS_ONE_G);

    // -deg_2_rad(60), deg_2_rad(60)
    ret = constrain(ret, -_roll_lim_rad, _roll_lim_rad);

    // PI / 2
    float roll_ang = constrain(ret, -params.roll_max, params.roll_max);

    return roll_ang;
}

void L1_TECS::control_lateral(float current_time)
{
    Point curr_pos(vehicle_status.latitude, vehicle_status.longtitude);         // vehical 的经纬度
    Point sp_pos(vehicle_setpoint.latitude, vehicle_setpoint.longtitude);       // vehical 经纬度的设定值
    Point ground_speed_2d(vehicle_status.ned_vel_x, vehicle_status.ned_vel_y);  // vehical 的ned 速度的 x 和 y
    // _l1_control.navigate_waypoints(prev_wp, curr_wp, curr_pos, nav_speed_2d);
    vehicle_setpoint.roll_angle = lateral_L1_modified(curr_pos, sp_pos, ground_speed_2d);
}

/*  subscriber */
void L1_TECS::setGlobalPosition(const sensor_msgs::NavSatFix msg)
{
    global_position_form_px4 = msg;
    vehicle_status.latitude = global_position_form_px4.latitude;
    vehicle_status.longtitude = global_position_form_px4.longitude;
    vehicle_status.altitude = global_position_form_px4.altitude;
}

void L1_TECS::setImu(const sensor_msgs::Imu msg)
{
    imu = msg;
   
    q[0] = msg.orientation.w;
    q[1] = msg.orientation.x;
    q[2] = msg.orientation.y;
    q[3] = msg.orientation.z;

    
    quaternion_2_euler(q, att_angle_Euler);

    vehicle_status.roll_angle = att_angle_Euler[0];
    vehicle_status.pitch_angle = -att_angle_Euler[1];

    if (att_angle_Euler[2] + deg_2_rad(90.0) > 0)
        vehicle_status.yaw_angle = att_angle_Euler[2] + deg_2_rad(90.0); //添加符号使增加方向相同，而且领先于px490°
    else
        vehicle_status.yaw_angle = att_angle_Euler[2] + deg_2_rad(90.0) + deg_2_rad(360.0);
    
    update_rotmat();

    vehicle_status.body_acc[0] = imu.linear_acceleration.x;
    vehicle_status.body_acc[1] = imu.linear_acceleration.y;
    vehicle_status.body_acc[2] = imu.linear_acceleration.z;

    // 为 vehicle_status.ned_acc 赋值
    matrix_plus_vector_3(vehicle_status.ned_acc, vehicle_status.rotmat, vehicle_status.body_acc);
}

void L1_TECS::update_rotmat() // 1
{
    float angle[3], quat[4];

    angle[0] = vehicle_status.roll_angle;
    angle[1] = vehicle_status.pitch_angle;
    angle[2] = vehicle_status.yaw_angle;

    euler_2_quaternion(angle, quat);

    quat_2_rotmax(quat, vehicle_status.rotmat);
}
void L1_TECS::setVelocityNed(const geometry_msgs::TwistStamped msg)
{
    velocity_ned_fused_from_px4 = msg;
    vehicle_status.ned_vel_x = velocity_ned_fused_from_px4.twist.linear.y;
    vehicle_status.ned_vel_y = velocity_ned_fused_from_px4.twist.linear.x;
    vehicle_status.ned_vel_z = velocity_ned_fused_from_px4.twist.linear.z;
}
void L1_TECS::setAirGroundSpeed(const mavros_msgs::VFR_HUD msg)
{
    air_ground_speed_from_px4 = msg;

    vehicle_status.air_speed = air_ground_speed_from_px4.airspeed;
    vehicle_status.ground_speed = air_ground_speed_from_px4.groundspeed;
    
}
void L1_TECS::setWindEstimate(const geometry_msgs::TwistWithCovarianceStamped msg)
{
    wind_estimate_from_px4 = msg;

    vehicle_status.wind_estimate_x = wind_estimate_from_px4.twist.twist.linear.y;
    vehicle_status.wind_estimate_y = wind_estimate_from_px4.twist.twist.linear.x;
    vehicle_status.wind_estimate_z = wind_estimate_from_px4.twist.twist.linear.z;
}

// void L1_TECS::setAirGroundSpeed(const mavros_msgs::VFR_HUD msg)
// {
//     air_ground_speed_from_px4 = msg;

//     vehicle_status.air_speed = air_ground_speed_from_px4.airspeed;
//     vehicle_status.ground_speed = air_ground_speed_from_px4.groundspeed;
    
// }
