#include <ros/ros.h>
#include <iostream>
#include "test/stringMsg.h"
// 当30个循环之后数据还是更新 那么就退出
test::stringMsg data1;
int times = 0;
int first = 0;  // 第一次执行回调函数
bool flag{false};

void newData(const test::stringMsg::ConstPtr& msg){
    data1 = *msg;
    std::cout << "call back function >> " << std::endl;
    std::cout << "data1: " << data1.testData1 << std::endl;
    std::cout << "data2: " << data1.testData2 << std::endl;
}


int main(int argc, char **argv){
    ros::init(argc, argv, "subNode");
    ros::NodeHandle nh;
    ros::Rate rate(100); // 100
    
    ros::Subscriber pub_msg = nh.subscribe<test::stringMsg>
        ("test/string/msg", 1, newData);

    while(ros::ok()){
        // std::cout << "waiting ..." << std::endl;
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}