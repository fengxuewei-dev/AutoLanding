#include "../navigator.hpp"

int main(int argc, char **argv){
    std::string uavName = "";
    std::string nodeName = "NavigatorGPS2ENU"; 
    ros::init(argc, argv, nodeName);
    
    // subscribe all the data...
    NavigatorSubAndPub navigatorSubAndPub(uavName);

    ros::Rate rate(NAVIGATOR_CONTROLLER_RATE_EXE);


    navigatorSubAndPub.GPS_transform_ENU();

    return 0;
}
