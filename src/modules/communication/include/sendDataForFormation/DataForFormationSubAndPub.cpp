#include "DataForFormationSubAndPub.hpp"

DataForFormationSubAndPub::DataForFormationSubAndPub(std::string uavName_){
    uavName = uavName_;

    gapsub = nh.subscribe<fw_msgs::uavflag>
        (uavName + "processer/uavflag",1,boost::bind(&DataForFormationSubAndPub::getgapvalue, this, _1));

    // distribution 
    formationPosition_pub = nh.advertise<fw_msgs::FormationPositionContoller>
        (uavName + "communication/formationData/positionController", 1);
    
    formationNavigator_pub = nh.advertise<fw_msgs::FormationNavigator>
        (uavName + "communication/formationData/navigator" , 1); // 需要加上飞机的编号
}
DataForFormationSubAndPub::~DataForFormationSubAndPub(){

}
void DataForFormationSubAndPub::newFormationShape(const fw_msgs::formations::ConstPtr& msg){
	formationShape = *msg;
}
void DataForFormationSubAndPub::newHomePosition(const fw_msgs::UpdHP::ConstPtr& msg){
    updHp = *msg;
}
void DataForFormationSubAndPub::newUdpData(const fw_msgs::UDPData::ConstPtr& msg){
    udpData = *msg;
}

void DataForFormationSubAndPub::getgapvalue(const fw_msgs::uavflag::ConstPtr& msg){
    gapvalue = *msg;
    myGap.x = gapvalue.gapx;
    myGap.y = gapvalue.gapy;
    leaderid = gapvalue.leaderid;
}

void DataForFormationSubAndPub::get_Initmsg(int _leaderid){
    string _leaderid_s = std::to_string(_leaderid);
    UpdHP_sub   = nh.subscribe<fw_msgs::UpdHP>
        (uavName + "communication/UpdHP" + _leaderid_s,10,boost::bind(&DataForFormationSubAndPub::newHomePosition, this, _1));
    UDPData_sub = nh.subscribe<fw_msgs::UDPData>
        (uavName + "communication/UDPData" + _leaderid_s,1,boost::bind(&DataForFormationSubAndPub::newUdpData, this, _1));
}

Point DataForFormationSubAndPub::getGap(std::string sysID){
    // 1. 根据编队类型
    ROS_ERROR("getGap(NAME)");
    char forma = formationShape.formationShape[0];
    Point gap{10, 10};
    Point *gaps_;
    cout << "enter set Gap: sysID[0]" << sysID[0] << std::endl;
    

    switch (sysID[0]) // uav2/
    {
    case '1': gaps_ = gaps[0]; break;
    case '2': gaps_ = gaps[1]; break;
    case '3': gaps_ = gaps[2]; break;
    case '4': gaps_ = gaps[3]; break;
    }
    switch(forma)
	{
	case 'Y': gap.x = gaps_[0].x; gap.y = gaps_[0].y; break;
	case 'T': gap.x = gaps_[1].x; gap.y = gaps_[1].y; break;
	case 'V': gap.x = gaps_[2].x; gap.y = gaps_[2].y; break;
	}
    return gap;
}
void DataForFormationSubAndPub::setData(std::string sysID){
    ROS_ERROR("setData(NAME)");

    formationNavigator.homeAlt = updHp.altitude;
    formationNavigator.homeLat = updHp.latitude;
    formationNavigator.homeLon = updHp.longitude;

    formationNavigator.gps_time = udpData.GPStime;
    formationNavigator.position_x = udpData.longitudex;
    formationNavigator.position_y = udpData.latitudey;
    formationNavigator.position_z = udpData.altitudez;
    formationNavigator.leaderAirspeed = udpData.velocity;
    formationNavigator.leaderHeading = udpData.heading;

    // gap的值
    // formationNavigator.gap_x = getGap(uavName).x;
    // formationNavigator.gap_y = getGap(uavName).y; 
    formationNavigator.gap_x = myGap.x;
    formationNavigator.gap_y = myGap.y; 

    formationPosition.count_number = udpData.number;
    formationPosition.leaderAirspeed = udpData.velocity;
    formationPosition.leaderCommand_yaw = udpData.commandyaw;
    formationPosition.leaderHeading = udpData.heading;
}

void DataForFormationSubAndPub::dataPublish(){
    ROS_ERROR("DATA PUBLISH");
    formationNavigator_pub.publish(formationNavigator);

    cout << "home alt : " << formationNavigator.homeAlt << endl;
    cout << "home lat : " << formationNavigator.homeLat << endl;
    cout << "home lon : " << formationNavigator.homeLon << endl;

    cout <<"gps_time.sec: " << formationNavigator.gps_time.sec << endl;
    cout << "position_z: " << formationNavigator.position_z << endl;
    cout << "position_x: " << formationNavigator.position_x <<endl;
    cout << "position_y : " << formationNavigator.position_y << endl;

    // gap的值
    cout << "gapx" << formationNavigator.gap_x << endl;
    cout << "gapy" << formationNavigator.gap_y << endl << endl;

    cout << "airspeed: " << formationPosition.leaderAirspeed << endl;
    cout << "commandYaw : " << formationPosition.leaderCommand_yaw << endl;
    cout << "heading : " << formationPosition.leaderHeading << endl;


    formationPosition_pub.publish(formationPosition);
}
void DataForFormationSubAndPub::showData(){
    cout << "home _ alt: " << updHp.altitude << endl;
    cout << "data _ commandyaw : " << udpData.commandyaw << endl;
}

void DataForFormationSubAndPub::setFormationShape(std::string formationShape_){
    formationShape.formationShape = formationShape_;
}
