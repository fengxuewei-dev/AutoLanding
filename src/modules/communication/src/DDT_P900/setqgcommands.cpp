using namespace std;
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <string.h>
#include <inttypes.h>
#include <fstream>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
using std::string;
#include <stdlib.h>
#include <ros/ros.h>

#include "fw_msgs/QgcCommands.h"
#include "fw_msgs/processer.h"

int main(int argc, char **argv)
{	
	std::string nodeName = "setqgcommands";

    fw_msgs::processer udpexecmsg;
    udpexecmsg.execflag == -1;

    fw_msgs::QgcCommands qgccommansmsg;
    qgccommansmsg.messageid = 4;
    qgccommansmsg.uavid = -1;
    qgccommansmsg.gsid = -1;
    qgccommansmsg.uavnumber = -1;
    qgccommansmsg.tasktype = -1;
    qgccommansmsg.plane_state = -1;
    qgccommansmsg.plane_group = -1;
    qgccommansmsg.gapx = -5;
    qgccommansmsg.gapy = -5;
    
    if(argc == 2){
        udpexecmsg.execflag = atof(argv[1]);
    }
	else if(argc == 9){
        char* argv_1 = argv[1];
        if(argv_1[0] != 'u'){
            qgccommansmsg.uavid = atoi(argv[1]);
        }
        else{
            std::string number = argv[1];
            qgccommansmsg.uavid = argv_1[3] - '0';
        }

        qgccommansmsg.gsid = atoi(argv[2]);
        qgccommansmsg.uavnumber = atoi(argv[3]);
        qgccommansmsg.tasktype = atoi(argv[4]);
        qgccommansmsg.plane_state = atoi(argv[5]);
        qgccommansmsg.plane_group = atoi(argv[6]);
        qgccommansmsg.gapx = atoi(argv[7]);
        qgccommansmsg.gapy = atoi(argv[8]);
        ROS_INFO("set param!");
    } 
	
    else{    
        ROS_INFO("Nothing to do!");
    }
	ros::init(argc, argv, nodeName);
	ros::NodeHandle nh("~");
    ros::Rate rate(2);

    ros::Publisher setqgcommands_param = nh.advertise<fw_msgs::QgcCommands>("/communication/DDT/setqgcommands", 10);
    ros::Publisher UDPexec_param = nh.advertise<fw_msgs::processer>("/communication/DDT/setudpexec", 10);

    int count = 0;

    while (	ros::ok() && (count < 5) )
	{	
        if(argc == 2){
            cout<<"///////////////set UDPsendflag as ://///////////////////"<<endl;
            ROS_INFO("execflag : %d", (int)udpexecmsg.execflag);
            UDPexec_param.publish(udpexecmsg);
            cout<<endl;
            count++;
        }

        else if(argc == 9){
            cout<<"///////////////set qgcommands as ://///////////////////"<<endl;
            ROS_INFO("uavid : %u", qgccommansmsg.uavid);
            ROS_INFO("gsid : %d", qgccommansmsg.gsid);
            ROS_INFO("uavnumber : %d", qgccommansmsg.uavnumber);
            ROS_INFO("tasktype : %d", qgccommansmsg.tasktype);
            ROS_INFO("plane_state : %d", qgccommansmsg.plane_state);
            ROS_INFO("plane_group : %d", qgccommansmsg.plane_group);
            ROS_INFO("gapx : %d", qgccommansmsg.gapx);
            ROS_INFO("gapy : %d", qgccommansmsg.gapy);
            cout<<endl;
            setqgcommands_param.publish(qgccommansmsg);
        
            count++;
        }
        else{
            return -1;
        }
        
        rate.sleep();
		ros::spinOnce();
    }
    return 0;
}