#pragma once

#include "include/FixedwingAttitudeSubAndPub/FixedwingAttitudeSubAndPub.hpp"
#include "include/PID/pidControl.hpp"
#include "include/RC/RC.hpp"

#include "../../lib/Macro.hpp"

enum{_ControlModeNULL_, _OFFBOARD_ATTITUDE_CONTROLLER_, _RC_ATTITUDE_CONTROLLER_};

typedef int ControlModeType;

int modeset_flag = 0;
int initflag = 1;
