#pragma once

#include <iostream>
#include <ros/ros.h>

#include "include/NavigatorSubAndPub/NavigatorSubAndPub.hpp"


using std::cout;
using std::endl;

typedef int ControlModeType;
typedef int FlyModeType;

enum CONTROL{_CONTROLMODENULL,_OFFBOARD_ATTITUDE_CONTROLLER_,_RC_ATTITUDE_CONTROLLER_};

enum FLY{_FLYMODENULL_, _SINGLE_FLYMODE_, _FORMATION_FLYMODE_};

int initflag = 1;
