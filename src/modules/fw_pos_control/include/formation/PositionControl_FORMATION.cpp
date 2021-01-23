#include "PositionControl_FORMATION.hpp"

PositionControl_FORMATION::PositionControl_FORMATION(){
	
}
PositionControl_FORMATION::~PositionControl_FORMATION(){

}
void PositionControl_FORMATION::run(
	mavros_msgs::Waypoint current_waypoint,
	mavros_msgs::VFR_HUD follower_state,
	geometry_msgs::PoseStamped follower_pose,
	double leaderHeading, 
	double leaderYaw, 
	double leaderSpeed
){

	
	Final_waypoint = current_waypoint;

	// 设置目标的位置
	followerFinalPoint.update(Final_waypoint.x_lat, Final_waypoint.y_long);
	followerPosition.update(follower_pose.pose.position.x, follower_pose.pose.position.y);
	
	leaderHeading = (-(leaderHeading) * (M_PI/180.0)) +M_PI/2.0, 
	followerHeading = (-(follower_state.heading) * (M_PI/180.0)) + M_PI/2.0;

	formationcontrol.compute(
		followerFinalPoint, 								// the current waypoint that is executing 
		followerPosition,  
		leaderHeading, 
		followerHeading,
		leaderYaw + M_PI/2.0, 
		leaderSpeed
	);
}

long PositionControl_FORMATION::getCurrentTime()  
{  
   // 获得时间 ms
   struct timeval tv;  
   gettimeofday(&tv,NULL);  
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;  
} 

float PositionControl_FORMATION::getYaw(){
	return formationcontrol.getHeadingSetpoint() - M_PI/2;
}

float PositionControl_FORMATION::getThrottle(){
	return formationcontrol.getGroundSpeedSetpoint(); 
}
float PositionControl_FORMATION::getPitch(){
	return Final_waypoint.z_alt;
}
