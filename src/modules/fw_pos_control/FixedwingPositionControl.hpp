#pragma once

#include <iostream>

#include "include/FixedwingPositionSubAndPub/FixedwingPositionSubAndPub.hpp"        // subscribe the message from the firmware
#include "fw_msgs/position_setpoint_triplet.h"
#include "fw_msgs/commands.h"
#include "../../lib/mathlib/math/mathlib.hpp"
#include "../../lib/Macro.hpp"          // Macro defined 

using std::cout;
using std::endl;

#define OFFBOARD_AIRSPEED_SETPOINT 17

enum CONTROL{_CONTROLMODENULL,_OFFBOARD_ATTITUDE_CONTROLLER_,_RC_ATTITUDE_CONTROLLER_};

enum FLY{_FLYMODENULL_, _SINGLE_FLYMODE_, _FORMATION_FLYMODE_};
typedef int ControlModeType;
typedef int FlyModeType;
int initflag = 1;
