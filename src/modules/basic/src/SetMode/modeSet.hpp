#pragma once



#include "../../include/modeSet.hpp"

mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}

void menu_choose(int& ch)
{
    // cout <<   "\t change the mode you need \t" << endl;
    cout <<   "\t The following is the flight mode \t" << endl;
    cout <<   "1: MANUAL\t\t 8: AUTO_MISSION\t"<< endl;
    cout <<   "2: ACRO\t\t\t 9: AUTO_LOITER\t"<< endl;
    cout <<   "3: ALTCTL\t\t 10: AUTO_RTL\t"<< endl;
    cout <<   "4: POSCTL\t\t 11: AUTO_LAND\t"<< endl;
    cout <<   "5: OFFBOARD\t\t 12: AUTO_RTGS\t"<< endl;
    cout <<   "6: STABILIZED\t\t 13: AUTO_READY\t"<< endl;
    cout <<   "7: RATTITUDE\t\t 14: AUTO_TAKEOFF\t"<< endl;
    cout <<   "0: exit\t"<< endl;
    cout <<   "  Please choose the command number you need: ";   

    cin  >> ch;
}
