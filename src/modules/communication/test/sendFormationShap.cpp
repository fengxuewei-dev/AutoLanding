#include <ros/ros.h>

#include <mavros_msgs/State.h>
#include <mavros_msgs/VFR_HUD.h>
#include <mavros_msgs/ParamValue.h>
#include <mavros_msgs/WaypointList.h>
#include <mavros_msgs/HomePosition.h>

#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/TimeReference.h>

#include <geometry_msgs/PoseStamped.h>

#include "fw_att_control/formations.h"

fw_att_control::formations formationShape;

/* 设置编队形状 */
int main(int argc, char **argv){
    std::string nodeName = "sendFormationShap";
    ros::init(argc, argv, nodeName);

    ros::NodeHandle nh;
    ros::Rate rate(1);

    ros::Time now = ros::Time::now() ;

    if(argc != 2){
        return 0;
    }
    fw_att_control::formations formationShape_;
    formationShape_.formationShape = argv[1];

    std::string uavName1 = "uav1/";
    std::string uavName2 = "uav2/";
    std::string uavName3 = "uav3/";
    std::string uavName4 = "uav4/";
    
    ros::Publisher formationShap1_pub = nh.advertise<fw_att_control::formations>
            (uavName1 + "communication/formation/formationShap", 1);
    ros::Publisher formationShap2_pub = nh.advertise<fw_att_control::formations>
            (uavName2 + "communication/formation/formationShap", 1);
    ros::Publisher formationShap3_pub = nh.advertise<fw_att_control::formations>
            (uavName3 + "communication/formation/formationShap", 1);
    ros::Publisher formationShap4_pub = nh.advertise<fw_att_control::formations>
            (uavName4 + "communication/formation/formationShap", 1);

    while (ros::ok())
    {
        formationShap1_pub.publish(formationShape_);
        formationShap2_pub.publish(formationShape_);
        formationShap3_pub.publish(formationShape_);
        formationShap4_pub.publish(formationShape_);
        ROS_ERROR("shape: %s", formationShape_.formationShape.c_str());
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}