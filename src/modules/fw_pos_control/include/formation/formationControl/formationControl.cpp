#include "formationControl.hpp"

formationControl::formationControl(float new_c1, float new_c2, double new_alpha):before_final_position(-1, -1)
{
    c1 = new_c1;
    c2 = new_c2;
    alpha = new_alpha;
}

formationControl::~formationControl()
{
}

formationControl::formationControl(){
    
}
/*
    	followerFinalPoint, 								// the current waypoint that is executing 
		followerPosition,  
		leaderHeading, 
		followerHeading,
		leaderYaw + M_PI/2.0, 
		leaderSpeed

	leaderHeading = (-(leaderHeading) * (M_PI/180.0)) +M_PI/2.0, 
	followerHeading = (-(follower_state.heading) * (M_PI/180.0)) + M_PI/2.0;

*/

void formationControl::compute(
    Point followerFinalPoint, Point followerPosition, 
    double leaderHeading, double followerHeading, double leaderHeadingCommanded, 
    double groundSpeedLeader
){ 
    Point followerFinalPoint_Proj(
        followerFinalPoint.x + cos(leaderHeadingCommanded),
        followerFinalPoint.y + sin(leaderHeadingCommanded)
    ); 



    double x_e = ((followerFinalPoint.x - followerPosition.x) * cos(followerHeading))+
            ((followerFinalPoint.y -followerPosition.y)*sin(followerHeading)); // 映射到 飞机的方向上

    double chi_e = leaderHeading - followerHeading; // 航向角度之差
    
    groundSpeedSetpoint = c1 * x_e + groundSpeedLeader * cos(chi_e);
    
    double followerDistance = Point::norm(followerFinalPoint - followerPosition);

#ifdef _FOLLOWER_VF_HEADING_SETPOINT_

    /* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
    double follower_command_heading = vectorField.getHeading(
		followerPosition,
        before_final_position,
		followerFinalPoint,
		M_PI/100.0, 
        M_PI/2.0 - followerHeading, // -(followerHeading - M_PI/2.0)
		groundSpeedLeader           // 标准VF中, 没有产生作用
	)-(M_PI/2.0); // chi_c
    /* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

    if(followerDistance > threshold){
        headingSetpoint = atan2(followerFinalPoint.y - followerPosition.y, followerFinalPoint.x - followerPosition.x);
        groundSpeedSetpoint = 2*groundSpeedLeader;
    }else{
        followerDistance = abs(Point::det(followerFinalPoint_Proj -  followerFinalPoint,followerFinalPoint-followerPosition))/Point::norm(followerFinalPoint_Proj-followerFinalPoint);
        int side = (Point::det(followerFinalPoint-followerFinalPoint_Proj, followerPosition-followerFinalPoint_Proj)) >= 0 ? 1 : -1;
        headingSetpoint = follower_command_heading + side*chi_infinite*(pow(followerDistance/threshold,k));
    }
    
    before_final_position = followerFinalPoint;

#else   // 最初的从机的 VF 控制逻辑

    if(followerDistance > threshold){
        headingSetpoint = atan2(followerFinalPoint.y - followerPosition.y, followerFinalPoint.x - followerPosition.x);
        groundSpeedSetpoint = 2*groundSpeedLeader;
        
    }else
    {
        followerDistance = abs(Point::det(followerFinalPoint_Proj -  followerFinalPoint,followerFinalPoint-followerPosition))/Point::norm(followerFinalPoint_Proj-followerFinalPoint);
        int side = (Point::det(followerFinalPoint-followerFinalPoint_Proj, followerPosition-followerFinalPoint_Proj)) >= 0 ? 1 : -1;
        headingSetpoint = leaderHeadingCommanded + side*chi_infinite*(pow(followerDistance/threshold,k));
    }

#endif

}


// {
    
//     Point followerFinalPoint_Proj(
//         followerFinalPoint.x + cos(leaderHeadingCommanded),
//         followerFinalPoint.y + sin(leaderHeadingCommanded)
//     ); 

//     double x_e = ((followerFinalPoint.x - followerPosition.x) * cos(followerHeading))+
//             ((followerFinalPoint.y -followerPosition.y + dist_y)*sin(followerHeading));
    
//     double chi_e = leaderHeading - followerHeading;
    
//     groundSpeedSetpoint = c1 * x_e + groundSpeedLeader * cos(chi_e);

//     double followerDistance = Point::norm(followerFinalPoint - followerPosition);

//     if(followerDistance > threshold){
//         headingSetpoint = atan2(followerFinalPoint.y - followerPosition.y, followerFinalPoint.x - followerPosition.x);
//         groundSpeedSetpoint = 2*groundSpeedLeader;
//     }else
//     {
//         followerDistance = abs(Point::det(followerFinalPoint_Proj -  followerFinalPoint,followerFinalPoint-followerPosition))/
//             Point::norm(followerFinalPoint_Proj-followerFinalPoint);

//         if(DEBUG) std::cout<<"new FollowerDistance:"<<followerDistance<<std::endl;
//         if(DEBUG) std::cout<<"Test:"<<Point::det(followerFinalPoint_Proj -  followerFinalPoint,followerFinalPoint-followerPosition)<<std::endl;
//         int side = (Point::det(followerFinalPoint-followerFinalPoint_Proj, followerPosition-followerFinalPoint_Proj)) >= 0 ? 1 : -1;
//         headingSetpoint = leaderHeadingCommanded + side*chi_infinite*(pow(followerDistance/threshold,k));             
//     }
// }

double formationControl::getGroundSpeedSetpoint(){
    return groundSpeedSetpoint;
};
double formationControl::getHeadingSetpoint(){
    return headingSetpoint;
};

