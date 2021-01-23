#pragma once

 // ros程序必备头文件
#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h> //GPS Fix.
#include <sensor_msgs/Imu.h>

#include <mavros/frame_tf.h>

#include <geometry_msgs/TwistStamped.h> //Velocity fused by FCU
#include <geometry_msgs/TwistWithCovarianceStamped.h>
#include <geometry_msgs/AccelWithCovarianceStamped.h>

#include <mavros_msgs/VFR_HUD.h>
#include <mavros_msgs/AttitudeTarget.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/Waypoint.h>
#include <mavros_msgs/WaypointList.h>
#include <mavros_msgs/WaypointReached.h>
#include <mavros_msgs/WaypointPush.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/HomePosition.h>
#include <geometry_msgs/PoseStamped.h>


#include <Eigen/Eigen>
#include <Eigen/Geometry>
#include <GeographicLib/Geocentric.hpp>

#include "fw_msgs/commands.h"
#include "fw_msgs/formations.h"
#include "fw_msgs/position_setpoint_triplet.h"
// #include "../formationControl/formationControl.hpp"
#include "positionControl/L1_TECS.hpp"
#include "vf/VF.hpp"
#include "threeDimensionVF/threeDimensionVF.h"
#include "../../../../lib/mathlib/vector/vector.hpp"
#include "../../../../lib/Macro.hpp"
#include "../../../../lib/GPS2Distance/GPS2Distance.hpp"
#include "../positionController_output.hpp"

#include "../../../../lib/parameters/parameters.hpp"

#define RADIUS_DEFAULTS 200

#define LOITERING_TIME 19
#define LOITERING_COMMAND 31
#define LOITER_UNLIM 17

#define GROUNDSPEED_DESIRED 17

typedef mavros_msgs::Waypoint ENU_Waypoint;

class PositionControl_VF{
    private:
        // receive the subcriber
        mavros_msgs::HomePosition home;                                         // home waypoint
        geometry_msgs::PoseStamped current_local_position;                      // local position
        fw_msgs::formations executeFormation;                            // formation shape which will be sent
        mavros_msgs::VFR_HUD current_vfr_hud;                                   // heading， airspeed_vf， groundSpeed

        fw_msgs::position_setpoint_triplet position_setpoint;                       // the setpoint about the tripe waypoints

        mavros_msgs::Waypoint previous_waypoint;
        
        Point currentPosition; 
	    Point wayPointStart; 
	    Point wayPointEnd; 
        VF vectorField;

        sensor_msgs::Imu current_imu;
        Three_Dimensional_Vector TDVF_localPosition; 
	    Three_Dimensional_Vector TDVF_wayPointStart; 
	    Three_Dimensional_Vector TDVF_wayPointEnd; 
        threeDimensionVF TDVF;

        float radius;
        float Yaw;
        double Pitch;
        float Throttle;

        // Euler angles(代表了 yaw， pitch，roll 的角度)
        double psi;                     // yaw
        double theta;                   // pitch
        double phi;                     // roll

        double horizontalDistance;
        double verticalDistance;
        double horizontalSide;
        double verticalSide;

        // 增量式 PID
        double Prev2Err{0};
        double PrevErr{0};
        double Err{0};
        double kp = 16;
        double ki = 8;
        double kd = 4;

        double X_e_min_1;
        double speed_e_min_1 = 0.0f;

    public:
        PositionControl_VF();
        ~PositionControl_VF();

        // get the data for vf controller
        int run(mavros_msgs::HomePosition, geometry_msgs::PoseStamped, mavros_msgs::VFR_HUD, fw_msgs::position_setpoint_triplet, sensor_msgs::Imu, float);
        int run_TECS(mavros_msgs::HomePosition, geometry_msgs::PoseStamped, mavros_msgs::VFR_HUD, fw_msgs::position_setpoint_triplet, float);
        void setPositionSetpoint(fw_msgs::position_setpoint_triplet);
        void setRadius(int R);

        // 84 --> enu
        void getENUoffset(mavros_msgs::Waypoint, mavros_msgs::Waypoint, Eigen::Vector3d*);
        
        // change into the enu
        void GPS_current_transform_ENU(mavros_msgs::Waypoint);
        void GPS_next_transform_ENU();

        void update_parameters();

        void setTriplePoint();
        void ChooseHandler();

        /* Processing logic */ 
        void straight_();
        void orbit_();
        void ThreeDVF_run();
        float getLongiThrottle(double);

        /* get the attitude setpoint */
        float getPitch();
        float getYaw();
        float getRoll();
        float getThrottle();
};
