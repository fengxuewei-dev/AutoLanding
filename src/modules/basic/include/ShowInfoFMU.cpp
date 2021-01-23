#include "ShowInfoFMU.hpp"
void  FIXED_WING_INFORMATION_DISPLAY::ros_sub_and_pub(string uavName, FW_SUB_PUB *fw_sub_pub_pointer)
{
    if("" == uavName){
        ROS_INFO("---- To begin display the information about single uav ----");
    }
    else{
        ROS_INFO("---- To begin display the information about the uav: %s ----", uavName.c_str());
    }
    
    fw_states                  // 查看飞控的飞行姿态
        = nh.subscribe<mavros_msgs::State> //
          (uavName+"/mavros/state", 10, &FW_SUB_PUB::state_cb,fw_sub_pub_pointer);

    
    // 【订阅】无人机imu信息，
    fw_imu                   //
        = nh.subscribe<sensor_msgs::Imu> //
          (uavName+"/mavros/imu/data", 10, &FW_SUB_PUB::imu_cb,fw_sub_pub_pointer);

    // 【订阅】无人机gps位置
   fw_global_position    //
        = nh.subscribe<sensor_msgs::NavSatFix> //
          (uavName+"/mavros/global_position/global", 10, &FW_SUB_PUB::global_position_form_px4_cb,fw_sub_pub_pointer);

    //【订阅】无人机gps相对alt
   fw_global_rel_alt //
        = nh.subscribe<std_msgs::Float64>  //
          (uavName+"/mavros/global_position/rel_alt", 10, &FW_SUB_PUB::fixed_wing_global_rel_alt_from_px4_cb,fw_sub_pub_pointer);

    // 【订阅】无人机ump位置
   fw_umt_position   //
        = nh.subscribe<nav_msgs::Odometry> //
          (uavName+"/mavros/global_position/local", 10, &FW_SUB_PUB::umt_position_from_px4_cb,fw_sub_pub_pointer);

    // 【订阅】无人机gps三向速度
   fw_velocity_global_fused   //
        = nh.subscribe<geometry_msgs::TwistStamped> //
          (uavName+"/mavros/global_position/raw/gps_vel", 10, &FW_SUB_PUB::velocity_global_fused_from_px4_cb,fw_sub_pub_pointer);

    // 【订阅】无人机ned位置
   fw_local_position             //
        = nh.subscribe<geometry_msgs::PoseStamped> //
          ( uavName+"/mavros/local_position/pose",10, &FW_SUB_PUB::local_position_from_px4_cb,fw_sub_pub_pointer);

    // 【订阅】无人机ned三向速度
   fw_velocity_ned_fused      //
        = nh.subscribe<geometry_msgs::TwistStamped> //
          (uavName+"/mavros/local_position/velocity_local", 10, &FW_SUB_PUB::velocity_ned_fused_from_px4_cb,fw_sub_pub_pointer);

    // 【订阅】无人机ned三向加速度
   fw_acc_ned                               //
        = nh.subscribe<geometry_msgs::AccelWithCovarianceStamped> //
          (uavName+"/mavros/local_position/accel", 10, &FW_SUB_PUB::acc_ned_from_px4_cb,fw_sub_pub_pointer);

    // 【订阅】无人机ned三向加速度
   fw_wind_estimate                         //
        = nh.subscribe<geometry_msgs::TwistWithCovarianceStamped> //
          (uavName+"/mavros/wind_estimation", 10, &FW_SUB_PUB::wind_estimate_from_px4_cb,fw_sub_pub_pointer);

     // 【订阅】无人机ned三向加速度
   fw_battrey_state         //
        = nh.subscribe<sensor_msgs::BatteryState> //
          (uavName+"/mavros/battery", 10, &FW_SUB_PUB::battrey_state_from_px4_cb,fw_sub_pub_pointer);

   fw_waypoints                   //// 【订阅】无人机当前航点
        = nh.subscribe<mavros_msgs::WaypointList> //
          (uavName+"/mavros/mission/waypoints", 10, &FW_SUB_PUB::waypointlist_from_px4_cb,fw_sub_pub_pointer);

   fw_waypointsreach                   //// 【订阅】无人机到达的航点
        = nh.subscribe<mavros_msgs::WaypointReached> //
          (uavName+"/mavros/mission/reached", 10, &FW_SUB_PUB::waypoints_reached_from_px4_cb,fw_sub_pub_pointer);

   fw_altitude          //订阅高度
        = nh.subscribe<mavros_msgs::Altitude> //
          (uavName+"/mavros/altitude", 10, &FW_SUB_PUB::altitude_from_px4_cb,fw_sub_pub_pointer);

   fw_air_ground_speed //订阅空速、地速
        = nh.subscribe<mavros_msgs::VFR_HUD> //
          (uavName+"/mavros/vfr_hud", 10, &FW_SUB_PUB::air_ground_speed_from_px4_cb,fw_sub_pub_pointer);
   
    if("" == uavName){
        ROS_INFO("---- To begin display the information about single uav ----");
    }
    else{
        ROS_INFO("---- To begin display the information about the uav: %s ----", uavName.c_str());
    }

}
bool FIXED_WING_INFORMATION_DISPLAY::run(int argc, char **argv)
{

    ros::Rate rate(20.0);
    begin_time = ros::Time::now(); // 记录启控时间
    
    std::string uavName;
    cout << "1this >> " << endl;
    if(argc == 1){ // 没有命令行参数
        ROS_INFO("The vehicle that you will control is single!");
        uavName = "";
    } else if(argc == 2){ // 存在命令行参数, 则 指定操作的飞机
        uavName = argv[1];
        if('/' != uavName[0]){// 如果第一个字符不是 '/'
            uavName = "/" + uavName;
        }
        ROS_INFO(("selected uav:"));	
		    ROS_INFO("%s",(uavName.c_str()));
    } else {
        ROS_ERROR("Incorrect number of parameters!");
        return false;
    }

    cout << "2this >> " << endl;
    ros_sub_and_pub(uavName, &fixed_wing_sub_pub);

    while(ros::ok()){
      ros::spinOnce();
      rate.sleep();
    }

    return true;
}
