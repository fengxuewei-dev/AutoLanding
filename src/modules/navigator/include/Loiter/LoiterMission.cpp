#include "LoiterMission.hpp"


LoiterMission::LoiterMission(){
    _time_first = sec;
    timer = nh.createTimer(ros::Duration(1.2), boost::bind(&LoiterMission::callback, this, _1)); 
}

LoiterMission::~LoiterMission(){
    
}


void LoiterMission::callback(const ros::TimerEvent&)
{
    ++sec;
}
float LoiterMission::enu_get_distance_to_next_waypoint(
    double cur_lat, double cur_lon, double cur_alt,
    double nex_lat, double nex_lon, double nex_alt
){
    return sqrt( 
            (cur_lat - nex_lat) * (cur_lat - nex_lat) + 
            (cur_lon - nex_lon) * (cur_lon - nex_lon) + 
            (cur_alt - nex_alt) * (cur_alt - nex_alt)
        );
}
float LoiterMission::wrap(float x, float high, float low) {
    // already in range
    if (low <= x && x < high) {
        return x;
    }

    const float range = high - low;
    const float inv_range = float(1) / range; // should evaluate at compile time, multiplies below at runtime
    // 向下取整
    const float num_wraps = floor((x - low) * inv_range);
    return x - range * num_wraps;
}

float LoiterMission::get_bearing_to_next_waypoint(double lat_now, double lon_now, double lat_next, double lon_next){
	const double lat_now_rad = radians(lat_now);
	const double lat_next_rad = radians(lat_next);

	const double cos_lat_next = cos(lat_next_rad);
	const double d_lon = radians(lon_next - lon_now);

	/* conscious mix of double and float trig function to maximize speed and efficiency */
	const float y = float(sin(d_lon) * cos_lat_next);
	const float x = float(cos(lat_now_rad) * sin(lat_next_rad) - sin(lat_now_rad) * cos_lat_next * cos(d_lon));

	return wrap(atan2f(y, x), M_PI);
}
void LoiterMission::waypoint_from_heading_and_distance(
    double lat_start, double lon_start, 
    float bearing, float dist,
	double *lat_target, double *lon_target
)
{
	bearing = wrap(bearing, 2 * M_PI);
	double radius_ratio = (double)fabs((double)dist) / CONSTANTS_RADIUS_OF_EARTH;

	double lat_start_rad = radians(lat_start);
	double lon_start_rad = radians(lon_start);

	*lat_target = asin(sin(lat_start_rad) * cos(radius_ratio) + cos(lat_start_rad) * sin(radius_ratio) * cos((double)bearing));
	*lon_target = lon_start_rad + atan2(sin((double)bearing) * sin(radius_ratio) * cos(lat_start_rad),
					    cos(radius_ratio) - sin(lat_start_rad) * sin(*lat_target));

	*lat_target = degrees(*lat_target);
	*lon_target = degrees(*lon_target);
}
/**
 * @param dist                  飞机当前的位置和下一个loiter航点的距离, 函数内部会进行更新  
 * @param loiter_radius         当前loiter航点的盘旋半径
 * @param current_waypoint      当前的航点的下标                   ======> 如果当前的航点已经过去 到达下一个航点
 * 
 * @param now                   当前的盘旋时间
 * @param _time_first           进入盘旋的时间
 * @param init_time_first       航点到达之后开始初始化盘旋时间 标志位   ==========> 
 * 
 * @param curr_wp               当前loiter的航点
 * @param next_wp               下一个航点
*/
void LoiterMission::is_loiter_mission_reached(
    float dist, float loiter_radius, uint16_t &current_waypoint, float loiter_time
)
{
    ROS_ERROR("Calculate the time");

    now = sec;
    cout << "_time_first: " << _time_first << endl;
    cout << "now: " << now << endl;
    cout << "now - _time_first: " << now - _time_first << " (<) " << "loiter_time: " << loiter_time << endl;
    cout << "distance reached: " << loiter_wp_dist_reached << endl;
    cout << "time reached: " << loiter_wp_time_reached << endl;

    int loiter_direction = loiter_radius > 0 ? 1 : 0;
    if (!loiter_wp_dist_reached)
    {
        if( dist >= 0.0f && dist <= (abs(loiter_radius) * 1.2f + ADVANCED_DISTANCE) ){
            loiter_wp_dist_reached = true; // 距离到达
            _time_first = now;
        }
    }
    if(loiter_wp_dist_reached && !loiter_wp_time_reached){
        if ( now - _time_first >= loiter_time){ // 达到盘旋时间
            // 不进行计算, 直接获得时间的标志
            loiter_wp_time_reached = true;
            // loiter_wp_dist_reached = false; 
         }
    }
    if(loiter_wp_time_reached && loiter_wp_dist_reached){
        // 当前的盘旋时间和距离都已经达到目标
        current_waypoint++; // 到下一个航点
        _time_first = now;  // 

        // 重置 loiter_wp_time_reached
        loiter_wp_time_reached = false;
        loiter_wp_dist_reached = false;
    }
}



void LoiterMission::is_loiter_mission_reached_no_2_yes(
    float dist, mavros_msgs::Waypoint& curr_wp, uint16_t &current_waypoint
)
{
    now = sec;
    
    int loiter_radius = curr_wp.param3; 
    
    int loiter_direction = loiter_radius > 0 ? 1 : 0;

    if(!loiter_wp_dist_reached)
    {
        if (dist >= 0.0f && dist <= (abs(loiter_radius) * 1.2f + ADVANCED_DISTANCE))
        {
            loiter_wp_dist_reached = true; // 距离到达
            current_waypoint++;
            _time_first = now;
        }
    } 
}
float LoiterMission::min_distance_curr_next(
    mavros_msgs::Waypoint& curr_wp, mavros_msgs::Waypoint& next_wp
)
{
    float min{0};

    // 1. 获得旋转半径
    float radius_curr = curr_wp.param3;
    float radius_next = next_wp.param3;

    // 2. 计算两个航点的距离
    float distance_curr_to_next = enu_get_distance_to_next_waypoint(
        curr_wp.x_lat, curr_wp.y_long, curr_wp.z_alt,
        next_wp.x_lat, next_wp.y_long, next_wp.z_alt        
    );
    
    // 3. 最短距离应该是两点连线上
    min = distance_curr_to_next - radius_curr;
    return min;
}
void LoiterMission::is_loiter_mission_reached_yes_2_no(
    uint16_t &current_waypoint,float loiter_time 
){

    now = sec;
    // 1. 首先判断距离
    
    // 2. 
    if(!loiter_wp_time_reached){
         if ( now - _time_first >= loiter_time){ // 达到盘旋时间
            // 不进行计算, 直接获得时间的标志
            loiter_wp_time_reached = true;
            loiter_wp_dist_reached = false;
        }
    }
    else if(loiter_wp_time_reached && loiter_wp_dist_reached)
    {
        // 盘旋到达
        current_waypoint++;
        _time_first = now;
        loiter_wp_time_reached = false; // 复位
        loiter_wp_dist_reached = false; // 复位
    }

}
