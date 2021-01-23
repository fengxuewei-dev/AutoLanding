#pragma once

#include <iostream>
#include <ros/ros.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/AttitudeTarget.h>
#include <mavros_msgs/VFR_HUD.h>
#include <mavros_msgs/OverrideRCIn.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/ParamSet.h>
#include <mavros_msgs/WaypointList.h>
#include <mavros_msgs/HomePosition.h>

#include <sensor_msgs/Imu.h>
#include <sensor_msgs/NavSatFix.h>

#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/TwistWithCovarianceStamped.h>
#include <geometry_msgs/AccelWithCovarianceStamped.h>
#include "fw_msgs/commands.h"
#include "fw_msgs/formations.h"
#include "fw_msgs/position_setpoint_triplet.h"

#include "../../../../lib/logger/LogStream.hpp"
#include "../../../../lib/Macro.hpp"
#include "../../../../lib/mathlib/vector/vector.hpp"
#include "../../../../lib/mathlib/math/mathlib.hpp"
#include "../single/PositionControl_L1_TECS.hpp"
#include "../single/PositionControl_VF.hpp"
#include "../formation/PositionControl_FORMATION.hpp"
#include "../positionController_output.hpp"

#include "fw_msgs/FormationPositionContoller.h"
#include "fw_msgs/Yaw.h"

#include "fw_msgs/uavflag.h"

using std::cout;
using std::end;

#define PITCH_NUMBER 0
#define ROLL_NUMBER 1
#define YAW_NUMBER 2
#define THROTTLE_NUMBER 3

/* subscribe for Position control */

double getDistance(double lon1, double lat1, double lon2, double lat2);

class FixedwingPositionSubAndPub{
    private:
        // 日志保存: 接收的航点值(三个) 和 发布的姿态数据值
        /*
            : currentWaypoint(_alloc)
            , nextWaypoint(_alloc)
            , Throttle(0)
            , ExistNext(0)  
        */
        logStream<double>   log_subscribe_currentWaypoint_x;
        logStream<double>   log_subscribe_currentWaypoint_y;
        logStream<double>   log_subscribe_currentWaypoint_z;
        logStream<double>   log_subscribe_nextWaypoint_x;
        logStream<double>   log_subscribe_nextWaypoint_y;
        logStream<double>   log_subscribe_nextWaypoint_z;
        logStream<double>   log_subscribe_enu_currentWaypoint_x;
        logStream<double>   log_subscribe_enu_currentWaypoint_y;
        logStream<double>   log_subscribe_enu_currentWaypoint_z;
        logStream<double>   log_subscribe_enu_nextWaypoint_x;
        logStream<double>   log_subscribe_enu_nextWaypoint_y;
        logStream<double>   log_subscribe_enu_nextWaypoint_z;
        logStream<float>    log_subscribe_Throttle;
        logStream<int>      log_subscribe_ExistNext;

        logStream<float>   log_publish_roll_setpoint;
        logStream<float>   log_publish_yaw_setpoint;
        logStream<float>   log_publish_pitch_setpoint;
        logStream<float>   log_publish_throttle_setpoint;

        std::string uavName;
        float att_sp[4];
        int serv_port;
        bool isRC;
        bool isSingleFly;
        bool isFormationFly;
        bool isSelfOrganization;
        float airspeed_single;                                         // airspeed setpoint for single 
        float airspeed_tecs;                                           // airspeed setpoint for tecs
        
        PositionControl_L1_TECS Control_L1_TECS;                                  // the single vehicle's control
        PositionControl_VF Control_VF;                                            // the vf control
        PositionControl_FORMATION Control_FORMATION;                                // the formation control
        
        float att_angle_Euler[3];  //无人机当前欧拉角(从飞控中读取) 
        float roll_cmd;
        
        /* increment pid >>> */ 
        float input{0.0};
        float prev_input{0.0};
        float prev2_input{0.0};
        float increment{0.0};
        float output{0.0};
        float prev_output{0.0};
        /* <<< increment pid */

    public:
        FixedwingPositionSubAndPub(std::string);
        ~FixedwingPositionSubAndPub();

        Point get_plane_to_sp_vector(Point origin, Point target);
        void setUavName(std::string);
        std::string getUavName();

        void setPort(int port){ serv_port = port; }
        void setIsRC(bool is){ isRC = is;}
        void setIsSingleFly(){ 
            isSingleFly = true; 
            isFormationFly = false;
            isSelfOrganization = false;
        }
        void setIsFormationFly(){
            isSingleFly = false; 
            isFormationFly = true;
            isSelfOrganization = false;
        }
        void setIsSelfOrganizationFly(){
            isSingleFly = false; 
            isFormationFly = false;
            isSelfOrganization = true;
        }
        void setAirspeed_single(float airspeed){ airspeed_single = airspeed; }
        void setAirspeed_tecs( float airspeed ) {airspeed_tecs = airspeed;}
        // 编队飞行

        ros::NodeHandle nh;

        /* 1. the publishers and subscribers */
        /* subscribe */ 
        ros::Subscriber state_sub;                          // the vehicle state
        ros::Subscriber uav_state_sub;                      // Data for HUD.
        ros::Subscriber uav_localPos_sub;                   // Local position from FCU.
        ros::Subscriber home_sub;                           // the home position 

        
        ros::Subscriber uav_globelPos_sub;                  // global position
        
        ros::Subscriber uav_localVel_sub;                   // ned_vel_x, ned_vel_y, ned_vel_z
        ros::Subscriber uav_imu_sub;                        // the imu information 

        ros::Subscriber uav_windEstimation_sub;             // the wind estimation
        ros::Subscriber uav_localAccel_sub;                 // the local accel
        ros::Subscriber uav_waypoints_sub;                  // the waypoints list
        ros::Subscriber uav_velocity_global_fused;

        ros::Subscriber position_setpoint_triplet_sub;      // receive the data from the navigtor

        ros::Subscriber formationPosition_sub;


	    ros::Publisher formationShap_pub;                   // send the formation date to udp
        ros::Publisher att_sp_pub;                          // publish the data to attitude controller
        ros::Publisher formationYaw_pub; 

        /* 2. the Variables declaration */
        mavros_msgs::State current_state;
        mavros_msgs::VFR_HUD current_UAV_state;
        mavros_msgs::WaypointList waypoint_List;      

        geometry_msgs::PoseStamped pose;
        geometry_msgs::PoseStamped current_localPose;                       
        geometry_msgs::TwistStamped velocity_ned_fused_from_px4;
        geometry_msgs::AccelWithCovarianceStamped acc_ned_from_px4;                   
        geometry_msgs::TwistWithCovarianceStamped wind_estimate_from_px4;
        geometry_msgs::TwistStamped velocity_global_fused_from_px4;        
        
        sensor_msgs::Imu imu;
        sensor_msgs::NavSatFix global_position_form_px4;
        mavros_msgs::HomePosition current_home;

        fw_msgs::position_setpoint_triplet position_setpoint;                                                 // data sources
        fw_msgs::commands setCommands;

        fw_msgs::FormationPositionContoller formationPosition;
        fw_msgs::Yaw formationYaw;

        ros::Subscriber uavflag_sub;
        fw_msgs::uavflag uavflag_state;
        void uavflag_cb(const fw_msgs::uavflag::ConstPtr& msg);
        
        void getRollAndYaw();
        float getRollAndYaw_increment_pid();
        float getRollByYaw();

        void IncrementPid(float, float, float, float);
        float GetFullOutput();

        void publish_2_udp_send(float);
        /* 3. the handle function */
        void formationPositionData_cb(const fw_msgs::FormationPositionContoller::ConstPtr& msg);
        void state_cb(const mavros_msgs::State::ConstPtr& msg);
        void newUAVState(const mavros_msgs::VFR_HUD::ConstPtr& msg);
        void new_localPose(const geometry_msgs::PoseStamped::ConstPtr& msg);
        void waypointlist_from_px4_sub(const mavros_msgs::WaypointList::ConstPtr &msg);
        void velocity_ned_fused_from_px4_cb(const geometry_msgs::TwistStamped::ConstPtr &msg);
        void velocity_global_fused_cb(const geometry_msgs::TwistStamped::ConstPtr &msg);

        void imu_cb(const sensor_msgs::Imu::ConstPtr &msg);
        void wind_estimate_from_px4_cb(const geometry_msgs::TwistWithCovarianceStamped::ConstPtr &msg);
        void acc_ned_from_px4_cb(const geometry_msgs::AccelWithCovarianceStamped::ConstPtr &msg);
        void global_position_form_px4_cb(const sensor_msgs::NavSatFix::ConstPtr &msg);
        void homePosition_cb(const mavros_msgs::HomePosition::ConstPtr& msg);
        void navigator_position_cb(const fw_msgs::position_setpoint_triplet::ConstPtr& msg);

        /* calculation the attitude setpoints according to the control */
        void calculation();
        void get_single_attitude_setpoints();
        void get_l1_tecs_attitude_setpoints();
        void get_formation_attitude_setpoints();
        void self_organization_setpoints();
        float calculationRoll(float);

        
        float get_tecs_throttle();
        float get_single_throttle();
        float get_formation_throttle();

        float get_single_yaw();
        float get_formation_yaw();
        
        void logConfig();
        void WriteLogFile_Subscribe();
        void WriteLogFile_Publish();

        float get_single_roll();
        float get_formation_roll();
        float get_l1_roll();

        // void calculation();
        float cal_pitch();
        float cal_roll();
        float cal_yaw();
        float cal_throttle();

        void Assignment();
        void publishSetpoint();

        void showDataFromUdp();
        void showData();
        void print_navi_setpoint();
        void printInfo();
        void print_wp(const mavros_msgs::Waypoint& wp);
        
};

