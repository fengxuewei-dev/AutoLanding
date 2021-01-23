#pragma once

#include <iostream>
#include "../../../../../lib/mathlib/vector/vector.hpp"
#include "../../../../../lib/Macro.hpp"
#include "../../single/vf/VF.hpp"
#include <math.h>

#define DEBUG 0
class formationControl
{
private:
    // float c1 = 1.2; // 速度
    float c1 = 2; // 速度, 最初为1
    float c2 = 40;
    double alpha = 200;
    double threshold = 25;
    // double threshold = 15;
    double k = 2;
    double chi_infinite = M_PI/2.0;
    double groundSpeedSetpoint;
    double headingSetpoint;

    VF vectorField;										// use the standard vf for formation controller

    Point before_final_position;
    
public:

    formationControl(float new_c1, float new_c2, double alpha);
    formationControl();
    void compute(
        Point followerFinalPoint,
        Point followerPosition, 
        double leaderHeading, 
        double followerHeading,
        double leaderHeadingCommanded,
        double groundSpeedLeader
    );
    
    ~formationControl();
    double getGroundSpeedSetpoint();
    double getHeadingSetpoint();

};
