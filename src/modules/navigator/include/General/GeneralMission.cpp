
#include "GeneralMission.hpp"
GeneralMission::GeneralMission(){

}
GeneralMission::~GeneralMission(){
	
}


float GeneralMission::get_default_altitude_acceptance_radius()
{
	return NAV_FW_ALT_RAD;
}

float GeneralMission::get_altitude_acceptance_radius()
{
	return get_default_altitude_acceptance_radius();
}

float GeneralMission::get_loiter_radius() { 
    return NAV_LOITER_RAD;
}

float GeneralMission::get_distance_to_point_global_wgs84(double lat_now, double lon_now, float alt_now,
		double lat_next, double lon_next, float alt_next,
		float *dist_xy, float *dist_z)
{
	double current_x_rad = lat_next / 180.0 * M_PI;
	double current_y_rad = lon_next / 180.0 * M_PI;
	double x_rad = lat_now / 180.0 * M_PI;
	double y_rad = lon_now / 180.0 * M_PI;

	double d_lat = x_rad - current_x_rad;
	double d_lon = y_rad - current_y_rad;

	double a = sin(d_lat / 2.0) * sin(d_lat / 2.0) + sin(d_lon / 2.0) * sin(d_lon / 2.0) * cos(current_x_rad) * cos(x_rad);
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));

	const float dxy = static_cast<float>(CONSTANTS_RADIUS_OF_EARTH_1 * c);
	const float dz = static_cast<float>(alt_now - alt_next);

	*dist_xy = fabsf(dxy);
	*dist_z = fabsf(dz);

	return sqrtf(dxy * dxy + dz * dz);
}

/**
 * @param _mission_item: 手动给定的航点的位置
 * 
 * @param lat
 * @param lon
 * @param alt
 */
bool GeneralMission::is_mission_item_reached(double lat_mission, double lon_mission, double alt_mission, double lat, double lon, double alt)
{
	// all acceptance criteria must be met in the same iteration
	_waypoint_position_reached = false;
	_waypoint_yaw_reached = false;

    ros::Time now = ros::Time::now();

	// 判断是否到达
	if (!_waypoint_position_reached){
		float dist = -1.0f;
		float dist_xy = -1.0f;
		float dist_z = -1.0f;
    
		dist = get_distance_to_point_global_wgs84(lat_mission, lon_mission, alt_mission,
				lat, // 当前ed lat
				lon,
				alt,
				&dist_xy, &dist_z);
        if ((dist >= 0.0f) && (dist_z < get_loiter_radius()) && (dist_xy <= get_loiter_radius() * 1.2f)) 
        {
            _waypoint_position_reached = true;
		}

		
		if (_waypoint_position_reached) {
			// reached just now
			_time_wp_reached = now;
		}
	}
	if (_waypoint_position_reached && !_waypoint_yaw_reached) {
		_waypoint_yaw_reached = true;
	}
	if (_waypoint_position_reached && _waypoint_yaw_reached) {

			return true;
	}
	return  false;
	
}


double GeneralMission::getPositionOnLine(Point Z, Point Start, Point End){
	double chi_f = atan2(End.y - Start.y, End.x - Start.x);   
	
	//Projection of the point Z on the line start-end
    double Z_proj = ((Z.x - Start.x) * (End.x - Start.x) + (Z.y - Start.y) * (End.y - Start.y)) / (pow(End.y - Start.y, 2) + pow(End.x - Start.x, 2)); 

    return Z_proj;
}