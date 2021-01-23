#include <ros/ros.h>
#include <iostream>
#include "test/stringMsg.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "pubNode");
    ros::NodeHandle nh;
    ros::Rate rate(100); 

    int i = 0;
    test::stringMsg data1;
    ros::Publisher pub_msg = nh.advertise<test::stringMsg>
        ("test/string/msg",1);
    int num{0};
    data1.testData1 = atoi(argv[1]);
    data1.testData2 = atoi(argv[2]);
    while(ros::ok()){  
        data1.number = ++num;
        std::cout << "data1.number: " << data1.number << std::endl;

        std::cout << "data1.testData1: " << data1.testData1 << std::endl;
        std::cout << "data1.testData2: " << data1.testData2 << std::endl;
        pub_msg.publish(data1);
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}