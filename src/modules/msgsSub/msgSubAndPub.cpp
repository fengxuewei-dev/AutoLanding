#include "msgSubAndPub.hpp"

int main(int argc, char **argv){


    std::string uavName = "";

    std::string nodeName = "msgsPub";
    if(argc == 2){
        uavName = argv[1];
        uavName = uavName + "/";
        nodeName = nodeName.append(uavName, 3, 1);
    }else{
        ROS_ERROR("the single mode!");
    }
    cout << "uavname : " << uavName << endl;   

    ros::init(argc, argv, nodeName);
    
    SubAndPub subandpub(uavName);

    ros::Rate rate(MSG_SUB_AND_PUB);

    while(ros::ok()){
        subandpub.printInfo();

        subandpub.publishData();
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}