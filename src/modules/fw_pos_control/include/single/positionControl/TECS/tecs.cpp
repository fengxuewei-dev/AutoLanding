#include "tecs.hpp"

void TECS::update_state(float time_now, float baro_altitude, float airspeed, const float rotMat[3][3],
                        const float accel_body[3], const float accel_earth[3], bool altitude_lock, bool in_air)
{
    /// Calculate time in seconds since last update
    uint64_t now = time_now;
    float DT = max((now - _update_50hz_last_usec), 0);

    bool reset_altitude = false;

    if (_update_50hz_last_usec == 0 || DT > DT_MAX)
    {
        DT = DT_DEFAULT; // when first starting TECS, use small time constant
        reset_altitude = true;
    }

    if (!altitude_lock || !in_air)
    {
        reset_altitude = true;
    }

    if (reset_altitude)
    {
        _integ3_state = baro_altitude;  // _vert_pos_state
        _integ2_state = 0.0f;
        _integ1_state = 0.0f;

        // Reset the filter state as we just switched from non-altitude control
        // to altitude control mode
        _states_initalized = false;
    }

    _update_50hz_last_usec = now;
    _EAS = airspeed;

    _in_air = in_air;

    // Get height acceleration
    float hgt_ddot_mea = -(accel_earth[2] + CONSTANTS_ONE_G);
    // Perform filter calculation using backwards Euler integration
    // Coefficients selected to place all three filter poles at omega
    float omega2 = _hgtCompFiltOmega * _hgtCompFiltOmega;
    float hgt_err = baro_altitude - _integ3_state;
    float integ1_input = hgt_err * omega2 * _hgtCompFiltOmega;
    _integ1_state = _integ1_state + integ1_input * DT;
    float integ2_input = _integ1_state + hgt_ddot_mea + hgt_err * omega2 * 3.0f;
    _integ2_state = _integ2_state + integ2_input * DT;
    float integ3_input = _integ2_state + hgt_err * _hgtCompFiltOmega * 3.0f;

    // If more than 1 second has elapsed since last update then reset the integrator state
    // to the measured height
    if (reset_altitude)
    {
        _integ3_state = baro_altitude;
    }
    else
    {
        _integ3_state = _integ3_state + integ3_input * DT;
    }

    // Update and average speed rate of change
    // Only required if airspeed is being measured and controlled
    float temp = 0;

    if (airspeed_sensor_enabled())
    {
        // Get DCM
        // Calculate speed rate of change
        // XXX check
        temp = rotMat[2][0] * CONSTANTS_ONE_G + accel_body[0];
        // take 5 point moving average
        //_vel_dot = _vdot_filter.apply(temp);
        // XXX resolve this properly
        _vel_dot = 0.95f * _vel_dot + 0.05f * temp;
    }
    else
    {
        _vel_dot = 0.0f;
    }

    if (!_in_air)
    {
        _states_initalized = false;
    }
}
void TECS::_initialise_states(float pitch, float throttle_cruise, float baro_altitude, float ptchMinCO_rad, float EAS2TAS)
{
    // Initialise states and variables if DT > 1 second or in climbout
    /*如果是第一次进入，或者有什么异常的时候直接重置一下*/
    /**************************
	* 初始化一些量，第一次进来这个函数会用到。
	*
	* _integ1_state <---- 高度的二阶导数，即高度方向的加速度；
	* _integ2_state <---- 高度的一阶导数，即高度方向的速度；
	* _integ3_state <---- 高度；
	* _integ4_state <---- 空速的一阶导数，即空速的加速度；
	* _integ5_state <---- 空速；
	* _integ6_state <---- 油门的积分量；
	* _integ7_state <---- pitch的积分量；
	***************************/
    /**************************
	*
	* 将等效空速转换为实际的空速
	* 其中EAS为等效空速，TAS为实际空速，一般情况下，两者比例为1
	*
	***************************/
    if (_update_pitch_throttle_last_usec == 0)
    {

        _integ1_state = 0.0f;
        _integ2_state = 0.0f;
        _integ3_state = baro_altitude;
        _integ4_state = 0.0f;
        _integ5_state = _EAS * EAS2TAS; //等效空速EAS
        _integ6_state = 0.0f;
        _integ7_state = 0.0f;

        _last_throttle_dem = throttle_cruise;
        _last_pitch_dem = constrain(pitch, _PITCHminf, _PITCHmaxf);
        _pitch_dem_unc = _last_pitch_dem;

        _hgt_dem_adj_last = baro_altitude;
        _hgt_dem_adj = _hgt_dem_adj_last;
        _hgt_dem_prev = _hgt_dem_adj_last;
        _hgt_dem_in_old = _hgt_dem_adj_last;

        _TAS_dem_last = _EAS * EAS2TAS;
        _TAS_dem_adj = _TAS_dem_last;

        _underspeed = false;
        _badDescent = false;

        if (_DT > DT_MAX || _DT < DT_MIN)
        {
            _DT = DT_DEFAULT;
        }
    }
    else if (_climbOutDem)
    {
        _PITCHminf = ptchMinCO_rad;
        _THRminf = _THRmaxf - 0.01f;

        _hgt_dem_adj_last = baro_altitude;
        _hgt_dem_adj = _hgt_dem_adj_last;
        _hgt_dem_prev = _hgt_dem_adj_last;

        _TAS_dem_last = _EAS * EAS2TAS;
        _TAS_dem_adj = _EAS * EAS2TAS;

        _underspeed = false;
        _badDescent = false;
    }

    _states_initalized = true;
}

void TECS::_update_speed(float time_now, float airspeed_demand, float indicated_airspeed,
                         float indicated_airspeed_min, float indicated_airspeed_max, float EAS2TAS)
{
    // Calculate time in seconds since last update
    float now = time_now; //这里的时间感觉会有问题，原先的算法是在这里读取系统时间，这里是我在进来的时候添加的时间，是静止的时间
    float DT = max((now - _update_speed_last_usec), 0) * 1.0e-6f;

    /**************************
	*
	* 将等效空速转换为实际的空速
	* 其中EAS为等效空速，TAS为实际空速，一般情况下，两者比例为1
    *
    * 这里的indicated_airspeed_max以及indicated_airspeed_min是构造函数初始化的时候做的(3,30)
	*
	***************************/

    _EAS_dem = airspeed_demand;
    _TAS_dem = _EAS_dem * EAS2TAS;
    _TASmax = indicated_airspeed_max * EAS2TAS;
    _TASmin = indicated_airspeed_min * EAS2TAS;

    // Get airspeed or default to halfway between min and max if
    // airspeed is not being used and set speed rate to zero

    _EAS = indicated_airspeed; //原作这里是有保护的，这里要保证indicated_airspeed有效

    // Reset states on initial execution or if not active
    if (_update_speed_last_usec == 0 || !_in_air)
    {
        _integ4_state = 0.0f; //空速的一阶导数
        _integ5_state = (_EAS * EAS2TAS);
    }

    if (DT < DT_MIN || DT > DT_MAX)
    {
        DT = DT_DEFAULT; // when first starting TECS, use small time constant
    }

    /**************************
	*
	* _integ4_state 为空速的加速度，先对这个加速度量做一个滤波
	*
	***************************/
    float aspdErr = (_EAS * EAS2TAS) - _integ5_state;
    float integ4_input = aspdErr * _spdCompFiltOmega * _spdCompFiltOmega;

    // Prevent state from winding up
    if (_integ5_state < 3.1f)
    {
        integ4_input = max(integ4_input, 0.0f);
    }

    _integ4_state = _integ4_state + integ4_input * DT;

    /**************************
	*
	* 空速度的加速度平滑完了之后，再对_integ5_state即空速做滤波；
	* 最后做一个保护
	*
	***************************/
    float integ5_input = _integ4_state + _vel_dot + aspdErr * _spdCompFiltOmega * 1.4142f;
    _integ5_state = _integ5_state + integ5_input * DT;

    // limit the airspeed to a minimum of 3 m/s
    _integ5_state = max(_integ5_state, 3.0f);
    _update_speed_last_usec = now;
}

void TECS::_update_STE_rate_lim()
{
    // Calculate Specific Total Energy Rate Limits
    // This is a trivial calculation at the moment but will get bigger once we start adding altitude effects
    _STEdot_max = _maxClimbRate * CONSTANTS_ONE_G;
    _STEdot_min = -_minSinkRate * CONSTANTS_ONE_G;
}

void TECS::_detect_underspeed() //初始化之后默认是打开的
{
    if (!_detect_underspeed_enabled)
    {
        _underspeed = false;
        return;
    }

    if (((_integ5_state < _TASmin * 0.9f) && (_throttle_dem >= _THRmaxf * 0.95f)) || ((_integ3_state < _hgt_dem_adj) && _underspeed))
    {
        _underspeed = true;
    }
    else
    {
        _underspeed = false;
    }
}

void TECS::_update_speed_demand()
{
    // Set the airspeed demand to the minimum value if an underspeed condition exists
    // or a bad descent condition exists
    // This will minimise the rate of descent resulting from an engine failure,
    // enable the maximum climb rate to be achieved and prevent continued full power descent
    // into the ground due to an unachievable airspeed value
    if ((_badDescent) || (_underspeed))
    {
        _TAS_dem = _TASmin;
    }

    // Constrain speed demand
    _TAS_dem = constrain(_TAS_dem, _TASmin, _TASmax);

    // calculate velocity rate limits based on physical performance limits
    // provision to use a different rate limit if bad descent or underspeed condition exists
    // Use 50% of maximum energy rate to allow margin for total energy controller
    float velRateMax;
    float velRateMin;

    if ((_badDescent) || (_underspeed))
    {
        velRateMax = 0.5f * _STEdot_max / _integ5_state;
        velRateMin = 0.5f * _STEdot_min / _integ5_state;
    }
    else
    {
        velRateMax = 0.5f * _STEdot_max / _integ5_state;
        velRateMin = 0.5f * _STEdot_min / _integ5_state;
    }

    _TAS_dem_adj = constrain(_TAS_dem, _TASmin, _TASmax);
    _TAS_rate_dem = constrain((_TAS_dem_adj - _integ5_state) * _speedrate_p, velRateMin, velRateMax);
    //xxx: using a p loop for now p控制产生速度的rate的期望值
}

void TECS::_update_height_demand(float demand, float state) //state是当前的实际高度，气压计
{
    // Handle initialization
    if (fabsf(_hgt_dem_in_old) < 0.1f)
    {
        _hgt_dem_in_old = demand;
    }
    // Apply 2 point moving average to demanded height
    // This is required because height demand is updated in steps
    //if (PX4_ISFINITE(demand))
    //{
    _hgt_dem = 0.5f * (demand + _hgt_dem_in_old);
    //_hgt_dem = demand;
    // }
    // else
    // {
    //     _hgt_dem = _hgt_dem_in_old;
    // }
    _hgt_dem_in_old = _hgt_dem; //将现在的期望高度记录一下，下一次用

    //Limit height demand
    //this is important to avoid a windup
    if ((_hgt_dem - _hgt_dem_prev) > (_maxClimbRate * _DT))
    {
        _hgt_dem = _hgt_dem_prev + _maxClimbRate * _DT;
    }
    else if ((_hgt_dem - _hgt_dem_prev) < (-_maxSinkRate * _DT))
    {
        _hgt_dem = _hgt_dem_prev - _maxSinkRate * _DT;
    }

    _hgt_dem_prev = _hgt_dem;

    _hgt_dem_adj = 0.1f * _hgt_dem + 0.9f * _hgt_dem_adj_last;
    //_hgt_dem_adj = demand;
    _hgt_dem_adj_last = _hgt_dem_adj;
    _hgt_rate_dem = (_hgt_dem_adj - state) * _heightrate_p + _heightrate_ff * (_hgt_dem_adj - _hgt_dem_adj_last) / _DT;

    // Limit height rate of change
    if (_hgt_rate_dem > _maxClimbRate)
    {
        _hgt_rate_dem = _maxClimbRate;
    }
    else if (_hgt_rate_dem < -_maxSinkRate)
    {
        _hgt_rate_dem = -_maxSinkRate;
    }
}

void TECS::_update_energies()
{
    // Calculate specific energy demands
    _SPE_dem = _hgt_dem_adj * CONSTANTS_ONE_G;
    _SKE_dem = 0.5f * _TAS_dem_adj * _TAS_dem_adj;

    // Calculate specific energy rate demands
    _SPEdot_dem = _hgt_rate_dem * CONSTANTS_ONE_G;
    _SKEdot_dem = _integ5_state * _TAS_rate_dem;

    // Calculate specific energy
    _SPE_est = _integ3_state * CONSTANTS_ONE_G;
    _SKE_est = 0.5f * _integ5_state * _integ5_state;

    // Calculate specific energy rate
    _SPEdot = _integ2_state * CONSTANTS_ONE_G;
    _SKEdot = _integ5_state * _vel_dot;
}

void TECS::_update_throttle(float throttle_cruise, const float rotMat[3][3])
{

    _STE_error = _SPE_dem - _SPE_est + _SKE_dem - _SKE_est;
    float STEdot_dem = constrain((_SPEdot_dem + _SKEdot_dem), _STEdot_min, _STEdot_max);

    // 计算总能量变化率的error
    _STEdot_error = STEdot_dem - _SPEdot - _SKEdot;

    // 滤波，去除加速度计带来的噪音
    _STEdot_error = 0.2f * _STEdot_error + 0.8f * _STEdotErrLast;
    _STEdotErrLast = _STEdot_error;

    // 如果失速了，那么直接推满油门！
    if (_underspeed)
    {
        _throttle_dem = 1.0f;
    }
    else
    {
        // 计算一个能量到油门的系数，类似于增益的kP
        float K_STE2Thr = 1 / (_timeConstThrot * (_STEdot_max - _STEdot_min));

        // Calculate feed-forward throttle
        float ff_throttle = 0;
        float nomThr = throttle_cruise;

        float cosPhi = sqrtf((rotMat[0][1] * rotMat[0][1]) + (rotMat[1][1] * rotMat[1][1])); //存疑，因为旋转矩阵不一定对。。。。
        STEdot_dem = STEdot_dem + _rollComp * (1.0f / constrain(cosPhi, 0.1f, 1.0f) - 1.0f);
        //计算前馈项
        if (STEdot_dem >= 0)
        {
            ff_throttle = nomThr + STEdot_dem / _STEdot_max * (_THRmaxf - nomThr);
        }
        else
        {
            ff_throttle = nomThr - STEdot_dem / _STEdot_min * nomThr;
        }

        // PD+FF控制，完了之后做个保护
        _throttle_dem = (_STE_error + _STEdot_error * _thrDamp) * K_STE2Thr + ff_throttle;
        _throttle_dem = constrain(_throttle_dem, _THRminf, _THRmaxf);

        // 依旧是保护，防止油门的变化率超过_throttle_slewrate
        if (fabsf(_throttle_slewrate) > 0.01f)
        {
            float thrRateIncr = _DT * (_THRmaxf - _THRminf) * _throttle_slewrate;
            _throttle_dem = constrain(_throttle_dem,
                                      _last_throttle_dem - thrRateIncr,
                                      _last_throttle_dem + thrRateIncr);
        }

        // Ensure _last_throttle_dem is always initialized properly
        _last_throttle_dem = _throttle_dem;

        // Calculate integrator state upper and lower limits
        // Set to a value that will allow 0.1 (10%) throttle saturation to allow for noise on the demand
        float integ_max = (_THRmaxf - _throttle_dem + 0.1f);
        float integ_min = (_THRminf - _throttle_dem - 0.1f);

        // 更新积分项，如果在爬升当中，那么直接将积分项给定为最大值，正常情况下，做保护
        _integ6_state = _integ6_state + (_STE_error * _integGain) * _DT * K_STE2Thr;

        if (_climbOutDem)
        {
            _integ6_state = integ_max;
        }
        else
        {
            _integ6_state = constrain(_integ6_state, integ_min, integ_max);
        }

        // 全部加起来，这里完成PID+FF控制
        if (airspeed_sensor_enabled())
        {
            _throttle_dem = _throttle_dem + _integ6_state;
        }
        else
        {
            _throttle_dem = ff_throttle;
        }

        // 保护

        _throttle_dem = constrain(_throttle_dem, _THRminf, _THRmaxf);
    }
}

void TECS::_update_pitch()
{

    /**************************
	*
	* 计算动能势能的控制权重。
	* 1 代表两者一样，正常情况下该权重系数都为1；
	* 0 代表势能控制，即此时不管俯仰角，只控高度，没有空速测量值的时候，会进入这种情况；
	* 2 代表动能控制，失速、起飞、爬升会进入这种情况
	*
	***************************/
    float SKE_weighting = constrain(_spdWeight, 0.0f, 2.0f);

    if ((_underspeed || _climbOutDem) && airspeed_sensor_enabled())
    {
        SKE_weighting = 2.0f;
    }
    else if (!airspeed_sensor_enabled())
    {
        SKE_weighting = 0.0f;
    }

    float SPE_weighting = 2.0f - SKE_weighting;

    // Specific Energy Balance
    // 计算能量转化率的期望，以及该转化率的变化率
    float SEB_dem = _SPE_dem * SPE_weighting - _SKE_dem * SKE_weighting;
    float SEBdot_dem = _SPEdot_dem * SPE_weighting - _SKEdot_dem * SKE_weighting;
    _SEB_error = SEB_dem - (_SPE_est * SPE_weighting - _SKE_est * SKE_weighting);
    _SEBdot_error = SEBdot_dem - (_SPEdot * SPE_weighting - _SKEdot * SKE_weighting);

    // 计算从能量转化率到俯仰角的转换系数，类似于增益的kP
    float gainInv = _integ5_state * _timeConst * CONSTANTS_ONE_G;

    // 累加积分项以及饱和限制
    float integ7_input = _SEB_error * _integGain;

    if (_pitch_dem_unc > _PITCHmaxf)
    {
        integ7_input = min(integ7_input, min((_PITCHmaxf - _pitch_dem_unc) * gainInv / _timeConst, 0.0f));
    }
    else if (_pitch_dem_unc < _PITCHminf)
    {
        integ7_input = max(integ7_input, max((_PITCHminf - _pitch_dem_unc) * gainInv / _timeConst, 0.0f));
    }

    // 更新pitch_dem项
    _integ7_state = _integ7_state + integ7_input * _DT;

    // Specific Energy Balance correction excluding integrator contribution
    // PD+ff控制的第一步，计算能量转化率的error
    float SEB_correction = _SEB_error + _SEBdot_error * _ptchDamp + SEBdot_dem * _timeConst;

    // During climbout/takeoff, bias the demanded pitch angle so that zero speed error produces a pitch angle
    // demand equal to the minimum value (which is )set by the mission plan during this mode). Otherwise the
    // integrator has to catch up before the nose can be raised to reduce speed during climbout.
    if (_climbOutDem)
    {
        SEB_correction += _PITCHminf * gainInv;
    }

    // 将PD+ff控制的第二步，将能量转化率的error转换到期望的俯仰角
    _pitch_dem_unc = (SEB_correction + _integ7_state) / gainInv;

    // Constrain pitch demand
    _pitch_dem = constrain(_pitch_dem_unc, _PITCHminf, _PITCHmaxf);

    // 对pitch的角速度做限制，不会超出_vertAccLim、、这个地方有问题，限制住了demand
    float ptchRateIncr = _DT * _vertAccLim / _integ5_state;

    if ((_pitch_dem - _last_pitch_dem) > ptchRateIncr)
    {
        _pitch_dem = _last_pitch_dem + ptchRateIncr;
    }
    else if ((_pitch_dem - _last_pitch_dem) < -ptchRateIncr)
    {
        _pitch_dem = _last_pitch_dem - ptchRateIncr;
    }

    _last_pitch_dem = _pitch_dem;
}

void TECS::update_pitch_throttle(float time_now, const float rotMat[3][3], float pitch, float baro_altitude, float hgt_dem,
                                 float EAS_dem, float indicated_airspeed, float EAS2TAS, bool climbOutDem, float ptchMinCO,
                                 float throttle_min, float throttle_max, float throttle_cruise, float pitch_limit_min, float pitch_limit_max)
{
    //cout<<"very_first" <<_hgt_dem<<endl;
    // Calculate time in seconds since last update
    float now = time_now;
    _DT = max((now - _update_pitch_throttle_last_usec), 0);
    _THRmaxf = throttle_max;
    _THRminf = throttle_min;
    _PITCHmaxf = pitch_limit_max;
    _PITCHminf = pitch_limit_min;

    /**************************
	* 初始化一些量，第一次进来这个函数会用到。
	*
	* _integ1_state <---- 高度的二阶导数，即高度方向的加速度；
	* _integ2_state <---- 高度的一阶导数，即高度方向的速度；
	* _integ3_state <---- 高度；
	* _integ4_state <---- 空速的一阶导数，即空速的加速度；
	* _integ5_state <---- 空速；
	* _integ6_state <---- 油门的积分量；
	* _integ7_state <---- pitch的积分量；
	***************************/
    _initialise_states(pitch, throttle_cruise, baro_altitude, ptchMinCO, EAS2TAS);

    /**************************
	*
	* 1. 计算当前的空速，对测量到的空速做一个二阶的低通滤波
    * 2. 将空速的加速度做一个滤波（并不知道是什么滤波）,得到的是空速的变换率
	*
	***************************/
    _update_speed(time_now, EAS_dem, indicated_airspeed, _indicated_airspeed_min, _indicated_airspeed_max, EAS2TAS);
    //cout<<"_initialise_states" <<_hgt_dem<<endl;
    // /**************************
    // *
    // * 2. 计算动能的极值，当爬升速度最大或最小的时候，取到动能的极值
    // *
    // ***************************/
    _update_STE_rate_lim();

    // /**************************
    // *
    // * 3. 检查有没有失速
    // *
    // ***************************/
    //_detect_underspeed();

    // /**************************
    // *
    // * 4. 计算期望空速和期望空速的加速度
    // *
    // ***************************/
    _update_speed_demand();

    // /**************************
    // *
    // * 5. 计算期望高度和期望爬升率
    // *
    // ***************************/
    _update_height_demand(hgt_dem, baro_altitude);

    // /**************************
    // *
    // * 6. 计算单位质量的势能和动能_SPE\_SKE以及其变化率
    // *
    // ***************************/
    _update_energies();

    // /**************************
    // *
    // * 7. 根据期望的总能量和当前的总能量计算期望油门值
    // *
    // ***************************/
    _update_throttle(throttle_cruise, rotMat);

    // /**************************
    // *
    // * 8. 根据期望的能量转化率和当前的能量转化率计算期望油门值
    // *
    // ***************************/
    _update_pitch();

    _tecs_state.timestamp = now;

    if (_underspeed)
    {
        _tecs_state.mode = ECL_TECS_MODE_UNDERSPEED;
    }
    else if (_badDescent)
    {
        _tecs_state.mode = ECL_TECS_MODE_BAD_DESCENT;
    }
    else if (_climbOutDem)
    {
        _tecs_state.mode = ECL_TECS_MODE_CLIMBOUT;
    }
    else
    {
        // If no error flag applies, conclude normal
        _tecs_state.mode = ECL_TECS_MODE_NORMAL;
    }

    /**************************
    *
    * 以上的8个步骤完成后，读取得到期望的油门值和期望的pitch角
    *
    ***************************/
    _tecs_state.altitude_sp = _hgt_dem_adj;
    _tecs_state.altitude_filtered = _integ3_state;
    _tecs_state.altitude_rate_sp = _hgt_rate_dem;
    _tecs_state.altitude_rate = _integ2_state;

    _tecs_state.airspeed_sp = _TAS_dem_adj;
    _tecs_state.airspeed_rate_sp = _TAS_rate_dem;
    _tecs_state.airspeed_filtered = _integ5_state;
    _tecs_state.airspeed_rate = _vel_dot;

    _tecs_state.total_energy_error = _STE_error;
    _tecs_state.energy_distribution_error = _SEB_error;
    _tecs_state.total_energy_rate_error = _STEdot_error;
    _tecs_state.energy_distribution_rate_error = _SEBdot_error;

    _tecs_state.energy_error_integ = _integ6_state;
    _tecs_state.energy_distribution_error_integ = _integ7_state;

    _tecs_state.throttle_integ = _integ6_state;
    _tecs_state.pitch_integ = _integ7_state;

    _update_pitch_throttle_last_usec = now;
}
