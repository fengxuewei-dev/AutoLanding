#include "speed_sp.hpp"

void SPEED_SP::re_cal_speed() { reset_cal_speed = true; }
void SPEED_SP::calculated_vel_led_fol(SPEED_SP::_s_status follower_status, SPEED_SP::_s_status leader_status)
{
    SPEED_SP_status.vel_led_fol_x = leader_status.ned_vel_x - follower_status.ned_vel_x;
    SPEED_SP_status.vel_led_fol_y = leader_status.ned_vel_y - follower_status.ned_vel_y;
}
void SPEED_SP::update_airspeed_pos_p(SPEED_SP::_s_error error, SPEED_SP::_s_status follower_status, SPEED_SP::_s_status leader_status)
{

    calculated_vel_led_fol(follower_status, leader_status);

    float abs_error = abs_num(error.distance_level);

    float per_k = formation_params.v_kp / formation_params.per_distance;

    SPEED_SP_status.ned_vel_x = leader_status.ned_vel_x + (per_k * abs_error) * error.n_distance;

    SPEED_SP_status.ned_vel_y = leader_status.ned_vel_y + (per_k * abs_error) * error.e_distance;

    cov_gdsp_2_airsp(follower_status);
}

void SPEED_SP::cov_gdsp_2_airsp(SPEED_SP::_s_status follower_status)
{
    airspeed_sp = sqrt((SPEED_SP_status.ned_vel_x - follower_status.wind_x) * (SPEED_SP_status.ned_vel_x - follower_status.wind_x) //
                       + (SPEED_SP_status.ned_vel_y - follower_status.wind_y) * (SPEED_SP_status.ned_vel_y - follower_status.wind_y));
}
