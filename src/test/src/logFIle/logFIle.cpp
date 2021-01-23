#include "../TestWaypointlistPub.hpp"
#include "../../../lib/logger/LoggerUdp.hpp"
#include "../../../lib/mathlib/vector/three_dimensional_vector.hpp"

int main(int argc, char **argv){

    ros::init(argc, argv, "TestLogfile");
    ros::NodeHandle nh;
    ros::Rate rate(20);

    // 根据执行命令的时候所在的路径为起点
    // loggerSend loggersend("send");
    // loggersend.UdpData_altitude_z.logPrint(29.9);


    // loggerReceive loggerreceive("receive");
    // loggerreceive.UdpData_altitude_z.logPrint(39.9);
    ros::spin();
    return 0;
}