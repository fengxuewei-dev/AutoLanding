#pragma once

#include <math.h>
#include <ros/ros.h>
#include <mavros_msgs/WaypointList.h>
#include "../../../../lib/GPS2Distance/GPS2Distance.hpp"

#ifndef M_PI_2_F
#define M_PI_2_F (M_PI / 2.0f)
#endif

#ifndef ADVANCED_DISTANCE
#define ADVANCED_DISTANCE 70
#endif

static double CONSTANTS_RADIUS_OF_EARTH = 6371000;					// meters (m)
static float  CONSTANTS_RADIUS_OF_EARTH_F = CONSTANTS_RADIUS_OF_EARTH;		// meters (m)

typedef float time_type;

class LoiterMission{
    private:

    public:
        LoiterMission();
        ~LoiterMission();

        time_type _time_first{0}; 
        time_type now{0};

        ros::NodeHandle nh;
        ros::Timer timer;
        
        int sec{0};
        
        bool loiter_wp_dist_reached{false};
        bool loiter_wp_time_reached{false};

        void callback(const ros::TimerEvent&);

        float enu_get_distance_to_next_waypoint(
            double cur_lat, double cur_lon, double cur_alt,
            double nex_lat, double nex_lon, double nex_alt);

        float wrap(float x, float high = 2 * M_PI, float low = 0);

        float radians(float degrees) { return (degrees / 180.0f) * float(M_PI); }
        float degrees(float radians) { return (radians * 180.0f) / float(M_PI); }

        float get_bearing_to_next_waypoint(double lat_now, double lon_now, double lat_next, double lon_next);
        float standard(float val, float min_val, float max_val){return (val < min_val) ? min_val : ((val > max_val) ? max_val : val);}
        void waypoint_from_heading_and_distance(
            double lat_start, double lon_start, 
            float bearing, float dist,
            double *lat_target, double *lon_target
        );

        void is_loiter_mission_reached(
            float dist, float loiter_radius, uint16_t &current_waypoint, float loiter_time
        );
        void is_loiter_mission_reached_no_2_yes(
            float dist,  mavros_msgs::Waypoint& curr_wp, uint16_t  &current_waypoint
        );
        void is_loiter_mission_reached_yes_2_no(
            uint16_t &current_waypoint,float loiter_time 
        );
        float min_distance_curr_next(mavros_msgs::Waypoint& curr_wp, mavros_msgs::Waypoint& next_wp);
        
};