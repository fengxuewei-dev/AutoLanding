#include "navigator.hpp"
/*
    在编队下面， navigator 只需要给主机发一个期望位置就可以了

        接收 主机的期望位置 + gap(写入内部)
    -->     计算初始误差 calculate_configuration_error() home 点的位置
    -->     计算时延(需要的是掌机的heading) calculate_time_error()
*/

int main(int argc, char **argv){
    /* 1. configuration */
    std::string ControlMode;
    std::string FlyMode;
    NAVIGATOR("导航启动...");

    std::string uavName = "";  

    ControlModeType controlMode = CONTROL::_CONTROLMODENULL;
    FlyModeType flyMode = FLY::_FLYMODENULL_;

    std::string nodeName = "Navigator";

    // node name & uavName & fly mode
    if(argc == 1){
        initflag = 0;
        // getchar();
    }else if(argc == 3){ 
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
        else if (FlyMode.substr(0, 3) == "uav")
        {
            initflag = 0;
            uavName = argv[1];
            uavName = uavName + "/";
            nodeName = nodeName.append(uavName, 3, 1);
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
        nodeName = nodeName.append(uavName, 3, 1);
    }
    else if (argc == 2)
    {
        initflag = 0;
        uavName = argv[1];
        uavName = uavName + "/";

        nodeName = nodeName.append(uavName, 3, 1);

    }
    else{
        ROS_ERROR("Please choose a call mode which contains RC and offboard or have not them!");
        return 0;
    }


    
    ros::init(argc, argv, nodeName);
    NAVIGATOR("节点初始化完成");

    // subscribe all the data...
    NavigatorSubAndPub navigatorSubAndPub(uavName);

    ros::Rate rate(NAVIGATOR_CONTROLLER_RATE_EXE);

    NAVIGATOR("开始等待 initflag ");

#ifdef _ADD_PROCESSOR_ 
    while(ros::ok() && 
        (
            navigatorSubAndPub.uavflag_state.group == 0 || 
            navigatorSubAndPub.uavflag_state.group == -1
        ) 
    ){
        NAVIGATOR("Init with QC msg, and QC msg not correct...");
        ros::spinOnce();
        rate.sleep();
    }

    if(navigatorSubAndPub.uavflag_state.isleader == 1){
        NAVIGATOR_DOUBLE("navigatorSubAndPub.uavflag_state.isleader = ", navigatorSubAndPub.uavflag_state.isleader);
        NAVIGATOR_DOUBLE("navigatorSubAndPub.uavflag_state.group = ", navigatorSubAndPub.uavflag_state.group);
        flyMode = _SINGLE_FLYMODE_;
        if(navigatorSubAndPub.uavflag_state.controlmode == 1){
            controlMode = _RC_ATTITUDE_CONTROLLER_;
        }
        else{
            controlMode = _OFFBOARD_ATTITUDE_CONTROLLER_;
        }
    }
    else if(navigatorSubAndPub.uavflag_state.isleader == 0)
    {
        NAVIGATOR_DOUBLE("navigatorSubAndPub.uavflag_state.isleader = ", navigatorSubAndPub.uavflag_state.isleader);
        NAVIGATOR_DOUBLE("navigatorSubAndPub.uavflag_state.group = ", navigatorSubAndPub.uavflag_state.group);
        flyMode = _FORMATION_FLYMODE_;
        if(navigatorSubAndPub.uavflag_state.controlmode == 1){
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
    // while(
    //     ros::ok() && navigatorSubAndPub.waypoint_List.waypoints.size() == 0          
    // ){
    //     // 等待接收到 航点列表 
    //     ros::spinOnce();
    //     rate.sleep();
    // }

    /* 接收打印 >>>>>>>>>>>>> */
    if( flyMode == _FORMATION_FLYMODE_)
        std::cout << "_FORMATION_FLYMODE_" << std::endl;
    else
        std::cout << "_SINGLE_FLYMODE_" << std::endl;
    if( controlMode == _RC_ATTITUDE_CONTROLLER_)
        std::cout << "_RC_ATTITUDE_CONTROLLER_" << std::endl;
    else
        std::cout << "_OFFBOARD_ATTITUDE_CONTROLLER_" << std::endl;
    /* <<<<<<<<<<<<<< 接收打印 */

switch(controlMode)
{
case _OFFBOARD_ATTITUDE_CONTROLLER_:    
    ROS_ERROR("the offboard commander --> set waypoint list for WGS84");
    navigatorSubAndPub.GPS_update();                // 更新航点列表 为了给offboard使用
    navigatorSubAndPub.setIsRC(false);
    break;
case _RC_ATTITUDE_CONTROLLER_:
    ROS_ERROR("the rc commander --> set waypoint list for rc");
    // navigatorSubAndPub.GPS_transform_ENU();         // 转化 enu
    navigatorSubAndPub.setIsRC(true);
    break;
}


switch (flyMode)
{
case _SINGLE_FLYMODE_:
     /* 2. get data source */
    while(ros::ok() && navigatorSubAndPub.waypoint_List.waypoints.size() == 0 && navigatorSubAndPub.getI() == 0){
        NAVIGATOR("single >>> waiting for waypointslist...");
        ros::spinOnce();
        rate.sleep();
    }
    /* updata the waypoint list to add the home position to the new waypoint list */ 
    navigatorSubAndPub.GPS_transform_ENU();
    while(ros::ok()){
        // 1. 初始化阶段 判断航线是否进行更新 第一次执行航线, 进行
        if(!navigatorSubAndPub.isSameWaypointLists(navigatorSubAndPub.pre_waypoint_List, navigatorSubAndPub.waypoint_List)){
            navigatorSubAndPub.GPS_transform_ENU();
            navigatorSubAndPub.pre_waypoint_List = navigatorSubAndPub.waypoint_List;
        }
        // 2. 执行航线
        navigatorSubAndPub.singleWriteLog();
        /* Waypoint switch */ 
        navigatorSubAndPub.WaypointSwitch();

        /* get and send the data */
        navigatorSubAndPub.choose_position_setpoints();
        navigatorSubAndPub.publishPositionTriplet();

        navigatorSubAndPub.showData();
        
        ros::spinOnce();
        rate.sleep();
    }
    break;
case _FORMATION_FLYMODE_:
    /* 2. get data source */

    while(ros::ok() && navigatorSubAndPub.leader_home.geo.altitude == 0){
        ROS_INFO("FORMATION");
        ROS_INFO("waiting for connecting...");
        ros::spinOnce();
        rate.sleep();
    }

    navigatorSubAndPub.showDataFrom_udp();
    
    while(ros::ok()){
        // 1. interface: 获得 -－> 设置gap的值
        navigatorSubAndPub.setGap();
        navigatorSubAndPub.formationWriteLog();
        navigatorSubAndPub.getWaypoint_formation();
        navigatorSubAndPub.setPoistionSetpoint_formation();
        navigatorSubAndPub.publishPositionTriplet();
        navigatorSubAndPub.showData();
        ros::spinOnce();
        rate.sleep();
    }
    break;
// case /*自组织算法*/: 
//     break;
}

    return 0;
}
