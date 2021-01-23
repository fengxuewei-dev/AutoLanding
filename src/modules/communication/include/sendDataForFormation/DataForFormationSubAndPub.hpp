#pragma once

#include <ros/ros.h>

#include "fw_msgs/ACK.h"
#include "fw_msgs/UpdHP.h"
#include "fw_msgs/UDPData.h"
#include "fw_msgs/formations.h"
#include "fw_msgs/FormationData.h"
#include "fw_msgs/FormationNavigator.h"
#include "fw_msgs/FormationPositionContoller.h"
#include "../../../../lib/mathlib/vector/vector.hpp"
#include "fw_msgs/uavflag.h"

class DataForFormationSubAndPub{
    private:
        fw_msgs::FormationNavigator formationNavigator;
        fw_msgs::FormationPositionContoller formationPosition;
        fw_msgs::UpdHP updHp;
        fw_msgs::UDPData udpData;
        fw_msgs::formations formationShape;

        std::string uavName;
        std::string s_i;

        Point gaps[4][3] = {
            { {5,   5},  {0,   -5}, {-5,   5}},  // uav1: Y, T, V
            { {5,  -5},  {0,    5}, {-5,  -5}},  // uav2: Y, T, V
            { {-5,  0},  {-5,   0}, {-10, 10}},  // uav3: Y, T, V
            { {-10, 0},  {-10,  0}, {-10, -10}}  // uav4: Y, T, V
        };
        
    public:
        DataForFormationSubAndPub(std::string);
        ~DataForFormationSubAndPub();

        ros::NodeHandle nh;
        ros::Subscriber UpdHP_sub;
        ros::Subscriber UDPData_sub;
        ros::Subscriber formationShap_sub;
        ros::Subscriber dataForFormation_sub;
        
        ros::Publisher dataFormationAck_pub;
        ros::Publisher formationPosition_pub;
        ros::Publisher formationNavigator_pub;

        fw_msgs::uavflag gapvalue;
        ros::Subscriber gapsub;
        void getgapvalue(const fw_msgs::uavflag::ConstPtr& msg);
        Point myGap{-1, -1};
        int leaderid = -1;
        void get_Initmsg(int);
        
        void newHomePosition(const fw_msgs::UpdHP::ConstPtr& msg);
        void newUdpData(const fw_msgs::UDPData::ConstPtr& msg);
        void newDataForFormation(const fw_msgs::FormationData::ConstPtr& msg);
        void newFormationShape(const fw_msgs::formations::ConstPtr& msg);
        
        Point getGap(std::string);

        void showData();
        void dataPublish();
        void setData(std::string);
        

        void setFormationShape(std::string);

        fw_msgs::UDPData getUdpDataFromUdp()      {  return udpData;     }
        fw_msgs::UpdHP getHomePositionFromUdp()   {  return updHp;       }
};
