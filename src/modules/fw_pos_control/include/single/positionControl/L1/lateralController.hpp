#ifndef _LATERAL_CONTROLLER_HPP_
#define _LATERAL_CONTROLLER_HPP_
/*
*作者：lee-shun
*本程序是基于L1控制器的改动版本，输入是飞机的当前的位置，当前的地速
*(向量），空速，目标位置点，输出的是期望的偏航角以及期望的滚转角
*估计应该会写几个种类的横向控制器，看最后用那个吧。。。。。。。。
*
*
*/
#include <iostream>
#include <math.h>
#include "../../../../../../lib/mathlib/mathlib.h"
#include "../../../../../../lib/mathlib/vector/vector.hpp"

using namespace std;

class LATERAL_CONTROLLER
{
private:
    /***********************************魔改L1控制器函数***************************************/
    /***********************************魔改L1控制器函数***************************************/
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

    struct _s_control_lateral_params
    {
        float kp{0.1};

        float kd{0.1};
    } control_lateral_params;

    float track_vel_k{1};
    /***********************************魔改L1控制器函数***************************************/
    /***********************************魔改L1控制器函数***************************************/

    ///////////速度追踪法/////////////

    ///////////速度追踪法/////////////

public:
    ///////////视线与速度夹角控制/////////////
    void lateral_yaw();

    ///////////视线与速度夹角速率控制/////////////
    void lateral_yaw_rate();

    ///////////滑膜控制/////////////
    void lateral_sliding_mode();

    /***********************************魔改L1控制器函数***************************************/
    /***********************************魔改L1控制器函数***************************************/
    void lateral_L1_modified(Point curr_pos, Point sp_pos, Point ground_speed_2d, float airspeed);

    Point get_local_planar_vector(Point origin, Point target);

    float get_lateral_roll_sp();

    float get_lateral_acc_lateral();

    void set_l1_period(float period);

    void set_l1_damping(float damping);

    void set_l1_roll_limit(float roll_lim_rad);
    float nav_roll();

    float nav_lateral_acceleration_demand();

    float nav_bearing();

    void track_velocity(Point curr_pos, Point sp_pos, Point ground_speed_2d, Point sp_speed_2d);
};
#endif