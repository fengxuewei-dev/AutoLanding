#pragma once

#include "../include/sendDataForFormation/DataForFormationSubAndPub.hpp"
#include <mavros_msgs/Mavlink.h>

#include "../../../lib/Macro.hpp"

mavros_msgs::Mavlink sysid;
void sysid_cb(const mavros_msgs::Mavlink::ConstPtr &msg){
    sysid = *msg;
}
