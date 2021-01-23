#include "FixedwingPositionSubAndPub.hpp"

FixedwingPositionSubAndPub::FixedwingPositionSubAndPub(std::string uavName_){
    uavName = uavName_;

    isRC = false;
    isSingleFly = false;
    isSelfOrganization = false;
    logConfig();

    for(size_t i = 0; i < 4; i++)
    {
        att_sp[i] = 0;
    }
    
    /* receive the data from the udp */ 
    formationPosition_sub = nh.subscribe<fw_msgs::FormationPositionContoller>
            (uavName + "communication/formationData/positionController", 1, boost::bind(&FixedwingPositionSubAndPub::formationPositionData_cb, this, _1));
    
    /* receive the data from the navigator */ 
    position_setpoint_triplet_sub = nh.subscribe<fw_msgs::position_setpoint_triplet>
            (uavName + "navigator/position_sp_triplet", 1, boost::bind(&FixedwingPositionSubAndPub::navigator_position_cb, this, _1));

    home_sub = nh.subscribe<mavros_msgs::HomePosition> 
            (uavName + "msgsFromPx4/home_position/home", 1, boost::bind(&FixedwingPositionSubAndPub::homePosition_cb, this, _1));
            
    uav_state_sub = nh.subscribe<mavros_msgs::VFR_HUD>  
            (uavName + "msgsFromPx4/vfr_hud", 1, boost::bind(&FixedwingPositionSubAndPub::newUAVState, this, _1));
    uav_localPos_sub = nh.subscribe<geometry_msgs::PoseStamped>
            (uavName + "msgsFromPx4/local_position/pose",1,boost::bind(&FixedwingPositionSubAndPub::new_localPose, this, _1));
    uav_globelPos_sub = nh.subscribe<sensor_msgs::NavSatFix>
            (uavName + "msgsFromPx4/global_position/global", 1, boost::bind(&FixedwingPositionSubAndPub::global_position_form_px4_cb, this, _1));

    uav_localVel_sub = nh.subscribe<geometry_msgs::TwistStamped>
            (uavName + "msgsFromPx4/local_position/velocity_local", 1, boost::bind(&FixedwingPositionSubAndPub::velocity_ned_fused_from_px4_cb, this, _1));

    uav_imu_sub = nh.subscribe<sensor_msgs::Imu>
            (uavName + "msgsFromPx4/imu/data", 1, boost::bind(&FixedwingPositionSubAndPub::imu_cb, this, _1));

    uav_windEstimation_sub = nh.subscribe<geometry_msgs::TwistWithCovarianceStamped>
            (uavName + "msgsFromPx4/wind_estimation", 1, boost::bind(&FixedwingPositionSubAndPub::wind_estimate_from_px4_cb, this, _1));

    uav_localAccel_sub = nh.subscribe<geometry_msgs::AccelWithCovarianceStamped> //
            (uavName + "msgsFromPx4/local_position/accel", 1, boost::bind(&FixedwingPositionSubAndPub::acc_ned_from_px4_cb, this, _1));
    
    uavflag_sub = nh.subscribe<fw_msgs::uavflag> 
            (uavName + "processer/uavflag", 10, boost::bind(&FixedwingPositionSubAndPub::uavflag_cb, this, _1));
            
    /* send the data to the attitude controller */
    att_sp_pub = nh.advertise<fw_msgs::commands>
            (uavName + "attitudeControl/commands", 1);

	formationShap_pub = nh.advertise<fw_msgs::formations>
            (uavName + "formationControl/formationShap",1);

    formationYaw_pub = nh.advertise<fw_msgs::Yaw>
            (uavName + "communication/yaw",1);

    uav_velocity_global_fused = nh.subscribe<geometry_msgs::TwistStamped>
        (uavName + "msgsFromPx4/global_position/raw/gps_vel", 1, boost::bind(&FixedwingPositionSubAndPub::velocity_global_fused_cb, this, _1));

}
FixedwingPositionSubAndPub::~FixedwingPositionSubAndPub(){}

void FixedwingPositionSubAndPub::imu_cb(const sensor_msgs::Imu::ConstPtr &msg)
{
    imu = *msg;
    float q[4];
    q[0] = msg->orientation.w;
    q[1] = msg->orientation.x;
    q[2] = msg->orientation.y;
    q[3] = msg->orientation.z;

    // att_angle_Euler: roll, pitch, yaw
    quaternion_2_euler(q, att_angle_Euler);
}

void FixedwingPositionSubAndPub::setUavName(std::string uavName_){
    uavName = uavName_;
}

std::string FixedwingPositionSubAndPub::getUavName(){
    return uavName;
}
void FixedwingPositionSubAndPub::logConfig(){
    log_subscribe_currentWaypoint_x.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/subscribe",  "gps_currentWaypoint", "x");
    log_subscribe_currentWaypoint_y.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/subscribe",  "gps_currentWaypoint", "y");
    log_subscribe_currentWaypoint_z.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/subscribe",  "gps_currentWaypoint", "z");
    log_subscribe_nextWaypoint_x.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/subscribe",  "gps_nextWaypoint", "x");
    log_subscribe_nextWaypoint_y.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/subscribe",  "gps_nextWaypoint", "y");
    log_subscribe_nextWaypoint_z.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/subscribe",  "gps_nextWaypoint", "z");

    log_subscribe_enu_currentWaypoint_x.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/subscribe",  "enu_currentWaypoint", "x");
    log_subscribe_enu_currentWaypoint_y.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/subscribe",  "enu_currentWaypoint", "y");
    log_subscribe_enu_currentWaypoint_z.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/subscribe",  "enu_currentWaypoint", "z");
    log_subscribe_enu_nextWaypoint_x.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/subscribe",  "enu_nextWaypoint", "x");
    log_subscribe_enu_nextWaypoint_y.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/subscribe",  "enu_nextWaypoint", "y");
    log_subscribe_enu_nextWaypoint_z.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/subscribe",  "enu_nextWaypoint", "z");

    log_subscribe_Throttle.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/subscribe",  "Throttle");
    log_subscribe_ExistNext.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/subscribe",  "ExistNext");
    
    log_publish_roll_setpoint.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/publish",  "roll", "setpoint");
    log_publish_yaw_setpoint.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/publish",  "yaw", "setpoint");
    log_publish_pitch_setpoint.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/publish",  "pitch", "setpoint");
    log_publish_throttle_setpoint.configuration
        (string(LOGGERPATH) + "/" + uavName + "position_controller/publish",  "throttle", "setpoint");
}
void FixedwingPositionSubAndPub::WriteLogFile_Subscribe(){
    log_subscribe_currentWaypoint_x.logPrint(position_setpoint.currentWaypoint.x_lat);
    log_subscribe_currentWaypoint_y.logPrint(position_setpoint.currentWaypoint.y_long);
    log_subscribe_currentWaypoint_z.logPrint(position_setpoint.currentWaypoint.z_alt);

    log_subscribe_nextWaypoint_x.logPrint(position_setpoint.nextWaypoint.x_lat);
    log_subscribe_nextWaypoint_y.logPrint(position_setpoint.nextWaypoint.y_long);
    log_subscribe_nextWaypoint_z.logPrint(position_setpoint.nextWaypoint.z_alt);
    
    log_subscribe_enu_currentWaypoint_x.logPrint(position_setpoint.enu_currentWaypoint.x_lat);
    log_subscribe_enu_currentWaypoint_y.logPrint(position_setpoint.enu_currentWaypoint.y_long);
    log_subscribe_enu_currentWaypoint_z.logPrint(position_setpoint.enu_currentWaypoint.z_alt);

    log_subscribe_enu_nextWaypoint_x.logPrint(position_setpoint.enu_nextWaypoint.x_lat);
    log_subscribe_enu_nextWaypoint_y.logPrint(position_setpoint.enu_nextWaypoint.y_long);
    log_subscribe_enu_nextWaypoint_z.logPrint(position_setpoint.enu_nextWaypoint.z_alt);

    log_subscribe_ExistNext.logPrint(int(position_setpoint.ExistNext));
    log_subscribe_Throttle.logPrint(int(position_setpoint.Throttle));
}
void FixedwingPositionSubAndPub::WriteLogFile_Publish(){
    log_publish_pitch_setpoint.logPrint(setCommands.pitch);
    log_publish_roll_setpoint.logPrint(setCommands.roll);
    log_publish_yaw_setpoint.logPrint(setCommands.yaw);
    log_publish_throttle_setpoint.logPrint(setCommands.throttle);
}
void FixedwingPositionSubAndPub::uavflag_cb(const fw_msgs::uavflag::ConstPtr& msg){
    uavflag_state = *msg;
}
void FixedwingPositionSubAndPub::velocity_global_fused_cb(const geometry_msgs::TwistStamped::ConstPtr &msg){
    velocity_global_fused_from_px4 = *msg;
}
void FixedwingPositionSubAndPub::formationPositionData_cb(const fw_msgs::FormationPositionContoller::ConstPtr& msg){
    formationPosition = *msg;
}

void FixedwingPositionSubAndPub::print_navi_setpoint(){
    cout << "from the navigator: " << endl;
    cout << "position_setpoint.Throttle: " << +position_setpoint.Throttle << endl;
    cout << "position_setpoint.ExistNext: " << +position_setpoint.ExistNext << endl;
    if(!isRC){
        POSITIONCONTROLLER("OFFBOARD 模式, 接收到的航点信息(需要GPS和ENU)的如下: ");
        std::cout << " ------------ GPS ---------- " << std::endl;
        print_wp(position_setpoint.currentWaypoint);
        print_wp(position_setpoint.nextWaypoint);
    }
    else
        POSITIONCONTROLLER("RC 模式下, 接收到的航线信息(只需要ENU的数据)如下: ");
    std::cout << " ------------ ENU ---------- " << std::endl;
    print_wp(position_setpoint.enu_currentWaypoint);
    print_wp(position_setpoint.enu_nextWaypoint);
    cout << endl;
}
void FixedwingPositionSubAndPub::print_wp(const mavros_msgs::Waypoint& wp)
{
    ROS_INFO("waypoint: x_lat = %f y_long = %f z_alt = %f ", wp.x_lat,wp.y_long,wp.z_alt);
    ROS_INFO("command = %d frame = %d autocontinue = %d ",wp.command,wp.frame,wp.autocontinue);
    ROS_INFO("param:%f %f %f %f", wp.param1,wp.param2,wp.param3,wp.param4);
}
void FixedwingPositionSubAndPub::printInfo(){
    print_navi_setpoint();
    int i = 0;
    cout << ++i <<  "altitude: " << global_position_form_px4.altitude << endl;
    cout << ++i <<  "longtitude: " << global_position_form_px4.longitude << endl;
    cout << ++i <<  "latitude: " << global_position_form_px4.latitude<< endl;
    cout << ++i <<  "velocity: " << velocity_ned_fused_from_px4.twist.angular.x << endl;

    cout << ++i <<  "imu: " << imu.header.seq << endl;
    cout << ++i <<  " wind : " << wind_estimate_from_px4.header.seq << endl;
    cout << ++i <<  "current_uav_state" << current_UAV_state.groundspeed << endl;
    cout <<  ++i << "acc: " << acc_ned_from_px4.accel.accel.angular.x << endl;
}
void FixedwingPositionSubAndPub::navigator_position_cb(const fw_msgs::position_setpoint_triplet::ConstPtr& msg){
    position_setpoint = *msg;
    WriteLogFile_Subscribe();
}
// void FixedwingPositionSubAndPub::state_cb(const mavros_msgs::State::ConstPtr& msg){
//     current_state = *msg;
// }

void FixedwingPositionSubAndPub::newUAVState(const mavros_msgs::VFR_HUD::ConstPtr& msg){   
    current_UAV_state = *msg;
}

void FixedwingPositionSubAndPub::new_localPose(const geometry_msgs::PoseStamped::ConstPtr& msg){
    current_localPose = *msg;
}

void FixedwingPositionSubAndPub::global_position_form_px4_cb(const sensor_msgs::NavSatFix::ConstPtr &msg)
{
    global_position_form_px4 = *msg;
}

void FixedwingPositionSubAndPub::acc_ned_from_px4_cb(const geometry_msgs::AccelWithCovarianceStamped::ConstPtr &msg)
{
    acc_ned_from_px4 = *msg;
}

void FixedwingPositionSubAndPub::velocity_ned_fused_from_px4_cb(const geometry_msgs::TwistStamped::ConstPtr &msg)
{
    velocity_ned_fused_from_px4 = *msg;    
}
void FixedwingPositionSubAndPub::wind_estimate_from_px4_cb(const geometry_msgs::TwistWithCovarianceStamped::ConstPtr &msg)
{ 
    // 控制单元对风的评估
    wind_estimate_from_px4 = *msg;
}
void FixedwingPositionSubAndPub::homePosition_cb(const mavros_msgs::HomePosition::ConstPtr& msg){
    current_home = *msg;
}
void FixedwingPositionSubAndPub::publish_2_udp_send(float yaw_){
    formationYaw.yaw = yaw_;
    formationYaw_pub.publish(formationYaw);
}
void FixedwingPositionSubAndPub::get_single_attitude_setpoints(){
    POSITIONCONTROLLER("执行vf控制逻辑");
    Control_VF.run(current_home, current_localPose, current_UAV_state, position_setpoint, imu, airspeed_single);

    att_sp[PITCH_NUMBER] = Control_VF.getPitch();
    att_sp[THROTTLE_NUMBER] = Control_VF.getThrottle();
    att_sp[YAW_NUMBER] = Control_VF.getYaw();
    att_sp[ROLL_NUMBER] = Control_VF.getYaw();

    publish_2_udp_send(Control_VF.getYaw());
}
void FixedwingPositionSubAndPub::get_formation_attitude_setpoints(){
    Control_FORMATION.run(
        position_setpoint.enu_nextWaypoint, current_UAV_state, current_localPose,
        formationPosition.leaderHeading, 
        formationPosition.leaderCommand_yaw, 
        formationPosition.leaderAirspeed 
    );
    
    att_sp[PITCH_NUMBER] = Control_FORMATION.getPitch();
    att_sp[THROTTLE_NUMBER] = Control_FORMATION.getThrottle();
    att_sp[YAW_NUMBER] = Control_FORMATION.getYaw();
    att_sp[ROLL_NUMBER] = Control_FORMATION.getYaw();

    publish_2_udp_send(Control_FORMATION.getYaw());
}
void FixedwingPositionSubAndPub::self_organization_setpoints(){
    ROS_ERROR("Organization controller >>>>> ");
    Control_FORMATION.run(
	position_setpoint.nextWaypoint, current_UAV_state, current_localPose,
        position_setpoint.selforgheading, 0, 25
    );

    att_sp[PITCH_NUMBER] = Control_FORMATION.getPitch();
    att_sp[THROTTLE_NUMBER] = Control_FORMATION.getThrottle();
    att_sp[YAW_NUMBER] = Control_FORMATION.getYaw();
    att_sp[ROLL_NUMBER] = Control_FORMATION.getYaw();


    publish_2_udp_send(Control_FORMATION.getYaw());
}
void FixedwingPositionSubAndPub::get_l1_tecs_attitude_setpoints(){
    
    Control_L1_TECS.run(
        position_setpoint.nextWaypoint, 
        global_position_form_px4, 
        velocity_ned_fused_from_px4, 
        imu, 
        wind_estimate_from_px4, 
        current_UAV_state, 
        airspeed_tecs
    );
    
    att_sp[PITCH_NUMBER] = Control_L1_TECS.getPitch();
    att_sp[THROTTLE_NUMBER] = Control_L1_TECS.getThrottle();
    att_sp[YAW_NUMBER] = Control_L1_TECS.getYaw();
    att_sp[ROLL_NUMBER] = Control_L1_TECS.getRoll();

    publish_2_udp_send(Control_L1_TECS.getYaw());
}

void FixedwingPositionSubAndPub::calculation(){
    if(isRC){ 
        if(isSingleFly)
        {
            get_single_attitude_setpoints(); 
        }
        else if(isSelfOrganization)
        {
            self_organization_setpoints();
        }
        else if(isFormationFly)
        {
            get_formation_attitude_setpoints(); 
        }
    }
    else
    {
        get_l1_tecs_attitude_setpoints(); // TECS
        getRollAndYaw();
    }
    // return 0;
}

// 切向加速度： a = v^2 / R = V * V/R = V * w(yaw的变化量)
// 角速度方向： 将右手的手指顺着转动的方向朝内弯曲， 大拇指的方向就是角速度的方向

// 全部的逻辑： 一直在打转
// 只是计算： chi_dot
float FixedwingPositionSubAndPub::calculationRoll(float yaw_sp){

    float roll_sp = 0.0f;
    double alpha = 0.4578; 
    // double alpha = 16; 
    double vf_yaw_dot = 0;

    vf_yaw_dot = alpha * (yaw_sp - M_PI / 180.0); // 初始值
    // vf_yaw_dot = alpha * (yaw_sp - deg_2_rad(current_UAV_state.heading)); // 初始值
    vf_yaw_dot = vf_yaw_dot * (current_UAV_state.groundspeed);
    
    float ret = atanf(vf_yaw_dot * 1.0f / CONSTANTS_ONE_G);
    ret = constrain(ret, -deg_2_rad(60), deg_2_rad(60));
    roll_sp = constrain(ret, -PI / 2, PI / 2); 

    return roll_sp;

    /*
    // 得到期望roll值, 后面是一些规范化
    double vf_yaw = yaw_sp;
    // double vf_yaw_differential = 0;

    // 计算微分
    vf_yaw_dot_init = alpha * (yaw_sp - deg_2_rad(current_UAV_state.heading)); // 初始值

    double vf_yaw_delta = vf_yaw - vf_yaw_previous;
    
    if(time == 1) // 第一次
    {
        vf_yaw_dot = vf_yaw_dot_init;
        time++;
    }
    else
    {
        vf_yaw_dot = vf_yaw_dot_previous + STEP * 2 * vf_yaw_delta; // fxw
        time++;
    }
    vf_yaw_dot = vf_yaw_dot * (current_UAV_state.groundspeed);
    float ret = vf_yaw_dot * 1.0f / CONSTANTS_ONE_G;

    ret = constrain(ret, -deg_2_rad(60), deg_2_rad(60));
    roll_sp = constrain(ret, -PI / 2, PI / 2); 
    */
    
}
void FixedwingPositionSubAndPub::getRollAndYaw(){
    // 在 offboard 分支下
    // 1. 根据 vf 获取 chi_dot,  包含当前的 heading 值(角度)
    Control_VF.run(current_home, current_localPose, current_UAV_state, position_setpoint, imu, airspeed_single);
    
    // 来自 TECS
    att_sp[PITCH_NUMBER] = Control_L1_TECS.getPitch();
    att_sp[THROTTLE_NUMBER] = Control_L1_TECS.getThrottle();
    att_sp[YAW_NUMBER] = Control_VF.getYaw();
    att_sp[ROLL_NUMBER] = getRollAndYaw_increment_pid(); // 反推的方法就不对
    // att_sp[ROLL_NUMBER] = getRollByYaw();
}
Point FixedwingPositionSubAndPub::get_plane_to_sp_vector(Point origin, Point target)
{
  Point out(deg_2_rad((target.x - origin.x)), deg_2_rad((target.y - origin.y) * cosf(deg_2_rad(origin.x))));

  return out * double(CONSTANTS_RADIUS_OF_EARTH);
}
float FixedwingPositionSubAndPub::getRollByYaw(){
    ROS_ERROR("<<<<<<<<<<<<<<<<< getRollByYaw >>>>>>>>>>>>> ");
    double yaw_dot = 0.0f;
    double alpha = 0.4578;
    double pitch_current = att_angle_Euler[1];  // 当前的pitch角度
    double roll_constrained_aimed = 0;          // px4中规范化之后, 需要的roll的值
    double roll_constrained = 0;                // 根据约束当前roll之后的值
    bool inverted = false;
    double ground_speed = 0.0f;

    // 规范 current_roll
    if (fabsf(att_angle_Euler[0]) < deg_2_rad(90.0f)) {
		/* not inverted, but numerically still potentially close to infinity */
		roll_constrained = constrain(att_angle_Euler[0], deg_2_rad(-80.0f), deg_2_rad(80.0f));

	} else { // 调换了
		inverted = true;

		// inverted flight, constrain on the two extremes of -pi..+pi to avoid infinity
		//note: the ranges are extended by 10 deg here to avoid numeric resolution effects
		if (att_angle_Euler[0] > 0.0f) {
			/* right hemisphere */
			roll_constrained = constrain(att_angle_Euler[0], deg_2_rad(100.0f), deg_2_rad(180.0f)); 

		} else {
			/* left hemisphere */
			roll_constrained = constrain(att_angle_Euler[0], deg_2_rad(-180.0f), deg_2_rad(-100.0f)); 
		}
	}
    
    // roll_constrained_aimed = constrain(roll_constrained, -fabsf(ctl_data.roll_setpoint), fabsf(ctl_data.roll_setpoint));

    ground_speed = current_UAV_state.groundspeed < 10 ? 10 : current_UAV_state.groundspeed;
    yaw_dot = alpha * (Control_VF.getYaw() - deg_2_rad(current_UAV_state.heading));
    roll_constrained_aimed = atanf(yaw_dot * ground_speed * 1.0f/ (CONSTANTS_ONE_G * cosf(pitch_current)));
    roll_constrained_aimed = constrain(roll_constrained_aimed, -M_PI/2, M_PI/2);
    
    std::cout << "roll_constrained_aimed: " << roll_constrained_aimed << std::endl;
    std::cout << "roll_constrained: " << roll_constrained << std::endl;

    return roll_constrained_aimed;
}
float FixedwingPositionSubAndPub::getRollAndYaw_increment_pid(){
    // 
    ROS_ERROR("<<<<<<<<<<<<<<<<< getRollAndYaw_increment_pid >>>>>>>>>>>>> ");
    double roll_out = 0.0f;
    double rollErrorDegree = 0.0f;
    double yaw_out = 0.0f;
    double KP_ROLL = 0.4578;
    // double KP_ROLL = 0.1;
    double ground_speed = 0.0f;
    double air_speed = 0.0f;

    std::cout << "getYaw(): " << Control_VF.getYaw() << std::endl;
    double yawErrorDegree = ((float)current_UAV_state.heading) + (Control_VF.getYaw() * (180.0/PI));   // error in degrees
	if(yawErrorDegree > 180)    yawErrorDegree-=360;
	if(yawErrorDegree < -180)   yawErrorDegree+=360;

    if(abs(yawErrorDegree) > 0) 
    {  
        std::cout << "roll control" << std::endl; // 1111
        yaw_out = -yawErrorDegree * KP_ROLL;
    }
    else{
        std::cout << "yaw control" << std::endl;
        yaw_out = yawErrorDegree*2;
    }

    ground_speed = current_UAV_state.groundspeed < 10 ? 10 : current_UAV_state.groundspeed;
    std::cout << "calculation: yaw_out: " << yaw_out << std::endl;
    std::cout << "calculation: ground_speed: " << ground_speed << std::endl;
    std::cout << "calculation: airspeed: " << current_UAV_state.airspeed << std::endl;
    // air_speed = current_UAV_state.airspeed < 10 ? 10 : current_UAV_state.airspeed;
    air_speed = current_UAV_state.airspeed;
    roll_cmd = atanf((yaw_out * air_speed) / CONSTANTS_ONE_G); // 计算出来的是弧度

    roll_cmd = constrain(roll_cmd, -PI / 4, PI / 4);
    // roll_cmd = constrain(roll_cmd, -PI / 2, PI / 2);

    return roll_cmd;

}

void FixedwingPositionSubAndPub::IncrementPid(float in, float Kp, float Ki,
                                              float Kd)
{
  input = in;

  float param_p = Kp * (input - prev_input);
  float param_i = Ki * input;
  float param_d = Kd * (input - 2 * prev_input + prev2_input);

  increment = param_p + param_i + param_d;

  prev2_input = prev_input;
  prev_input = input;
}
float FixedwingPositionSubAndPub::GetFullOutput()
{
  output = prev_output + increment;
  prev_output = output;
  return output;
}
void FixedwingPositionSubAndPub::Assignment(){
    setCommands.count_number = formationPosition.count_number;
    setCommands.pitch = att_sp[PITCH_NUMBER];
    setCommands.roll = att_sp[ROLL_NUMBER];
    setCommands.throttle = att_sp[THROTTLE_NUMBER];
    setCommands.yaw = att_sp[YAW_NUMBER];
}
void FixedwingPositionSubAndPub::showDataFromUdp(){
    cout << "count_number: " << formationPosition.count_number << endl;
    cout << "airspeed: " << formationPosition.leaderAirspeed << endl;
    cout << "commandYaw : " << formationPosition.leaderCommand_yaw << endl;
    cout << "heading : " << formationPosition.leaderHeading << endl;
    cout << endl;
}

void FixedwingPositionSubAndPub::showData(){
    cout << "poition controller: " << endl;
    cout << "cout_number = " << formationPosition.count_number << endl;
    cout << "yaw = " << setCommands.yaw << endl;
    cout << "roll = " << setCommands.roll << endl;
    cout << "pitch = " << setCommands.pitch << endl;
    cout << "throttle = " << setCommands.throttle << endl;
    cout << endl;
    
}

void FixedwingPositionSubAndPub::publishSetpoint(){
    Assignment();
    ROS_ERROR("publish the att_sp");
    att_sp_pub.publish(setCommands);
    WriteLogFile_Publish();
}
