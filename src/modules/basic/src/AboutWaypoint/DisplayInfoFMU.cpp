/**
 * @file DisplayInfoFMU.cpp
 * To display the information about the FMU
*/
#include "DisplayInfoFMU.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "DisplayInfoFMU");

    cout << "111 " << endl;
    FIXED_WING_INFORMATION_DISPLAY display_inf;
  
    if(!display_inf.run(argc, argv))
    { // 返回为false
        ROS_ERROR("The node is failed to open!");
    }
    return 0;
}

