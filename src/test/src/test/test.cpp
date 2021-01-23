#include "../../include/TestData.hpp"

int main(int argc, char **argv){
    std::string nodeName = "test";
    ros::init(argc, argv, nodeName);
    std::string uavName = "";
    int flag = 0;
    // if(argc == 3){
    //     uavName = argv[1];
    //     uavName = uavName + "/";
    //     flag = atoi(argv[2]);
    // }else
    // {
    //     ROS_INFO("the argc != 3, need two argments");
    //     return 0;
    // }
    
    TestData testData(uavName);
    testData.exitflag.EXIT_FLAG = flag;

    ros::Rate rate(TEST_DATA);
    while(ros::ok()){
        ros::spinOnce();
        rate.sleep();
        // 和下一个航点还有大概 5% 的距离就进行切换, 数字为
        std::cout << "waypoint Reached seq: " << testData._waypointReached_.wp_seq << std::endl; // 已经到达的航点, 标号为 航点标号-1
        std::cout << "waypoint list: " << testData._waypointLists_.current_seq << std::endl; // 正在执行的目标航点(第一个航点是home之后的第一个航点,标号为0)

        // 如果我这个时候更新航线, current_seq 标号会重新设置为0, 但是reached 标号还是上次航线到达的航点序列号; 当执行新的航线之后, reached 标号更新
        std::cout << "print waypoints list: " << std::endl;
        for(size_t i = 0; i < testData._waypointLists_.waypoints.size(); i++)
        {
            testData.print_wp(testData._waypointLists_.waypoints[i]);
            std::cout << " " << std::endl;
        }
    }
    
    return 0;
}