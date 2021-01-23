#include "LogStream.hpp"

class logger_ACK{
    public: 
        string pathName;
        string uavName;
        logStream<unsigned short int> ACK_message_id;//消息类型
        logStream<unsigned short int> ACK_uav_id;//本机的总体编号
        logStream<bool> ACK_judge;
        logStream<int> ACK_parity;
        logStream<long int> ACK_Gps_time_sec;//发送的GPS时间，unsign int
        logStream<long int> ACK_Gps_time_nsec;//发送的GPS时间，unsign int

        logger_ACK(std::string, std::string);
        ~logger_ACK();
        
};
logger_ACK::logger_ACK(std::string pathName_, std::string _uavName_):uavName(_uavName_), pathName(pathName_){
    ACK_judge.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"judge", "judge");
    ACK_uav_id.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"ACK", "uav", "id");
    ACK_parity.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"parity", "parity");
    ACK_message_id.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"ACK", "message", "id");
    ACK_Gps_time_sec.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"ACK", "Gps_time", "sec");
    ACK_Gps_time_nsec.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"ACK", "Gps_time", "nsec");
}
logger_ACK::~logger_ACK(){}

class logger_QGC_Command{
    public: 
        string pathName;
        string uavName;
        logStream<unsigned short int> QGC_Command_message_id;//消息类型
        logStream<unsigned short int> QGC_Command_gs_id;//地面站id，用于多个地面站区分
        logStream<unsigned short int> QGC_Command_uav_id;//指定控制的飞机
        logStream<int> QGC_Command_taskType;              
        logStream<short int> QGC_Command_plane_state;//设置组号+组内的还是状态 全0为自组织
        logStream<short int> QGC_Command_plane_group;//设置组号+组内的还是状态 全0为自组织
        logStream<short int> QGC_Command_gapx; 
        logStream<short int> QGC_Command_gapy; 
        logStream<double> QGC_Command_GPS_time;//发送的GPS时间，unsign int
        logStream<int> QGC_Command_parity;              // 校验位
        logger_QGC_Command(std::string, std::string);
        ~logger_QGC_Command();
};
// /logs/uavX/send(receive)/QGC_Command
logger_QGC_Command::logger_QGC_Command(std::string pathName_, std::string _uavName_):uavName(_uavName_), pathName(pathName_){
    QGC_Command_taskType.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"QGC_Command", "taskType");
    QGC_Command_gapx.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"QGC_Command", "gap", "x");
    QGC_Command_gapy.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"QGC_Command", "gap", "y");
    QGC_Command_uav_id.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"QGC_Command", "uav", "id");
    QGC_Command_message_id.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"QGC_Command", "message", "id");
    QGC_Command_gs_id.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"QGC_Command", "message", "id");
    QGC_Command_plane_state.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"QGC_Command", "plane", "state");
    QGC_Command_plane_group.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"QGC_Command", "plane", "group");

}
logger_QGC_Command::~logger_QGC_Command(){

}
class logger_Home{
    public:
        string pathName;
        string uavName;
        logStream<unsigned short int> Home_message_id;  //消息类型
        logStream<unsigned short int> Home_uav_id;      //本机的总体编号
        logStream<double> Home_longitude;
        logStream<double> Home_latitude;
        logStream<double> Home_altitude;  
        logStream<int> Home_parity;                     // 校验位
        logger_Home(std::string, std::string);
        ~logger_Home();
};
logger_Home::logger_Home(std::string pathName_, std::string _uavName_):uavName(_uavName_), pathName(pathName_){
    Home_parity.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"Home", "parity");
    Home_latitude.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"Home", "latitude");
    Home_altitude.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"Home", "altitude");
    Home_longitude.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"Home", "longitude");
    Home_uav_id.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"Home", "uav", "id");
    Home_message_id.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"Home", "message", "id");
}
logger_Home::~logger_Home(){

}
class logger_UdpData{
    public:
        string pathName;
        string uavName;
        logStream<unsigned short int> UdpData_message_id;//消息类型
        logStream<unsigned short int> UdpData_uav_id;//本机的总体编号
        logStream<unsigned short int> UdpData_plane_state;//本机的组内类型（主/从）
        logStream<unsigned short int> UdpData_plane_group;//本机的组号
        logStream<long int> UdpData_number;
        logStream<double> UdpData_longitude_x;
        logStream<double> UdpData_latitude_y;
        logStream<double> UdpData_altitude_z;  
        logStream<double> UdpData_heading;//本机的当前航向，主要用于
        logStream<double> UdpData_velocity;        // 掌机实时空速
        logStream<double> UdpData_command_yaw;//发送的主机计算后的yaw
        logStream<long int> UdpData_GPS_time_sec;//发送的GPS时间，unsign int
        logStream<long int> UdpData_GPS_time_nsec;//发送的GPS时间，unsign int
        logStream<int> UdpData_parity;              // 校验位
        logger_UdpData(std::string, std::string);
        ~logger_UdpData();
};
// "/home/fengxuewei/GitHub/uav_project_1/fixedWing_ws/src/logs" + "udp_send" + 
logger_UdpData::logger_UdpData(std::string pathName_, std::string _uavName_):uavName(_uavName_), pathName(pathName_){
    UdpData_parity.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"UdpData", "parity");
    UdpData_number.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"UdpData", "number");
    UdpData_heading.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"UdpData", "heading");
    UdpData_velocity.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"UdpData", "velocity");
    UdpData_uav_id.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"UdpData", "uav", "id");
    UdpData_altitude_z.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"UdpData", "altitude", "z");
    UdpData_latitude_y.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"UdpData", "latitude", "y");
    UdpData_message_id.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"UdpData", "message", "id");
    UdpData_plane_state.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"UdpData", "plane", "state");
    UdpData_plane_group.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"UdpData", "plane", "group");
    UdpData_longitude_x.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"UdpData", "longitude", "x");
    UdpData_command_yaw.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"UdpData", "command", "yaw");
    UdpData_GPS_time_sec.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"UdpData", "GPS_time", "sec");
    UdpData_GPS_time_nsec.configuration
        (std::string(LOGGERPATH) + "/" + uavName + pathName + "/" +"UdpData", "GPS_time", "nsec");
}
logger_UdpData::~logger_UdpData(){

}

class loggerSend: public logger_UdpData, public logger_Home, public logger_ACK{
    private:
        string pathName;
        string uavName;
    public:
        loggerSend(std::string, std::string);
        ~loggerSend();
};
loggerSend::loggerSend(std::string pathName_, std::string _uavName_)
    :logger_UdpData(pathName_, _uavName_), 
    logger_Home(pathName_, _uavName_), 
    logger_ACK(pathName_, _uavName_)
{
    pathName = pathName_;
    uavName = _uavName_;
}
loggerSend::~loggerSend(){

}

class loggerReceive: public logger_QGC_Command, public logger_UdpData, public logger_Home, public logger_ACK{
    private:
        string pathName;
        string uavName;
    public:
        loggerReceive(std::string, std::string);
        ~loggerReceive();
};
loggerReceive::loggerReceive(std::string pathName_, std::string _uavName_)
    :logger_QGC_Command(pathName_, _uavName_), 
    logger_UdpData(pathName_, _uavName_), 
    logger_Home(pathName_, _uavName_), 
    logger_ACK(pathName_, _uavName_)
{
    pathName = pathName_;
    uavName = _uavName_;
}
loggerReceive::~loggerReceive(){}
