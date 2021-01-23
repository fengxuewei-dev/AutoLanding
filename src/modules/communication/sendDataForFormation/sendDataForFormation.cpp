#include "sendDataForFormation.hpp"

// 放在 receive 内部 进行分装 分布
// taskType需要单拉一个节点进行任务分发
// 从机的接收端
int main(int argc, char **argv){

    /* 1. configuration */

    // 分发数据到从机的各个控制器
    std::string uavName = "";
    std::string nodeName = "sendDataForFormation";
    std::string formationShape = "";

    std::string sysID = "";
    std::string param = "";
    cout<<"111"<<endl;
    
    if(argc == 1){

    }
    else if(argc == 2) // 没有飞机的编号 uavX
	{   
        param = argv[1];
        if (param.substr(0, 3) == "uav")
        {
            uavName = argv[1];
            uavName = uavName + "/";
            nodeName = nodeName.append(uavName, 3, 1);
        }
        else
        {
            formationShape = argv[1]; // 编队类型
        }
        
        
	}
	else{
        // uavName + 编队类型
		uavName = argv[1];
        uavName = uavName + "/";
        formationShape = argv[2];
        nodeName = nodeName.append(uavName, 3, 1);
    }

    
    ros::init(argc, argv, nodeName);

    DataForFormationSubAndPub dataForFormationSubAndPub(uavName);
    ros::Rate rate(UDP_COMMUNICATION_RECEIVE);

    while(
        ros::ok() && 
        (dataForFormationSubAndPub.myGap.x == -1 ||
        dataForFormationSubAndPub.leaderid == -1)
    ){
        ROS_INFO("Waiting for the Init param from QGCommands ... %f, %f", dataForFormationSubAndPub.myGap.x, dataForFormationSubAndPub.leaderid);
        ros::spinOnce();
        rate.sleep();
    }

    sysID = std::__cxx11::to_string(sysid.sysid - 1);
    std::cout << "sysID: " << sysID << std::endl;
    
    dataForFormationSubAndPub.get_Initmsg(dataForFormationSubAndPub.leaderid);

    while(
        ros::ok() && 
        (dataForFormationSubAndPub.getHomePositionFromUdp().altitude == 0 ||
        dataForFormationSubAndPub.getUdpDataFromUdp().latitudey == 0)
    ){
        ROS_INFO("Waiting for the first connection ... ");
        cout<<dataForFormationSubAndPub.getUdpDataFromUdp().latitudey<<endl;
        cout<<dataForFormationSubAndPub.getHomePositionFromUdp().altitude<<endl;
        cout<<"///////////////////"<<dataForFormationSubAndPub.leaderid<<endl;
        ros::spinOnce();
        rate.sleep();
    }

    dataForFormationSubAndPub.showData();
    
    while(
        ros::ok() && 
        dataForFormationSubAndPub.getHomePositionFromUdp().altitude != 0 &&
        dataForFormationSubAndPub.getUdpDataFromUdp().latitudey == 0
    ){
        // 拿到home位置 没有拿到 udp data 数据
        ROS_INFO("Has received the home position then send the ack to udp ... ");
        ROS_INFO("Waiting for the udp data!");
        ros::spinOnce();
        rate.sleep();
    }
    while(
        ros::ok() && 
        dataForFormationSubAndPub.getHomePositionFromUdp().altitude == 0 &&
        dataForFormationSubAndPub.getUdpDataFromUdp().latitudey != 0
    ){
        // 这个应该放在 navigator 里面
        ROS_INFO("Has received the home position then send the ack to udp ... ");
        ROS_INFO("Waiting for the home data!");
        ros::spinOnce();
        rate.sleep();
    }
    while(
        ros::ok() && 
        dataForFormationSubAndPub.getHomePositionFromUdp().altitude != 0 &&
        dataForFormationSubAndPub.getUdpDataFromUdp().latitudey != 0
    ){
        ROS_INFO("data has began received and start to be sent!");
	while(ros::ok())
{
        dataForFormationSubAndPub.setData(sysID);
        dataForFormationSubAndPub.dataPublish();

        ROS_INFO("Leaderid is : %d, gapx is %f, gapy is %f", dataForFormationSubAndPub.leaderid, dataForFormationSubAndPub.myGap.x,dataForFormationSubAndPub.myGap.y);

        ros::spinOnce();
        rate.sleep();
}
    }
    return 0;
}
