#pragma once

#include <iostream>
#include <unistd.h>
#include <ros/ros.h>

#include <mavros_msgs/VFR_HUD.h>
#include <mavros_msgs/WaypointList.h>
#include <mavros_msgs/WaypointReached.h>
#include <mavros_msgs/HomePosition.h>

#include <Eigen/Eigen>
#include <Eigen/Geometry>
#include <GeographicLib/Geocentric.hpp>

// get the GPS time
#include <sensor_msgs/TimeReference.h>

#include <mavros/frame_tf.h>

#include <geometry_msgs/PoseStamped.h>

#include "fw_msgs/position_setpoint_triplet.h"

#include "../Loiter/LoiterMission.hpp"
#include "../General/GeneralMission.hpp"

#include "fw_msgs/FormationNavigator.h"

#include "fw_msgs/uavflag.h"

#include "../../../../lib/GPS2Distance/GPS2Distance.hpp"

#include "../../../../lib/Macro.hpp"          // Macro defined 

#include "../PathManger/algorithms.hpp"
#include "../../../../lib/logger/LoggerMatlab.hpp"
#include "../navigator_output.hpp"

#define _SPEED_DEFALUT_ 17
#define DISTANCE_PERCENTAGE 0.9
#define NULLDATA -1

#define UAVNUMBER 40
#define WORKNUMBER 2
#define GROUPNUMBER 4

class NavigatorSubAndPub{
    private:	
        // 日志保存: 发送航点值(三个), 
        logger_leader       logger_Leader;                      // 保留主机的位置
        logger_follower     logger_Follower;                    // 保留从机的计算期望位置的数据

        GeneralMission generalMission;
        LoiterMission loiterMission;
        
        /* If the last waypoint is reached, new_previous_sq and new_current_sq are equal */
        uint16_t new_previous_sq;                           // the previous waypoing's number
        uint16_t new_current_sq;                            // the current(target) waypoing's number

        Point gap{0,0};

        std::string uavName;

        Algorithms algorithms;

        bool isRC{false};
        bool isOffboard{false};

        int i = 0;

        bool GetNewWaypointList{false};
    public:
        NavigatorSubAndPub(std::string);
        ~NavigatorSubAndPub();

        std::string getUavName();

        ros::NodeHandle nh;

        ros::Subscriber uav_home_sub;                       // get the home position
        ros::Subscriber uav_state_sub;
        ros::Subscriber uav_waypoints_sub;                  // the waypoints list
        ros::Subscriber uav_localPos_sub;
	    ros::Subscriber uav_gpsTime_sub;

        ros::Subscriber uavflag_sub;

        /* for the formation */
        // enu 下面， 那么对应的是 x 正东， y 正北
        ros::Subscriber formationNavigator_sub;


        ros::Publisher position_setpoint_triplet_pub;

        ros::Time now;

        mavros_msgs::VFR_HUD current_UAV_state;  
        mavros_msgs::HomePosition leader_home;
        mavros_msgs::HomePosition current_home;
        mavros_msgs::WaypointList waypoint_List;  
        mavros_msgs::WaypointList pre_waypoint_List;      
        mavros_msgs::WaypointList enu_waypoint_List;   
        mavros_msgs::WaypointList gps_waypoint_List;   
        geometry_msgs::PoseStamped leader_position;                                 // the position for the formation
        geometry_msgs::PoseStamped current_localPose;
        sensor_msgs::TimeReference Gps_time;
        fw_msgs::FormationNavigator formationNavigator;

        fw_msgs::position_setpoint_triplet position_setpoint;
        fw_msgs::uavflag uavflag_state;

        
        void formationNavigator_cb(const fw_msgs::FormationNavigator::ConstPtr& msg);
        void newUAVState(const mavros_msgs::VFR_HUD::ConstPtr& msg);
        void waypointlist_sub(const mavros_msgs::WaypointList::ConstPtr &msg);
        void new_localPose(const geometry_msgs::PoseStamped::ConstPtr& msg);
        void homePosition_cb(const mavros_msgs::HomePosition::ConstPtr& msg);
        void newGpsTime(const sensor_msgs::TimeReference::ConstPtr& msg);

        void GPS_transform_ENU();
        void GPS_update();                // 更新航点列表 为了给offboard使用
        void setIsRC(bool is){
            isRC = is;
            isOffboard = !is;
        }
        void setIsOffboard(bool is){
            isRC = !is;
            isOffboard = is;
        }
        uint16_t getNew_current_sq(){
            return new_current_sq;
        }
        uint16_t getNew_previous_sq(){
            return new_previous_sq;
        }
        int getI(){
            return i;
        }
        bool getFlagGetNewWaypointList(){
            return GetNewWaypointList;
        }
        void getENUoffset(mavros_msgs::Waypoint startlistposition, mavros_msgs::Waypoint endlistposition, Eigen::Vector3d* enu_offset);
        bool isExitNextWaypoint();
        void showDataFrom_udp();

        void uavflag_cb(const fw_msgs::uavflag::ConstPtr& msg);

        // for the formation 
        Point calculate_time_error();
        Point calculate_configuration_error();
        void getWaypoint_formation();
        void setGap();

        /* add the home waypoint to the new waypoint list */
        void updateWaypointList();
        /* the logic of waypoint switch */
        void choose_position_setpoints();
        void WaypointSwitch();
        void WaypointSwitch_offboard();

        void Gerenal_2_General();
        void Gerenal_2_Loiter();

        void Loiter_2_Anything(float);
        void Loiter_2_General();

        void straight_2_straight();
        double enu_get_distance_xy_to_next_waypoint( double cur_lat, double cur_lon,
    double nex_lat, double nex_lon);

        int  getWaypointExecuted();
        int  getWaypointExecuting();

        void setPoistionSetpoint();
        void setPoistionSetpoint_TECS();
        void setPoistionSetpoint_formation();
        void publishPositionTriplet();

        void WriteLogFile();

        void print_wp(const mavros_msgs::Waypoint&);
        void showData();
        void printInfo();

        void singleWriteLog();                          // 打印主机的当前local位置
        void formationWriteLog();                       // 打印从机的当前local位置
        void formationWriteLogOthers();                 // 打印从机的期望位置 gap值
        void singleGPSWaypointListLog(mavros_msgs::Waypoint);                   // 打印主机的gps航点信息
        void singleENUWaypointListLog(mavros_msgs::Waypoint);                   // 打印主机转换之后的enu航点数据


        bool isSameWaypointLists(const mavros_msgs::WaypointList, const mavros_msgs::WaypointList);
};
