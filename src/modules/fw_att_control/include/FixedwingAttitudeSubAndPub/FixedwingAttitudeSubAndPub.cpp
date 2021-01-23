#include "FixedwingAttitudeSubAndPub.hpp"


FixedwingAttitudeSubAndPub::FixedwingAttitudeSubAndPub(std::string uavName_){

    uavName = uavName_;
    
    logSubConfig();
    
    offb_att_sp_pub = nh.advertise<mavros_msgs::AttitudeTarget>
            (uavName + "mavros/setpoint_raw/attitude", 1); 
    rc_control = nh.advertise<mavros_msgs::OverrideRCIn>  
            (uavName + "mavros/rc/override", 1);
    
    offboard_sub = nh.subscribe<fw_msgs::commands>
            (uavName + "attitudeControl/commands", 1,boost::bind(&FixedwingAttitudeSubAndPub::command_cb, this, _1));
    uav_state_sub = nh.subscribe<mavros_msgs::VFR_HUD>  
            (uavName + "msgsFromPx4/vfr_hud", 1,boost::bind(&FixedwingAttitudeSubAndPub::newUAVState, this, _1));
    uav_localPos_sub = nh.subscribe<geometry_msgs::PoseStamped>
            (uavName + "msgsFromPx4/local_position/pose",1,boost::bind(&FixedwingAttitudeSubAndPub::new_localPose, this, _1));

    processer_sub = nh.subscribe<fw_msgs::processer>
            (uavName + "processer/attitude", 1, boost::bind(&FixedwingAttitudeSubAndPub::processer_cb, this, _1));

    uavflag_sub = nh.subscribe<fw_msgs::uavflag> 
            (uavName + "processer/uavflag", 1, boost::bind(&FixedwingAttitudeSubAndPub::uavflag_cb, this, _1));
    
    local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>
            (uavName + "mavros/setpoint_position/local", 1);

    state_sub = nh.subscribe<mavros_msgs::State>
            (uavName + "msgsFromPx4/state", 1,boost::bind(&FixedwingAttitudeSubAndPub::state_cb, this, _1));
    set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
            (uavName + "mavros/set_mode");
    set_parameter = nh.serviceClient<mavros_msgs::ParamSet>   
            (uavName + "mavros/param/set");


    uav_imu_sub = nh.subscribe<sensor_msgs::Imu>
            (uavName + "msgsFromPx4/imu/data", 1, boost::bind(&FixedwingAttitudeSubAndPub::imu_cb, this, _1));
}
FixedwingAttitudeSubAndPub::~FixedwingAttitudeSubAndPub(){}

void FixedwingAttitudeSubAndPub::imu_cb(const sensor_msgs::Imu::ConstPtr &msg)
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


void FixedwingAttitudeSubAndPub::getEuler(float *_Euler_){
    _Euler_[0] = att_angle_Euler[0];
    _Euler_[1] = att_angle_Euler[1];
    _Euler_[2] = att_angle_Euler[2];
}
void FixedwingAttitudeSubAndPub::logRCPubConfig(){
    log_publish_rc_roll_sp.configuration
        (string(LOGGERPATH) + "/" + uavName + "attitude_controller/publish/RC", "roll", "setpoint") ;
    log_publish_rc_yaw_sp.configuration
        (string(LOGGERPATH) + "/" + uavName + "attitude_controller/publish/RC", "yaw", "setpoint") ;
    log_publish_rc_pitch_sp.configuration
        (string(LOGGERPATH) + "/" + uavName + "attitude_controller/publish/RC", "pitch", "setpoint") ;
    log_publish_rc_throttle_sp.configuration
        (string(LOGGERPATH) + "/" + uavName + "attitude_controller/publish/RC", "throttle", "setpoint") ;
}

void FixedwingAttitudeSubAndPub::logOFFBOARDPubConfig(){
    log_publish_offboard_roll_sp.configuration
        (string(LOGGERPATH) + "/" + uavName + "attitude_controller/publish/OFFBOARD", "roll", "setpoint") ;
    log_publish_offboard_yaw_sp.configuration
        (string(LOGGERPATH) + "/" + uavName + "attitude_controller/publish/OFFBOARD", "yaw", "setpoint") ;
    log_publish_offboard_pitch_sp.configuration
        (string(LOGGERPATH) + "/" + uavName + "attitude_controller/publish/OFFBOARD", "pitch", "setpoint") ;
    log_publish_offboard_throttle_sp.configuration
        (string(LOGGERPATH) + "/" + uavName + "attitude_controller/publish/OFFBOARD", "throttle", "setpoint") ;
}
void FixedwingAttitudeSubAndPub::logSubConfig(){
    log_subscribe_roll_setpoint.configuration
        (string(LOGGERPATH) + "/" + uavName + "attitude_controller/subscribe",  "roll", "setpoint");
    log_subscribe_yaw_setpoint.configuration
        (string(LOGGERPATH) + "/" + uavName + "attitude_controller/subscribe",  "yaw", "setpoint");
    log_subscribe_pitch_setpoint.configuration
        (string(LOGGERPATH) + "/" + uavName + "attitude_controller/subscribe",  "pitch", "setpoint");
    log_subscribe_throttle_setpoint.configuration
        (string(LOGGERPATH) + "/" + uavName + "attitude_controller/subscribe",  "throttle", "setpoint");
}

void FixedwingAttitudeSubAndPub::WriteLogFile_Subscribe(){
    log_subscribe_roll_setpoint.logPrint(commands.roll); // 可以打印
    log_subscribe_yaw_setpoint.logPrint(commands.yaw);
    log_subscribe_pitch_setpoint.logPrint(commands.pitch);
    log_subscribe_throttle_setpoint.logPrint(commands.throttle);
    
}
void FixedwingAttitudeSubAndPub::WriteLogFile_RC_Publish(float *att_sp){
    log_publish_rc_roll_sp.logPrint(att_sp[ROLL_CHANNEL-1]);
    log_publish_rc_yaw_sp.logPrint(att_sp[YAW_CHANNEL-1]);
    log_publish_rc_pitch_sp.logPrint(att_sp[PITCH_CHANNEL-1]);
    log_publish_rc_throttle_sp.logPrint(att_sp[THROTTLE_CHANNEL-1]);
}
void FixedwingAttitudeSubAndPub::WriteLogFile_OFFBOARD_Publish(fw_msgs::commands commands){
    log_publish_offboard_roll_sp.logPrint(commands.roll);
    log_publish_offboard_yaw_sp.logPrint(commands.yaw);
    log_publish_offboard_pitch_sp.logPrint(commands.pitch);
    log_publish_offboard_throttle_sp.logPrint(commands.throttle);
}

void FixedwingAttitudeSubAndPub::uavflag_cb(const fw_msgs::uavflag::ConstPtr& msg){
    uavflag_state = *msg;
}

void FixedwingAttitudeSubAndPub::state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}
void FixedwingAttitudeSubAndPub::command_cb(const fw_msgs::commands::ConstPtr& msg){
    commands = *msg;
    WriteLogFile_Subscribe();
}
void FixedwingAttitudeSubAndPub::newUAVState(const mavros_msgs::VFR_HUD::ConstPtr& msg){
    current_UAV_state = *msg;
}

void FixedwingAttitudeSubAndPub::new_localPose(const geometry_msgs::PoseStamped::ConstPtr& msg){
	current_localPose = *msg;
}

void FixedwingAttitudeSubAndPub::processer_cb(const fw_msgs::processer::ConstPtr& msg){
    processer = *msg;
}

void FixedwingAttitudeSubAndPub::turnAngle2Quaternion(){
    float angle[3], quat[4];
    angle[0] = commands.roll;
    angle[1] = commands.pitch;
    angle[2] = commands.yaw;
        
    euler_2_quaternion(angle, quat);

    attitude_setpoint.type_mask = 7; //1+2+4+64+128 body.rate_x,body.rate_y,body.rate_z thrust..
    attitude_setpoint.orientation.w = quat[0];
    attitude_setpoint.orientation.x = quat[1];
    attitude_setpoint.orientation.y = quat[2];
    attitude_setpoint.orientation.z = quat[3];
    attitude_setpoint.thrust = commands.throttle;
}
void FixedwingAttitudeSubAndPub::pos_publish(){
    geometry_msgs::PoseStamped pose;
    pose.pose.position.x = 0;
    pose.pose.position.y = 0;
    pose.pose.position.z = 2;
    local_pos_pub.publish(pose);
}
void FixedwingAttitudeSubAndPub::offPublishSetpoints(){
    offb_att_sp_pub.publish(attitude_setpoint);
}

void FixedwingAttitudeSubAndPub::showSetpoints(){
    cout << endl;
    cout << "commands.roll \t pitch \t yaw \t throttle: " << commands.roll << endl;
    cout << commands.roll << " " << commands.pitch << " " << commands.yaw << " " << commands.throttle << endl;
}

bool FixedwingAttitudeSubAndPub::CommandsIsNull(){
    return (commands.roll == 0 && commands.yaw == 0 && commands.throttle == 0 && commands.pitch != 0);
}
