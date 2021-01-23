/**
 * multi_sitl: 下面进行数据分析的打印节点
*/
#include "../src/TestWaypointlistPub.hpp"
#include "../../lib/logger/LogStream.hpp"
#include "../../lib/mathlib/vector/three_dimensional_vector.hpp"
#include "../../lib/logger/LogStream.hpp"
#include <fw_msgs/position_setpoint_triplet.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/VFR_HUD.h>

logStream<double> uav0_x;
logStream<double> uav0_y;
logStream<double> uav0_Heading;
logStream<double> uav0_Airspeed;
logStream<double> uav0_GroundSpeed;

logStream<double> uav1_x;
logStream<double> uav1_y;
logStream<double> uav1_final_x;
logStream<double> uav1_final_y;
logStream<double> uav1_Heading;
logStream<double> uav1_Airspeed;
logStream<double> uav1_GroundSpeed;

// logStream<double> uav2_x;
// logStream<double> uav2_y;
// logStream<double> uav2_final_x;
// logStream<double> uav2_final_y;

// logStream<double> uav3_x;
// logStream<double> uav3_y;
// logStream<double> uav3_final_x;
// logStream<double> uav3_final_y;

// logStream<double> uav4_x;
// logStream<double> uav4_y;
// logStream<double> uav4_final_x;
// logStream<double> uav4_final_y;

void configuration(std::string uavName_){

    uav0_x.configuration(std::string(LOGGERPATH) + "test", "uav0", "x");
    uav0_y.configuration(std::string(LOGGERPATH) + "test", "uav0", "y");
    uav0_Heading.configuration(std::string(LOGGERPATH) + "test", "uav0", "Heading");
    uav0_Airspeed.configuration(std::string(LOGGERPATH) + "test", "uav0", "AirSpeed");
    uav0_GroundSpeed.configuration(std::string(LOGGERPATH) + "test", "uav0", "GroundSpeed");

    uav1_x.configuration(std::string(LOGGERPATH) + "test", "uav1", "x");
    uav1_y.configuration(std::string(LOGGERPATH) + "test", "uav1", "y");
    uav1_final_x.configuration(std::string(LOGGERPATH) + "test", "uav1", "final_x");
    uav1_final_y.configuration(std::string(LOGGERPATH) + "test", "uav1", "final_y");
    uav1_Heading.configuration(std::string(LOGGERPATH) + "test", "uav1", "Heading");
    uav1_Airspeed.configuration(std::string(LOGGERPATH) + "test", "uav1", "AirSpeed");
    uav1_GroundSpeed.configuration(std::string(LOGGERPATH) + "test", "uav1", "GroundSpeed");

    // uav2_x.configuration(std::string(LOGGERPATH) + "test", "uav2", "x");
    // uav2_y.configuration(std::string(LOGGERPATH) + "test", "uav2", "y");
    // uav2_final_x.configuration(std::string(LOGGERPATH) + "test", "uav2", "final_x");
    // uav2_final_y.configuration(std::string(LOGGERPATH) + "test", "uav2", "final_y");
    
    // uav3_x.configuration(std::string(LOGGERPATH) + "test", "uav3", "x");
    // uav3_y.configuration(std::string(LOGGERPATH) + "test", "uav3", "y");
    // uav3_final_x.configuration(std::string(LOGGERPATH) + "test", "uav3", "final_x");
    // uav3_final_y.configuration(std::string(LOGGERPATH) + "test", "uav3", "final_y");
    
    // uav4_x.configuration(std::string(LOGGERPATH) + "test", "uav4", "x");
    // uav4_y.configuration(std::string(LOGGERPATH) + "test", "uav4", "y");
    // uav4_final_x.configuration(std::string(LOGGERPATH) + "test", "uav4", "final_x");
    // uav4_final_y.configuration(std::string(LOGGERPATH) + "test", "uav4", "final_y");
}

// 获取 local 位置
geometry_msgs::PoseStamped current_localPose0;
void new_localPose0(const geometry_msgs::PoseStamped::ConstPtr& msg){
    current_localPose0 = *msg;
    uav0_x.logPrint(current_localPose0.pose.position.x);
    uav0_y.logPrint(current_localPose0.pose.position.y);
}
geometry_msgs::PoseStamped current_localPose1;
void new_localPose1(const geometry_msgs::PoseStamped::ConstPtr& msg){
    current_localPose1 = *msg;
    uav1_x.logPrint(current_localPose1.pose.position.x);
    uav1_y.logPrint(current_localPose1.pose.position.y);
}
// geometry_msgs::PoseStamped current_localPose2;
// void new_localPose2(const geometry_msgs::PoseStamped::ConstPtr& msg){
//     current_localPose2 = *msg;
//     uav2_x.logPrint(current_localPose2.pose.position.x);
//     uav2_y.logPrint(current_localPose2.pose.position.y);
// }
// geometry_msgs::PoseStamped current_localPose3;
// void new_localPose3(const geometry_msgs::PoseStamped::ConstPtr& msg){
//     current_localPose3 = *msg;
//     uav3_x.logPrint(current_localPose3.pose.position.x);
//     uav3_y.logPrint(current_localPose3.pose.position.y);
// }
// geometry_msgs::PoseStamped current_localPose4;
// void new_localPose4(const geometry_msgs::PoseStamped::ConstPtr& msg){
//     current_localPose4 = *msg;
//     uav4_x.logPrint(current_localPose4.pose.position.x);
//     uav4_y.logPrint(current_localPose4.pose.position.y);
// }
fw_msgs::position_setpoint_triplet final_localPose1;
void new_finalPose1(const fw_msgs::position_setpoint_triplet::ConstPtr& msg){
    final_localPose1 = *msg;

    uav1_final_x.logPrint(final_localPose1.nextWaypoint.x_lat);
    uav1_final_y.logPrint(final_localPose1.nextWaypoint.y_long);
}
// fw_msgs::position_setpoint_triplet final_localPose2;
// void new_finalPose2(const fw_msgs::position_setpoint_triplet::ConstPtr& msg){
//     final_localPose2 = *msg;
//     uav2_final_x.logPrint(final_localPose2.nextWaypoint.x_lat);
//     uav2_final_y.logPrint(final_localPose2.nextWaypoint.y_long);
// }
// fw_msgs::position_setpoint_triplet final_localPose3;
// void new_finalPose3(const fw_msgs::position_setpoint_triplet::ConstPtr& msg){
//     final_localPose3 = *msg;
//     uav3_final_x.logPrint(final_localPose3.nextWaypoint.x_lat);
//     uav3_final_y.logPrint(final_localPose3.nextWaypoint.y_long);
// }
// fw_msgs::position_setpoint_triplet final_localPose4;
// void new_finalPose4(const fw_msgs::position_setpoint_triplet::ConstPtr& msg){
//     final_localPose4 = *msg;
//     uav4_final_x.logPrint(final_localPose4.nextWaypoint.x_lat);
//     uav4_final_y.logPrint(final_localPose4.nextWaypoint.y_long);
// }
mavros_msgs::VFR_HUD current_UAV0_state;
void newUAVState0(const mavros_msgs::VFR_HUD::ConstPtr& msg){   
    current_UAV0_state = *msg;
    uav0_Heading.logPrint(current_UAV0_state.heading);
    uav0_Airspeed.logPrint(current_UAV0_state.airspeed);
    uav0_GroundSpeed.logPrint(current_UAV0_state.groundspeed);
}
mavros_msgs::VFR_HUD current_UAV1_state;
void newUAVState1(const mavros_msgs::VFR_HUD::ConstPtr& msg){   
    current_UAV1_state = *msg;
    uav1_Heading.logPrint(current_UAV1_state.heading);
    uav1_Airspeed.logPrint(current_UAV1_state.airspeed);
    uav1_GroundSpeed.logPrint(current_UAV1_state.groundspeed);
}
int main(int argc, char **argv){
    
    ros::init(argc, argv, "TestMap");
    ros::NodeHandle nh;
    ros::Rate rate(20);

    std::string uavName = "";

    configuration(uavName);

    // 1, 获得航点
    ros::Subscriber uav_localPos_sub0 = nh.subscribe<geometry_msgs::PoseStamped>
            ("uav0/mavros/local_position/pose",1,new_localPose0);
    ros::Subscriber uav_localPos_sub1 = nh.subscribe<geometry_msgs::PoseStamped>
            ("uav1/mavros/local_position/pose",1,new_localPose1);
    // ros::Subscriber uav_localPos_sub2 = nh.subscribe<geometry_msgs::PoseStamped>
    //         ("uav2/mavros/local_position/pose",1,new_localPose2);
    // ros::Subscriber uav_localPos_sub3 = nh.subscribe<geometry_msgs::PoseStamped>
    //         ("uav3/mavros/local_position/pose",1,new_localPose3);
    // ros::Subscriber uav_localPos_sub4 = nh.subscribe<geometry_msgs::PoseStamped>
    //         ("uav4/mavros/local_position/pose",1,new_localPose4);


    ros::Subscriber uav_vfr_sub0 = nh.subscribe<mavros_msgs::VFR_HUD>
            ("uav0/mavros/vfr_hud",1,newUAVState0);
    ros::Subscriber uav_vfr_sub1 = nh.subscribe<mavros_msgs::VFR_HUD>
            ("uav1/mavros/vfr_hud",1,newUAVState1);

    // publish the data to position controller
    ros::Subscriber uav_final_sub1 = nh.subscribe<fw_msgs::position_setpoint_triplet>
            ("uav1/navigator/position_sp_triplet", 1, new_finalPose1);
    // ros::Subscriber uav_final_sub2 = nh.subscribe<fw_msgs::position_setpoint_triplet>
    //         ("uav2/navigator/position_sp_triplet", 1, new_finalPose2);
            
    // ros::Subscriber uav_final_sub3 = nh.subscribe<fw_msgs::position_setpoint_triplet>
    //         ("uav3/navigator/position_sp_triplet", 1, new_finalPose3);
            
    // ros::Subscriber uav_final_sub4 = nh.subscribe<fw_msgs::position_setpoint_triplet>
    //         ("uav4/navigator/position_sp_triplet", 1, new_finalPose4);
            
            
    while(ros::ok()){
        ROS_INFO("getData");
        ros::spinOnce();
        rate.sleep();
    }
    

    return 0;
}