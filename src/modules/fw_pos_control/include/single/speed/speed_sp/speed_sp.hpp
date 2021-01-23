#ifndef _SPEED_SP_H_
#define _SPEED_SP_H_

#include <iostream>
#include "../../../../../../lib/mathlib/mathlib.h"
#include "../../../../../../lib/mathlib/vector/vector.hpp"

using namespace std;

class SPEED_SP
{
public:
    struct _s_error
    {
        float ned_vel_x; //ned速度，北向

        float ned_vel_y;

        float global_pos_lat;

        float global_pos_long;

        float global_pos_alt;

        float distance_level;

        float n_distance;

        float e_distance;

        float distance_3d;
    };

    struct _s_status
    {
        float ned_vel_x; //ned速度，北向

        float ned_vel_y;

        float global_pos_lat;

        float global_pos_long;

        float global_pos_alt;

        float wind_x;

        float wind_y;
    };

    struct _s_SPEED_SP_status
    {
        float ned_vel_x;

        float ned_vel_y;

        float vel_led_fol_x{0}; //ned下，领机和从机速度之差，由speed——sp类产生

        float vel_led_fol_y{0};

        float vel_led_fol_z{0};
    };

    float get_airspeed_sp(){
        return airspeed_sp;
    }

    _s_SPEED_SP_status get_sp_status(){
        return SPEED_SP_status;
    }
    void calculated_vel_led_fol(SPEED_SP::_s_status follower_status, SPEED_SP::_s_status leader_status);

    void cov_gdsp_2_airsp(SPEED_SP::_s_status follower_status);

    //控制方案：相对位置误差的p控制产生期望速度增量，加到领机的速度之上作为从机的期望速度
    void update_airspeed_pos_p(SPEED_SP::_s_error error, SPEED_SP::_s_status follower_status, SPEED_SP::_s_status leader_status);

    //控制方案：相对位置误差,相对速度误差作为总控制误差，将这个error pid之后产生期望速度
    void update_airspeed_mix_vp(float time, SPEED_SP::_s_error error, SPEED_SP::_s_status follower_status, SPEED_SP::_s_status leader_status);

    void re_cal_speed();

private:
    // PID_CONTROLLER n_pid, e_pid;

    bool first_use{true};

    bool reset_cal_speed{false};

    float current_time{0.0};

    float last_time{0.0};

    float _dt{0.0};

    float integ_e_pv_n{0}; //混合误差积分项

    float integ_e_pv_e{0};

    struct _s_formation_params
    {
        float v_kp{0.8};

        float v_kp1{0.1}; //近距离

        float v_kp2{0.5}; //远距离

        float kv_p{0.5}; //主从机速度差比例项

        float kp_p{0.8}; //从机期望与实际位置误差比例

        float mix_kp{0.6};

        float mix_kd{0.0};

        float mix_ki{0.01};

        double altitude_offset{0};

        double longtitude_offset{0};

        double latitude_offset{0};

        double per_distance{100};

    } formation_params;

    float airspeed_sp{0};

    _s_SPEED_SP_status SPEED_SP_status;
};
#endif