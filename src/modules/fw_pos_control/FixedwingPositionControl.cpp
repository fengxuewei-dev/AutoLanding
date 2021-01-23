#include "FixedwingPositionControl.hpp"

int main(int argc, char **argv){

    /* 1. configuration */
    std::string ControlMode;
    std::string FlyMode;

    std::string uavName = "";  

    ControlModeType controlMode = CONTROL::_CONTROLMODENULL;
    FlyModeType flyMode = FLY::_FLYMODENULL_;

    std::string nodeName = "FixedwingPositionControl";

    // node name & uavName & control mode & fly mode
    if(argc == 3){ 
        ControlMode = argv[1]; // get the control mode
        FlyMode = argv[2];      // get the fly mode
        
        if(FlyMode == "_SINGLE_FLYMODE_"){ // classification
            ROS_INFO("The control mode is _SINGLE_FLYMODE_!");
            flyMode = _SINGLE_FLYMODE_;
        }
        else if(FlyMode == "_FORMATION_FLYMODE_"){
            ROS_INFO("The control mode is _FORMATION_FLYMODE_!");
            flyMode = _FORMATION_FLYMODE_;
        }
        else{
            ROS_INFO("The fly mode is error!");
            return 0;
        }

        if(ControlMode == "_RC_ATTITUDE_CONTROLLER_"){ // classification
            ROS_INFO("The control mode is _RC_ATTITUDE_CONTROLLER_!");
            controlMode = _RC_ATTITUDE_CONTROLLER_;
        }
        else if(ControlMode == "_OFFBOARD_ATTITUDE_CONTROLLER_"){
            ROS_INFO("The control mode is _OFFBOARD_ATTITUDE_CONTROLLER_!");
            controlMode = _OFFBOARD_ATTITUDE_CONTROLLER_;
        }
        else{
            ROS_INFO("The control mode is error!");
            return 0;
        }	   
    }else  if(argc == 4){ 
        uavName = argv[1];
        uavName = uavName + "/";
        nodeName = nodeName.append(uavName, 3, 1);

        ControlMode = argv[2]; // get the control mode
        FlyMode = argv[3];      // get the fly mode
        
        if(FlyMode == "_SINGLE_FLYMODE_"){ // classification
            ROS_INFO("The control mode is _SINGLE_FLYMODE_!");
            flyMode = _SINGLE_FLYMODE_;
        }
        else if(FlyMode == "_FORMATION_FLYMODE_"){
            ROS_INFO("The control mode is _FORMATION_FLYMODE_!");
            flyMode = _FORMATION_FLYMODE_;
        }
        else{
            ROS_INFO("The fly mode is error!");
            return 0;
        }

        if(ControlMode == "_RC_ATTITUDE_CONTROLLER_"){ // classification
            ROS_INFO("The control mode is _RC_ATTITUDE_CONTROLLER_!");
            controlMode = _RC_ATTITUDE_CONTROLLER_;
        }
        else if(ControlMode == "_OFFBOARD_ATTITUDE_CONTROLLER_"){
            ROS_INFO("The control mode is _OFFBOARD_ATTITUDE_CONTROLLER_!");
            controlMode = _OFFBOARD_ATTITUDE_CONTROLLER_;
        }
        else{
            ROS_INFO("The control mode is error!");
            return 0;
        }	   
    }
    else if(argc == 1)
    {
        initflag = 0;
    }
    else if (argc == 2)
    {
        initflag = 0;
        uavName = argv[1];
        uavName = uavName + "/";
        nodeName = nodeName.append(uavName, 3, 1);
    }
    
    else{
        ROS_ERROR("Please choose a call mode which contains RC and offboard!");
        return 0;
    }

    
    
    ros::init(argc, argv, nodeName);

    // subscribe all the data..
    FixedwingPositionSubAndPub fixedwingPositionSubAndPub(uavName);

    ros::Rate rate(POSITION_CONTROLLER_RATE_EXE);
    
#ifdef _ADD_PROCESSOR_ 
    while(ros::ok() && initflag == 0 && (fixedwingPositionSubAndPub.uavflag_state.group == 0 || fixedwingPositionSubAndPub.uavflag_state.group == -1) ){
        ROS_INFO("Init with QC msg, and QC msg not correct...");
        ros::spinOnce();
        rate.sleep();
    }
    if(fixedwingPositionSubAndPub.uavflag_state.isleader == 1){
        flyMode = _SINGLE_FLYMODE_;
        if(fixedwingPositionSubAndPub.uavflag_state.controlmode == 1){
            controlMode = _RC_ATTITUDE_CONTROLLER_;
        }
        else{
            controlMode = _OFFBOARD_ATTITUDE_CONTROLLER_;
        }
    }
    else if(fixedwingPositionSubAndPub.uavflag_state.isleader == 0)
    {
        flyMode = _FORMATION_FLYMODE_;
        if(fixedwingPositionSubAndPub.uavflag_state.controlmode == 1){
            controlMode = _RC_ATTITUDE_CONTROLLER_;
        }
        else{
            controlMode = _OFFBOARD_ATTITUDE_CONTROLLER_;
        }
    }
    else
    {
        while(ros::ok()){
            ROS_INFO("Unknow error...");
            ros::spinOnce();
            rate.sleep();
        }
    }
#endif

    ROS_ERROR("position controller...");
    
    // wait for FCU connection
    while(ros::ok() && fixedwingPositionSubAndPub.position_setpoint.enu_nextWaypoint.z_alt == 0){
        ROS_INFO("waiting for connection ...");
        ros::spinOnce();
        rate.sleep();
    }        // 运行途中关掉 主机和从机的数据链 之后, 看看从机是如何执行的

    /* 2. data sources -- position_setpoint */

    /* 3. logically handle */
    while(ros::ok())
    {   
        ROS_ERROR(" position controller >>> ");
        // 需要用到速度的方面有：
        // 1. tecs 计算 throttle 的时候； 
        // 2. vf 计算的时候 throttle 给定的是 18
        // 3. handler 计算主机的速度
        // DEBUG
        /* print the information */
        
        // cout << "airspeed : " << fixedwingPositionSubAndPub.formationPosition.leaderAirspeed << endl;
        // cout << "command yaw : " << fixedwingPositionSubAndPub.formationPosition.leaderCommand_yaw << endl;
        // cout << "heading  : " << fixedwingPositionSubAndPub.formationPosition.leaderHeading << endl;
switch(controlMode)
{
case _OFFBOARD_ATTITUDE_CONTROLLER_:    
    ROS_ERROR("the offboard mode --> set airspeed for tecs");
    fixedwingPositionSubAndPub.setAirspeed_tecs(fixedwingPositionSubAndPub.position_setpoint.Throttle);                                // set the airspeed setpoint for TECS
    fixedwingPositionSubAndPub.setIsRC(false);
    break;
case _RC_ATTITUDE_CONTROLLER_:
    fixedwingPositionSubAndPub.setIsRC(true);
    break;
}

switch(flyMode)
{
case _SINGLE_FLYMODE_: 
    ROS_ERROR("the single mode --> set airspeed for vf");
    fixedwingPositionSubAndPub.setAirspeed_single(fixedwingPositionSubAndPub.position_setpoint.Throttle);                                // set the airspeed setpoint for TECS
    fixedwingPositionSubAndPub.setIsSingleFly();
    break;
case _FORMATION_FLYMODE_:   
    ROS_INFO("formation position controller");
    fixedwingPositionSubAndPub.setIsFormationFly();
    break;
// case _SELFORG_FLYMODE_:   
//     ROS_INFO("Self Organization controller");
//     fixedwingPositionSubAndPub.setIsSelfOrganizationFly();
//     break;
}

        fixedwingPositionSubAndPub.showDataFromUdp();
        fixedwingPositionSubAndPub.print_navi_setpoint();
        /* Calculation att_sp */
        
        fixedwingPositionSubAndPub.calculation();

        /* 4. publish the setpoints to attitude controller */
        fixedwingPositionSubAndPub.publishSetpoint();
        
        fixedwingPositionSubAndPub.showData();
        
        ros::spinOnce(); // 保证数据的实时性
        rate.sleep();
    }
    return 0;
}
