#include "pidControl.hpp"

float pidControl::map(float x, float in_min, float in_max, float out_min, float out_max) {
	if(x > in_max) return out_max;
	if(x < in_min) return out_min;
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void pidControl::cal_Error(){
    altitudeError =  current_localPose.pose.position.z - current_commands.pitch;
    // throttleErrorDegree = current_commands.throttle - current_UAV_state.groundspeed;
     
    rollErrorDegree = ((float)current_UAV_state.heading)  + (current_commands.roll*(180.0/PI)); // error in degrees
	if(rollErrorDegree > 180)  rollErrorDegree-=360;
	if(rollErrorDegree < -180) rollErrorDegree+=360;

    yawErrorDegree = ((float)current_UAV_state.heading)  + (current_commands.yaw*(180.0/PI));   // error in degrees
	if(yawErrorDegree > 180)    yawErrorDegree-=360;
	if(yawErrorDegree < -180)   yawErrorDegree+=360; 
}
// pitch , roll , yaw , throttle
// att_angle_Euler: roll, pitch, yaw
void pidControl::Calculate(float *att_sp, float *Euler){
    
    cal_Error();
    float altitude_out = altitudeError*KP_ALT;
    float yaw_out; 
    float roll_out;
    
    float current_theta = Euler[1];
    
    // pitchErrorDegree = (((float)current_theta)  + (current_commands.pitch)) * (180.0 / M_PI); // error in degrees
	// if(pitchErrorDegree > 180)  pitchErrorDegree-=360;
	// if(pitchErrorDegree < -180) pitchErrorDegree+=360;
    // double pitch_out = -pitchErrorDegree * KP_PITCH;
    double pitchError, pitch_out;
#ifndef NEW_PITCH_CONTROLLER
    pitchError = current_commands.pitch - current_theta; 
    pitch_out = pitchError * (180.0 / M_PI)  * KP_PITCH;
#else
    pitchError = current_commands.pitch - current_theta; 
    pitch_out = pitchError * (180.0 / M_PI)  * KP_NEW_PITCH;
#endif
    att_sp[THROTTLE_CHANNEL - 1]  = map(
        // current_commands.throttle,  
        24,
        15, 30, RC_MIN,RC_MAX
    );

    att_sp[PITCH_CHANNEL - 1] = map(

#ifdef _USE_THREE_DIMENSION_VF_
        pitch_out,
        -PI, PI, 1000, 2000);       // 开发板
        // -60, 60, 1000, 2000);       // 开发板
        // current_commands.pitch, -M_PI / 3, M_PI / 3, 1000, 2000);       // 开发板 针对 就旧版的三维 VF
#else
        altitude_out, -100, 100, 1000+300, 2000-300);       // 开发板
#endif  

    std::cout << "abs(yawErrorDegree): " << abs(yawErrorDegree) << std::endl;

    if(abs(yawErrorDegree) > 0)     
    {  
        yaw_out = -yawErrorDegree * KP_YAW; 
        double roll_out = 
            KP_ROLL * 
            (atan2(yaw_out * current_UAV_state.groundspeed, CONSTANTS_ONE_G) - Euler[0]) * 
            (180.0/PI);
        
        att_sp[YAW_CHANNEL - 1]  = map(yaw_out,  -PI, PI, RC_MIN, RC_MAX);  
        att_sp[ROLL_CHANNEL - 1] = map(roll_out, -90, 90, RC_MIN, RC_MAX);   
    }
    else{
        std::cout << "yaw control : 1200 1300" << std::endl;
        yaw_out = yawErrorDegree * KP_YAW;

        att_sp[YAW_CHANNEL - 1]  = map(yaw_out, -2 * PI, 2*PI, RC_MIN+200,RC_MAX-200);   
    }
    // 最初的控制
    // double roll_out = -rollErrorDegree * 4;
    // att_sp[ROLL_CHANNEL - 1] = map(roll_out, -90, 90, RC_MIN,RC_MAX);   // sitl
}
