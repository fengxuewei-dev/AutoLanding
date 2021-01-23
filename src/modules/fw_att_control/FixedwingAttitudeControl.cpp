#include "FixedwingAttitudeControl.hpp"

int main(int argc, char **argv){
    
    /* 1. confirguration */ 
    std::string ControlMode;
    ControlModeType controlMode = _ControlModeNULL_;
    
    std::string uavName = "";
    std::string nodeName = "FixedwingAttitudeControl";

    if(argc == 2){
        ControlMode = argv[1]; // get the control mode
        if(ControlMode == "_RC_ATTITUDE_CONTROLLER_"){ // classification
            ROS_INFO("The control mode is _RC_ATTITUDE_CONTROLLER_!");
            controlMode = _RC_ATTITUDE_CONTROLLER_;
        }
        else if(ControlMode == "_OFFBOARD_ATTITUDE_CONTROLLER_"){
            ROS_INFO("The control mode is _OFFBOARD_ATTITUDE_CONTROLLER_!");
            controlMode = _OFFBOARD_ATTITUDE_CONTROLLER_;
        }
        else if (ControlMode.substr(0, 3) == "uav")
        {
            initflag = 0;
            uavName = argv[1];
            uavName = uavName + "/";
            nodeName = nodeName.append(uavName, 3, 1);
        }
        else{
            ROS_INFO("The mode is error!");
            return 0;
        }
    }else if(argc == 3){
        uavName = argv[1];
        uavName = uavName + "/";
        ControlMode = argv[2]; // get the control mode
        if(ControlMode == "_RC_ATTITUDE_CONTROLLER_"){ // classification
            ROS_INFO("The control mode is _RC_ATTITUDE_CONTROLLER_!");
            controlMode = _RC_ATTITUDE_CONTROLLER_;
        }
        else if(ControlMode == "_OFFBOARD_ATTITUDE_CONTROLLER_"){
            ROS_INFO("The control mode is _OFFBOARD_ATTITUDE_CONTROLLER_!");
            controlMode = _OFFBOARD_ATTITUDE_CONTROLLER_;
        }
        else{
            ROS_INFO("The mode is error!");
            return 0;
        }
        nodeName = nodeName.append(uavName, 3, 1);
    }
    else if(argc == 1){
        initflag = 0;
    }
    else{
        ROS_ERROR("Please choose a call mode which contains RC and offboard!");
        return 0;
    }

    ros::init(argc, argv, nodeName);

    FixedwingAttitudeSubAndPub fixedwingAttitudeSubAndPub(uavName);  

    ros::Rate rate(ATTITUDE_CONTROLLER_RATE_EXE);

    fixedwingAttitudeSubAndPub.pose.pose.position.x = 0;
    fixedwingAttitudeSubAndPub.pose.pose.position.y = 0;
    fixedwingAttitudeSubAndPub.pose.pose.position.z = 2;

    pidControl PID;
	rc RC;
	float att_sp[4];

#ifdef _ADD_PROCESSOR_ 
    while(ros::ok() && initflag == 0 && 
        (fixedwingAttitudeSubAndPub.uavflag_state.group == 0 || fixedwingAttitudeSubAndPub.uavflag_state.group == -1) )
    {
        ROS_INFO("Init with QC msg, and QC msg not correct...");
        ros::spinOnce();
        rate.sleep();
    }
    if(fixedwingAttitudeSubAndPub.uavflag_state.isleader == 1){
        controlMode = _RC_ATTITUDE_CONTROLLER_;
    }
    else if(fixedwingAttitudeSubAndPub.uavflag_state.isleader == 0)
    {
        controlMode = _RC_ATTITUDE_CONTROLLER_;
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

switch(controlMode)
{
case _OFFBOARD_ATTITUDE_CONTROLLER_:
    fixedwingAttitudeSubAndPub.logOFFBOARDPubConfig();
    fixedwingAttitudeSubAndPub.set_mode.request.custom_mode = "OFFBOARD";
    break;
case _RC_ATTITUDE_CONTROLLER_:
	
    RC.setParameters();
    fixedwingAttitudeSubAndPub.logRCPubConfig();

    fixedwingAttitudeSubAndPub.set_mode.request.custom_mode = "ALTCTL";
}
//    while (ros::ok() && fixedwingAttitudeSubAndPub.processer.execflag == 0)
//    {
//        ROS_INFO("waiting for processer flag ...");
//        ros::spinOnce();
//        rate.sleep();
//    }

//    if(fixedwingAttitudeSubAndPub.set_mode_client.call(fixedwingAttitudeSubAndPub.set_mode)) ROS_INFO("MODE CALLED");
//	if(!fixedwingAttitudeSubAndPub.set_mode.response.mode_sent) ROS_INFO("MODE FAILED");

    ros::Time last_request = ros::Time::now();

    // wait for FCU connection
    while(
        ros::ok() && 
        !fixedwingAttitudeSubAndPub.current_state.connected &&
        fixedwingAttitudeSubAndPub.commands.pitch == 0
    ){
        ROS_INFO("waiting for connection ...");
        ros::spinOnce();
        rate.sleep();
    }
    /* 2. data sources --- commands that come from offboard or rc */
    
    
    /* 3. logically handle */
    while(ros::ok())
    {

#ifdef _ADD_PROCESSOR_ 
        // check if it is in altitude control 
		if(fixedwingAttitudeSubAndPub.processer.execflag == 0){
		    ROS_INFO("waiting for processer flag ...%d", fixedwingAttitudeSubAndPub.processer.execflag);
		}
	    else 
#endif
        if(

#ifdef _ADD_PROCESSOR_ 
	0
    //            (fixedwingAttitudeSubAndPub.processer.execflag == 1) && (modeset_flag == 0) && 
#endif
//                fixedwingAttitudeSubAndPub.current_state.mode.compare(fixedwingAttitudeSubAndPub.set_mode.request.custom_mode)
  //              && (ros::Time::now() - last_request > ros::Duration(5.0))
        ){
                    if( 
       //                 fixedwingAttitudeSubAndPub.set_mode_client.call(fixedwingAttitudeSubAndPub.set_mode) 
         //               &&	fixedwingAttitudeSubAndPub.set_mode.response.mode_sent
			1
                    ){
                        ROS_INFO("%s enabled", 	fixedwingAttitudeSubAndPub.set_mode.request.custom_mode.c_str());
                        
                    }
			        last_request = ros::Time::now();
		}
	     else if(fixedwingAttitudeSubAndPub.current_state.mode.compare(fixedwingAttitudeSubAndPub.set_mode.request.custom_mode) == 0
                && "ALTCTL" == fixedwingAttitudeSubAndPub.current_state.mode)
       		{
          		 modeset_flag = 1;
          		 last_request = ros::Time::now();
          		 ROS_INFO("ALTCTL mode has set...");
       		}
switch(controlMode)
{
case _OFFBOARD_ATTITUDE_CONTROLLER_:
        /* publish the pose to set the offboard */
        fixedwingAttitudeSubAndPub.pos_publish();

        fixedwingAttitudeSubAndPub.isOffboardAttiControl = true;
        
        if(!fixedwingAttitudeSubAndPub.CommandsIsNull())
        {
            // turn the angle into the quaternion
            fixedwingAttitudeSubAndPub.turnAngle2Quaternion();
            
            // show the setpoints
            fixedwingAttitudeSubAndPub.showSetpoints();
            fixedwingAttitudeSubAndPub.WriteLogFile_OFFBOARD_Publish(fixedwingAttitudeSubAndPub.commands);

            // 4. publish the setpoints to firmware by offborad
            fixedwingAttitudeSubAndPub.offb_att_sp_pub.publish(fixedwingAttitudeSubAndPub.attitude_setpoint);
        }
        else
        {
            ROS_ERROR("No information be sended!");
        }
        break;

case _RC_ATTITUDE_CONTROLLER_:

        fixedwingAttitudeSubAndPub.isOffboardAttiControl = false;

        PID.current_commands = fixedwingAttitudeSubAndPub.commands;
		PID.current_localPose = fixedwingAttitudeSubAndPub.current_localPose;
		PID.current_UAV_state = fixedwingAttitudeSubAndPub.current_UAV_state;   
        float Eular[3];
        fixedwingAttitudeSubAndPub.getEuler(Eular);
        PID.Calculate(att_sp, Eular);
		RC.Assignment(att_sp);
        
        fixedwingAttitudeSubAndPub.showSetpoints();
		fixedwingAttitudeSubAndPub.WriteLogFile_RC_Publish(att_sp);
        
        // 4. publish the setpoints to firmware by RC.
        fixedwingAttitudeSubAndPub.rc_control.publish(RC.newRCIn);
        break;
}
        ros::spinOnce();
        rate.sleep();
    }
   return 0;
}
