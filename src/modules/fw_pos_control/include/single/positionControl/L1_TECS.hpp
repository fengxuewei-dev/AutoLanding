#pragma once

#include <ros/ros.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <sensor_msgs/NavSatFix.h> //GPS Fix.
#include <sensor_msgs/Imu.h>

#include <geometry_msgs/TwistStamped.h> //Velocity fused by FCU
#include <geometry_msgs/TwistWithCovarianceStamped.h>
#include <geometry_msgs/AccelWithCovarianceStamped.h>

#include <mavros_msgs/VFR_HUD.h>
#include <mavros_msgs/AttitudeTarget.h>
#include <mavros_msgs/Waypoint.h>
#include <mavros_msgs/WaypointList.h>

#include "TECS/tecs.hpp"
#include "fw_msgs/commands.h"
#include "../speed/speed_sp/speed_sp.hpp"
#include "../../../../../lib/mathlib/mathlib.h"
#include "../../../../../lib/mathlib/vector/vector.hpp"

typedef struct _s_control_lateral_params
{
    float kp{0.1};
    float kd{0.1};
}L1_params;
typedef struct _s_vehicle_status
{
    string mode;

    float ned_vel_x{0};
    float ned_vel_y{0};
    float ned_vel_z{0};

    double latitude{0};
	double altitude{0};
	double longtitude{0};

    float air_speed{0};
    float ground_speed{0};

    float wind_estimate_x{-20000};
    float wind_estimate_y{-20000};
	float wind_estimate_z{-20000};

    float rotmat[3][3];

    float ned_acc[3];

    float body_acc[3];

    float pitch_angle{-20000};
    float yaw_angle{-20000};
	float roll_angle{-20000};

    bool altitude_lock{false};
	bool in_air{true};

}Vehicle_Status;
typedef struct _s_vehicle_setpiont
{
    string mode;

	float ground_speed_ned_param1{0};

	float ground_speed_ned_param2{0};

	float global_vel_x{0};
	float global_vel_y{0};
	float global_vel_z{0};

    float air_speed{0};

	float relative_hight{0};

	double latitude{0};
	double altitude{0};
	double longtitude{0};

	double relative_alt{0};
	float ned_pos_x{0};
    float ned_pos_y{0};
    float ned_pos_z{0};

	float ned_vel_x{0};
	float ned_vel_y{0};
	float ned_vel_z{0};

	float ned_acc_x{0};
    float ned_acc_y{0};
	float ned_acc_z{0};

	float body_acc_x{0};
	float body_acc_y{0};
	float boday_acc_z{0};

	float pitch_angle{0};
	float yaw_angle{0};
	float roll_angle{0};
	float thrust{0};

    mavros_msgs::WaypointList waypointList;

}Vehicle_Setpiont;
//, leader_setpoint, sp_to_send;

typedef struct _s_vehicle_error
	{
		double latitude{0};

		double altitude{0};

		double longtitude{0};

		float n_distance{0};

		float e_distance{0};

		float Xb_distance{0};

		float Yb_distance{0};

		float airspeed{0};

		float groundspeed{0};

		float distance_level{0};

		float distance_vertical{0};

		float distance_3d{0};

		float ned_vel_x{0};

		float ned_vel_y{0};

		float vel_led_fol_x{0};

		float vel_led_fol_y{0};

		float vel_led_fol_z{0};

	}Vehicle_Error;

typedef struct _s_fixed_wing_params
	{
		int EAS2TAS{1};

		bool climboutdem{false};

		float climbout_pitch_min_rad{0.2};

		float throttle_min{0.1};

		float throttle_max{1};

		float throttle_cruise{0.1};

		float pitch_min_rad{-0.5};

		float pitch_max_rad{0.5};

		float speed_weight{1};

		float time_const_throt{1.0};

		float time_const{5.0};

		float roll_max{PI / 2};
	} Fixed_Wing_Params;

class L1_TECS{
	private:
    	ros::Subscriber fixed_wing_global_position_form_px4_sub_uav1;
    	ros::Subscriber fixed_wing_velocity_ned_fused_from_px4_sub;
	    ros::Subscriber fixed_wing_imu_sub;
	    ros::Subscriber fixed_wing_wind_estimate_from_px4_sub;
	    ros::Subscriber fixed_wing_air_ground_speed_from_px4_sub;
    	ros::Subscriber fixed_wing_states_sub;
    	ros::Subscriber fixed_wing_acc_ned_from_px4_sub;


	public:
		L1_TECS();
		ros::Time begin_time;

		ros::NodeHandle nh;
        float track_vel_k{1};
        float acc_lateral{0};
        float _nav_bearing;
        float _lateral_accel{0};
        float _K_L1{2};
        float _roll_lim_rad{deg_2_rad(60)};
        float roll_sp{0};
        float _L1_period{25};
        float _L1_ratio{5.0};
        float _L1_damping{0.75};
        float _L1_distance{20.0};

        string control_mode_prev;
        string control_mode_current;
        string control_mode_prev_sp;
        string control_mode_current_sp;

        float current_time{0};

        TECS _tecs;
        SPEED_SP _speed_sp;
        mavros_msgs::AttitudeTarget att_sp;
        fw_msgs::commands setCommands;

		Vehicle_Status vehicle_status;
		Vehicle_Setpiont vehicle_setpoint;
		Vehicle_Setpiont sp_to_send;
		Vehicle_Error error_vehicle;
		Fixed_Wing_Params params;

		sensor_msgs::Imu imu;
		float q[4];
		float att_angle_Euler[3];  //无人机当前欧拉角(从飞控中读取)

		sensor_msgs::NavSatFix global_position_form_px4;
		geometry_msgs::TwistStamped velocity_ned_fused_from_px4;
		mavros_msgs::VFR_HUD air_ground_speed_from_px4;
		geometry_msgs::TwistWithCovarianceStamped wind_estimate_from_px4;

		/*  set */
		void setImu(const sensor_msgs::Imu msg);
		void setAirGroundSpeed(const mavros_msgs::VFR_HUD msg);
		void setGlobalPosition(const sensor_msgs::NavSatFix msg);
		void setVelocityNed(const geometry_msgs::TwistStamped msg);
		void setWindEstimate(const geometry_msgs::TwistWithCovarianceStamped msg);
		void update_rotmat();

		Point get_local_planar_vector(Point origin, Point target);

		void run(mavros_msgs::Waypoint, sensor_msgs::NavSatFix, geometry_msgs::TwistStamped, sensor_msgs::Imu, geometry_msgs::TwistWithCovarianceStamped,mavros_msgs::VFR_HUD,float);

		void air_ground_speed_from_px4_cb(const mavros_msgs::VFR_HUD msg);

		void dataConfirguration(mavros_msgs::Waypoint,float);
		void control_vertical(float current_time);
		void control_lateral(float current_time);
		
		float get_ros_time(ros::Time begin);
		float lateral_L1_modified(Point curr_pos, Point sp_pos, Point ground_speed_2d);
};
