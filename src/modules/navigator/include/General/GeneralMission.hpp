#pragma once

#include <ros/ros.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>

#include "../../../../lib/mathlib/vector/vector.hpp"

enum NAV_CMD {
	NAV_CMD_IDLE = 0,
	NAV_CMD_WAYPOINT = 16,
	NAV_CMD_LOITER_UNLIMITED = 17,
	NAV_CMD_LOITER_TIME_LIMIT = 19,
	NAV_CMD_RETURN_TO_LAUNCH = 20,
	NAV_CMD_LAND = 21,
	NAV_CMD_TAKEOFF = 22,
	NAV_CMD_LOITER_TO_ALT = 31,
	NAV_CMD_DO_FOLLOW_REPOSITION = 33,
	NAV_CMD_VTOL_TAKEOFF = 84,
	NAV_CMD_VTOL_LAND = 85,
	NAV_CMD_DELAY = 93,
	NAV_CMD_DO_JUMP = 177,
	NAV_CMD_DO_CHANGE_SPEED = 178,
	NAV_CMD_DO_SET_HOME = 179,
	NAV_CMD_DO_SET_SERVO = 183,
	NAV_CMD_DO_LAND_START = 189,
	NAV_CMD_DO_SET_ROI_LOCATION = 195,
	NAV_CMD_DO_SET_ROI_WPNEXT_OFFSET = 196,
	NAV_CMD_DO_SET_ROI_NONE = 197,
	NAV_CMD_DO_SET_ROI = 201,
	NAV_CMD_DO_DIGICAM_CONTROL = 203,
	NAV_CMD_DO_MOUNT_CONFIGURE = 204,
	NAV_CMD_DO_MOUNT_CONTROL = 205,
	NAV_CMD_DO_SET_CAM_TRIGG_INTERVAL = 214,
	NAV_CMD_DO_SET_CAM_TRIGG_DIST = 206,
	NAV_CMD_SET_CAMERA_MODE = 530,
	NAV_CMD_IMAGE_START_CAPTURE = 2000,
	NAV_CMD_IMAGE_STOP_CAPTURE = 2001,
	NAV_CMD_DO_TRIGGER_CONTROL = 2003,
	NAV_CMD_VIDEO_START_CAPTURE = 2500,
	NAV_CMD_VIDEO_STOP_CAPTURE = 2501,
	NAV_CMD_DO_VTOL_TRANSITION = 3000,
	NAV_CMD_FENCE_RETURN_POINT = 5000,
	NAV_CMD_FENCE_POLYGON_VERTEX_INCLUSION = 5001,
	NAV_CMD_FENCE_POLYGON_VERTEX_EXCLUSION = 5002,
	NAV_CMD_FENCE_CIRCLE_INCLUSION = 5003,
	NAV_CMD_FENCE_CIRCLE_EXCLUSION = 5004,
	NAV_CMD_INVALID = UINT16_MAX /* ensure that casting a large number results in a specific error */
};


struct mission_item_s {
	double lat;					/**< latitude in degrees				*/
	double lon;					/**< longitude in degrees				*/
	union {
		struct {
			union {
				float time_inside;		/**< time that the MAV should stay inside the radius before advancing in seconds */
				float pitch_min;		/**< minimal pitch angle for fixed wing takeoff waypoints */
				float circle_radius;		/**< geofence circle radius in meters (only used for NAV_CMD_NAV_FENCE_CIRCLE*) */
			};
			float acceptance_radius;		/**< default radius in which the mission is accepted as reached in meters */
			float loiter_radius;			/**< loiter radius in meters, 0 for a VTOL to hover, negative for counter-clockwise */
			float yaw;				/**< in radians NED -PI..+PI, NAN means don't change yaw		*/
			float ___lat_float;			/**< padding */
			float ___lon_float;			/**< padding */
			float altitude;				/**< altitude in meters	(AMSL)			*/
		};
		float params[7];				/**< array to store mission command values for MAV_FRAME_MISSION ***/
	};

	uint16_t nav_cmd;				/**< navigation command					*/

	int16_t do_jump_mission_index;			/**< index where the do jump will go to                 */
	uint16_t do_jump_repeat_count;			/**< how many times do jump needs to be done            */

	union {
		uint16_t do_jump_current_count;			/**< count how many times the jump has been done	*/
		uint16_t vertex_count;				/**< Polygon vertex count (geofence)	*/
		uint16_t land_precision;			/**< Defines if landing should be precise: 0 = normal landing, 1 = opportunistic precision landing, 2 = required precision landing (with search)	*/
	};

	struct {
		uint16_t frame : 4,				/**< mission frame */
			 origin : 3,				/**< how the mission item was generated */
			 loiter_exit_xtrack : 1,		/**< exit xtrack location: 0 for center of loiter wp, 1 for exit location */
			 force_heading : 1,			/**< heading needs to be reached */
			 altitude_is_relative : 1,		/**< true if altitude is relative from start point	*/
			 autocontinue : 1,			/**< true if next waypoint should follow after this one */
			 vtol_back_transition : 1,		/**< part of the vtol back transition sequence */
			 _padding0 : 4;				/**< padding remaining unused bits  */
	};

	uint8_t _padding1[2];				/**< padding struct size to alignment boundary  */
};


class GeneralMission{
	private:
		bool _waypoint_position_reached{false};
		bool _waypoint_yaw_reached{false};

		float NAV_FW_ALT_RAD{10.0f};
		float NAV_LOITER_RAD{50.0f};
		double CONSTANTS_RADIUS_OF_EARTH_1{6371000};
		double CONSTANTS_RADIUS_OF_EARTH_F_1{CONSTANTS_RADIUS_OF_EARTH_1};

		struct mission_item_s _mission_item{};
		ros::Time _time_wp_reached{0};

	public:
		GeneralMission();
		~GeneralMission();

		float get_loiter_radius();
		float get_altitude_acceptance_radius();
		float get_default_altitude_acceptance_radius();
		float get_distance_to_point_global_wgs84(
				double lat_now, double lon_now, float alt_now,
				double lat_next, double lon_next, float alt_next,
				float *dist_xy, float *dist_z
		);
		
		double getPositionOnLine(Point Z, Point Start, Point End);

		bool is_mission_item_reached(double lat_mission, double lon_mission, double alt_mission, double lat, double lon, double alt);

		
};