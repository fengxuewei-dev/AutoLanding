// ros程序必备头文件
#ifndef _VIR_MYUDP_HPP_
#define _VIR_MYUDP_HPP_

#include "../../include/communication/SendLib.h"
#include <mavros_msgs/WaypointList.h>
#include <sensor_msgs/NavSatFix.h> 
#include <sensor_msgs/TimeReference.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>
#include <mavros_msgs/HomePosition.h>
#include <mavros_msgs/VFR_HUD.h>
#include "../../../../lib/Macro.hpp"
#include "fw_msgs/Yaw.h"
#include <typeinfo>

#include "fw_msgs/udpDataTypes.h"

#include "../../../../lib/logger/LoggerUdp.hpp"
#define DEFAULT_IP_ADDRESS  "127.0.0.1"

//GPS位置
sensor_msgs::NavSatFix current_gpsposition;
void gpsposition_cb(const sensor_msgs::NavSatFix::ConstPtr& msg){
    current_gpsposition = *msg;
}

geometry_msgs::PoseStamped current_localposition;
void localposition_cb(const geometry_msgs::PoseStamped::ConstPtr& msg){
    current_localposition = *msg;
}

geometry_msgs::TwistStamped current_velocity;
void localvelocity_cb(const geometry_msgs::TwistStamped::ConstPtr& msg){
    current_velocity = *msg;
}

mavros_msgs::VFR_HUD current_state;
void state_cb(const mavros_msgs::VFR_HUD::ConstPtr& msg){
    current_state = *msg;
}

/////////////////////////////////////////////////////////////////////////////////////////////
mavros_msgs::VFR_HUD current_Leader_state;
void newLeaderState(const mavros_msgs::VFR_HUD::ConstPtr& msg){
    current_Leader_state = *msg;
}

geometry_msgs::PoseStamped current_leaderPose;
void new_leaderPose(const geometry_msgs::PoseStamped::ConstPtr& msg){
	current_leaderPose = *msg;
}

fw_msgs::Yaw current_leaderCommand;
void new_leaderCommands(const fw_msgs::Yaw::ConstPtr& msg){
	current_leaderCommand = *msg;
}
 
sensor_msgs::TimeReference GPS_time;
void new_GPSTime(const sensor_msgs::TimeReference::ConstPtr& msg){
	GPS_time = *msg;
}

mavros_msgs::HomePosition current_home;
void homePosition_cb(const mavros_msgs::HomePosition::ConstPtr& msg){
    current_home = *msg;
}

fw_msgs::udpDataTypes processer_control;
void processer_cb(const fw_msgs::udpDataTypes::ConstPtr& msg){
	processer_control = *msg;
}
// 测试集群的时候, 主机和从机要进行端口指定, 不能使用默认的, 代码需要改动一下
// rosrun communication UDP_Send 
//          -t p 
//         -mt AC -ip 192.168.1.198
// rosrun communication UDP_Send -t p -mt AC -ip 192.168.1.198
// rosrun communication UDP_Send -mt UH: -mt 指定消息类型 默认为本机所有的网络下的8002端口
// rosrun communication UDP_Send -mt UD
///////////////////////////////////////////////////////////main/////////////////////////////////////////////////////////


int main(int argc, char **argv)
{
  
  std::string nodeName = "myudp_send";
  int uavid = 0;
  std::string uavName = "";
  if(argc >= 2){
    if(argv[1] == (string)("0")){
      cout<<"single mode"<<endl;\
      uavid = LOCALUAVID;
      
    }
    else{
      std::string number = argv[1];
      nodeName = nodeName.append(number, 0, 1);
      uavName = argv[1];
      uavName = uavName + "/";
      char s_id = uavName[3];
      uavid = s_id - '0';
      cout<<"use mulit sitl mode, current id is : "<<uavid<<", uav name is : "<<uavName<<endl;;
    } 
  }
  
  ros::init(argc, argv, nodeName);
  
  loggerSend LOGGERSEND("send", uavName);

  ros::NodeHandle nh;

	ros::Subscriber leader_state_sub = nh.subscribe<mavros_msgs::VFR_HUD>  (uavName + "msgsFromPx4/vfr_hud", 1, newLeaderState);
	ros::Subscriber leader_localPos_sub = nh.subscribe<geometry_msgs::PoseStamped> (uavName + "msgsFromPx4/local_position/pose",1,new_leaderPose);
	ros::Subscriber GPStime_sub = nh.subscribe<sensor_msgs::TimeReference>(uavName + "msgsFromPx4/time_reference",1,new_GPSTime);
  ros::Subscriber home_sub = nh.subscribe<mavros_msgs::HomePosition> (uavName + "msgsFromPx4/home_position/home", 10, homePosition_cb);
  ros::Subscriber leaderCommands_sub = nh.subscribe<fw_msgs::Yaw>(uavName + "communication/yaw",1,new_leaderCommands);

  ros::Subscriber processer_sub = nh.subscribe<fw_msgs::udpDataTypes>( "uav0/communication/taskTypes/udpDataTypes",1,processer_cb);
  
  ros::Rate rate(UDP_COMMUNICATION_SEND);

  /*******************************************************************UDP*************************************************/
   /* socket文件描述符 */
  int sock_fd;
  sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sock_fd < 0)
  {
    perror("socket");
    exit(1);
  }

  std::vector<int> port;
  // port.push_back(DEFAULT_PORT);
  std::vector<int> len;
  std::vector<struct sockaddr_in>addr_serv;
  std::vector<char*> ipaddress;
  struct sockaddr_in addr_serv_temp;

  bool isradio = true;
  // int messagetype = 0;
  bool messagetype_UD = false;
  bool messagetype_UH = false;
  bool messagetype_AC = false;
  bool messagetype_QC = false;

  if(argc >= 3){
    int argnum = 2;
    while (argnum < argc)
    {
      // rosrun communication UDP_Send -t p -mt AC -ip 192.168.1.198
      // -t p 点对点模式 需要后面加上对应的IP地址
      // 没有 -t p 的时候, 是发送不同的消息
      if(argv[argnum] == (string)("-t")){//广播type
        if(argv[argnum + 1] == (string)("p")){
          cout<<"at "<<argnum<<endl;
          cout<<"send type is point to point"<<endl;
          isradio = false;
        }  
        argnum = argnum + 2;
      }
      else if(argv[argnum] == (string)("-mt")){//messagetype
        cout<<"at "<<argnum<<endl;
        if(argv[argnum + 1] == (string)("UD")){
            // messagetype = UD;
            messagetype_UD = true;
            cout<<"UD is choiced, id:"<<messagetype_UD<<endl;            
        }
        else if(argv[argnum + 1] == (string)("AC")){
            // messagetype = AC;
            messagetype_AC = true;
            cout<<"AC is choiced, id:"<<messagetype_AC<<endl;
        }
        else if(argv[argnum + 1] == (string)("UH")){
            // messagetype = UH;
            messagetype_UH = true;
            cout<<"UH is choiced, id:"<<messagetype_UH<<endl;
        }
        else if(argv[argnum + 1] == (string)("QC")){
            // messagetype = QC;
            messagetype_QC = true;
            cout<<"QC is choiced, id:"<<messagetype_QC<<endl;
        }
        argnum = argnum + 2;  
      }
      else if(argv[argnum] == (string)("-ip") && isradio == false ){ // get the ports
        while(argv[argnum+1] != (string)("-p")){
          ipaddress.push_back(argv[++argnum]);
          cout<<"at "<<argnum<<", using IP : "<<ipaddress[ipaddress.size()-1]<<endl;
        }
        
      }
      else if(argv[argnum] == (string)("-p")){
        while((argnum + 1 < argc)){
          port.push_back(atoi(argv[++argnum]));        // 数组添加
          cout<<"at "<<argnum<<", port : "<<port[port.size()-1]<<endl;
        }
      }
      else{
        argnum++;
        cout<<"param error : "<< argnum<<endl;
      }
        
    }
  } 
  
  cout<<"send type is radio? "<<isradio<<endl;



  char* ip_p2p = (char*)"192.168.1.198";
  ipaddress.push_back(ip_p2p);
  std::vector<struct sockaddr_in>addr_serv_p2p;
  std::vector<int> len_p2p;
  for(int j = 0; j < ipaddress.size(); j++){
      cout<<ipaddress[j]<<endl;
      memset(&addr_serv_temp, 0, sizeof(addr_serv_temp));
      addr_serv_temp.sin_family = AF_INET;
      addr_serv_temp.sin_addr.s_addr = inet_addr(ipaddress[j]);
      addr_serv_temp.sin_port = htons(8002); // 已经修改好了
      len_p2p.push_back(sizeof(addr_serv_temp));
      addr_serv_p2p.push_back(addr_serv_temp);
  }
    
  
  
  const int opt = 1;
  //设置该套接字为广播类型，
  int nb = 0;
  setsockopt(sock_fd, SOL_SOCKET, SO_BROADCAST, (char *)&opt, sizeof(opt));
  for (int i = 0; i < port.size(); i++)
  {
    cout<<"use port ： "<<port[i]<<endl;
    memset(&addr_serv_temp, 0, sizeof(addr_serv_temp));
    addr_serv_temp.sin_family = AF_INET;
    addr_serv_temp.sin_addr.s_addr = htonl(INADDR_BROADCAST);
    addr_serv_temp.sin_port = htons(port[i]);
    len.push_back(sizeof(addr_serv_temp));
    addr_serv.push_back(addr_serv_temp);
  }   
  

  Senddata send_buf;
  UDP_Data UDP_buf;
  Upd_HP UPDH_buf;
  ACK ACK_buf;
  Qgc_Commands QC_buf;


  /*******************************************************************UDP*************************************************/
  while(ros::ok()){

    messagetype_UD = true;
    messagetype_UH = true;
    messagetype_AC = false;

    if(processer_control.startUDP_Data == 1){
      messagetype_UD = true;
      cout<<"send UD message now"<<endl;
    }

    if(processer_control.startUPD_HOME == 1){
      messagetype_UH = true;
      cout<<"send UH message now"<<endl;
    }

    if(processer_control.startACK == 1){
      messagetype_AC = true;
      cout<<"send AC message now"<<endl;
    }
      

     
    ros::spinOnce();
    printf("///////////////////////////Cycle Start//////////////////////////////////////\n");
    // 工作任务: 
    // 数据来源需要改一下
    // plane_state 发送的时候进行一个编码, 接收的时候进行一个解码

    // *****  msg id 不能改
    if(messagetype_UD == true){ // UD: 1 通用型的消息
      UDP_buf.message_id = UD;
      UDP_buf.uav_id = uavid;        // 飞机的编号(相当于整个集群的(从1开始 , 0是默认位)) // 自定义飞机属性的消息; 
      UDP_buf.plane_state = 1;    // 
      UDP_buf.plane_group = 1;
      
      ++UDP_buf.number;

      // ned
      UDP_buf.longitude_x = current_leaderPose.pose.position.x; 
      UDP_buf.latitude_y = current_leaderPose.pose.position.y;
      UDP_buf.altitude_z = current_leaderPose.pose.position.z;
      
      UDP_buf.heading = current_Leader_state.heading;
      
      // 改动
      UDP_buf.velocity = current_Leader_state.airspeed;

      // UDP_buf.command_yaw = current_leaderCommand.yaw;
      // UDP_buf.command_yaw = current_leaderCommand.yaw * M_PI / 180.0;
	UDP_buf.command_yaw = (current_Leader_state.heading) * (M_PI / 180);
      std::cout << "heading : " <<current_Leader_state.heading << "so command_yaw = " <<UDP_buf.command_yaw << std::endl;
      


      UDP_buf.GPS_time = GPS_time.time_ref;
      UDP_buf.parity = (int)(UDP_buf.message_id + UDP_buf.uav_id + UDP_buf.plane_state  + UDP_buf.longitude_x + UDP_buf.latitude_y + 
                                UDP_buf.altitude_z + UDP_buf.heading + UDP_buf.velocity + UDP_buf.command_yaw + UDP_buf.GPS_time.nsec + 
                                UDP_buf.GPS_time.sec);
      printf("///////////////////////////UD//////////////////////////////////////\n");
      cout<<"GPS time is : "<<UDP_buf.GPS_time.sec<<"."<<UDP_buf.GPS_time.nsec<<", size is : "<<sizeof(UDP_buf.GPS_time)<<endl;
      std::cout << std::endl;
      std::cout<<"send number   is:"<<UDP_buf.number<<std::endl;
      std::cout<<"send message_id    is:"<<UDP_buf.message_id<<std::endl;
      std::cout<<"send uav_id   is:"<<UDP_buf.uav_id<<std::endl;
      std::cout<<"send plane_state is:"<<UDP_buf.plane_state<<std::endl;
      std::cout<<"send plane_group is:"<<UDP_buf.plane_group<<std::endl;
      std::cout<<"send longitude_x is:"<<UDP_buf.longitude_x<<std::endl;
      std::cout<<"send latitude_y is:"<<UDP_buf.latitude_y<<std::endl;
      std::cout<<"send altitude_z is:"<<UDP_buf.altitude_z<<std::endl;
      std::cout<<"send heading        is:"<<UDP_buf.heading<<std::endl;
      std::cout<<"send velocity    is:"<<UDP_buf.velocity<<std::endl;
      std::cout<<"send command_yaw   is:"<<UDP_buf.command_yaw<<std::endl;
      std::cout<<"send Parity is:"<<UDP_buf.parity<<std::endl; 
      LOGGERSEND.UdpData_altitude_z.logPrint(UDP_buf.altitude_z);
      LOGGERSEND.UdpData_latitude_y.logPrint(UDP_buf.latitude_y);
      LOGGERSEND.UdpData_longitude_x.logPrint(UDP_buf.longitude_x);


      LOGGERSEND.UdpData_command_yaw.logPrint(UDP_buf.command_yaw);
      LOGGERSEND.UdpData_heading.logPrint(UDP_buf.heading);
      LOGGERSEND.UdpData_GPS_time_sec.logPrint(UDP_buf.GPS_time.sec);
      LOGGERSEND.UdpData_GPS_time_nsec.logPrint(UDP_buf.message_id);
      LOGGERSEND.UdpData_number.logPrint(UDP_buf.number);
      LOGGERSEND.UdpData_parity.logPrint(UDP_buf.parity);
      LOGGERSEND.UdpData_plane_group.logPrint(UDP_buf.plane_group);
      LOGGERSEND.UdpData_plane_state.logPrint(UDP_buf.plane_state);
      LOGGERSEND.UdpData_uav_id.logPrint(UDP_buf.uav_id);
      LOGGERSEND.UdpData_velocity.logPrint(UDP_buf.velocity);
    }

    if(messagetype_AC == true){ 
      ACK_buf.message_id = AC;
      ACK_buf.uav_id = uavid;
      ACK_buf.judge = 1;
      ACK_buf.GPS_time = GPS_time.time_ref;
      ACK_buf.parity = (int)(ACK_buf.message_id + ACK_buf.uav_id + ACK_buf.judge + ACK_buf.GPS_time.nsec + ACK_buf.GPS_time.sec);
      printf("///////////////////////////AC//////////////////////////////////////\n");
      cout<<"GPS time is : "<<ACK_buf.GPS_time.sec<<"."<<ACK_buf.GPS_time.nsec<<", size is : "<<sizeof(ACK_buf.GPS_time)<<endl;
      std::cout<<"send message_id    is:"<<ACK_buf.message_id<<std::endl;
      std::cout<<"send uav_id   is:"<<ACK_buf.uav_id<<std::endl;
      std::cout<<"send judge is:"<<ACK_buf.judge<<std::endl;
      std::cout<<"send Parity is:"<<ACK_buf.parity<<std::endl; 

      LOGGERSEND.ACK_judge.logPrint(ACK_buf.judge);
      LOGGERSEND.ACK_message_id.logPrint(ACK_buf.message_id);
      LOGGERSEND.ACK_uav_id.logPrint(ACK_buf.uav_id);
      LOGGERSEND.ACK_parity.logPrint(ACK_buf.parity);
      LOGGERSEND.ACK_Gps_time_sec.logPrint(ACK_buf.GPS_time.sec);
      LOGGERSEND.ACK_Gps_time_nsec.logPrint(ACK_buf.GPS_time.nsec);
    }
    if(messagetype_UH == true){
      UPDH_buf.message_id = UH;
      UPDH_buf.uav_id = uavid;
      UPDH_buf.longitude = current_home.geo.longitude;
      UPDH_buf.latitude = current_home.geo.latitude;
      UPDH_buf.altitude = current_home.geo.altitude;
      UPDH_buf.parity = (int)(UPDH_buf.message_id + UPDH_buf.uav_id + UPDH_buf.longitude  + UPDH_buf.latitude + UPDH_buf.altitude);
      printf("///////////////////////////UH//////////////////////////////////////\n");
      std::cout<<"send message_id    is:"<<UPDH_buf.message_id<<std::endl;
      std::cout<<"send uav_id   is:"<<UPDH_buf.uav_id<<std::endl;
      std::cout<<"send longitude_x is:"<<UPDH_buf.longitude<<std::endl;
      std::cout<<"send latitude_y is:"<<UPDH_buf.latitude<<std::endl;
      std::cout<<"send altitude_z is:"<<UPDH_buf.altitude<<std::endl;
      std::cout<<"send Parity is:"<<UPDH_buf.parity<<std::endl; 

      LOGGERSEND.Home_message_id.logPrint(UPDH_buf.message_id);
      LOGGERSEND.Home_uav_id.logPrint(UPDH_buf.uav_id);
      LOGGERSEND.Home_longitude.logPrint(UPDH_buf.longitude);
      LOGGERSEND.Home_latitude.logPrint(UPDH_buf.latitude);
      LOGGERSEND.Home_altitude.logPrint(UPDH_buf.altitude);
      LOGGERSEND.Home_parity.logPrint(UPDH_buf.parity);
    }

    if(messagetype_QC == true){
      QC_buf.message_id = QC;
      QC_buf.gs_id = 1;
      QC_buf.uav_id = uavid;
      QC_buf.vehicleNumber = 40;
      QC_buf.taskType = 1;
      QC_buf.plane_state = 2;
      QC_buf.plane_group = 2;
      QC_buf.gapx = 5;
      QC_buf.gapy = 5;
      QC_buf.GPS_time = 100.111;
      QC_buf.parity = (int)(QC_buf.message_id + QC_buf.gs_id + QC_buf.uav_id + QC_buf.vehicleNumber + QC_buf.taskType + QC_buf.plane_state + 
                            QC_buf.gapx + QC_buf.gapy + QC_buf.GPS_time);
      printf("///////////////////////////QC//////////////////////////////////////\n");
      cout<<"GPS time is : "<<QC_buf.GPS_time<<endl;
      std::cout<<"send message_id    is:"<<QC_buf.message_id<<std::endl;
      std::cout<<"send uav_id   is:"<<QC_buf.uav_id<<std::endl;
      std::cout<<"send gs_id    is:"<<QC_buf.gs_id<<std::endl;
      std::cout<<"send vehicleNumber   is:"<<QC_buf.vehicleNumber<<std::endl;
      std::cout<<"send taskType    is:"<<QC_buf.taskType<<std::endl;
      std::cout<<"send plane_state   is:"<<QC_buf.plane_state<<std::endl;
      std::cout<<"send plane_state   is:"<<QC_buf.plane_group<<std::endl;
      std::cout<<"send gapx    is:"<<QC_buf.gapx<<std::endl;
      std::cout<<"send gapy    is:"<<QC_buf.gapy<<std::endl;
      std::cout<<"send Parity is:"<<QC_buf.parity<<std::endl; 
    }
    
    // send_buf.heading = current_Leader_state.heading;
    // send_buf.airspeed = current_Leader_state.airspeed;
    // send_buf.position_x = current_leaderPose.pose.position.x;
    // send_buf.position_y = current_leaderPose.pose.position.y;
    // send_buf.position_z = current_leaderPose.pose.position.z;
    // send_buf.yaw = current_leaderCommand.yaw;

    // send_buf.id++;
    // send_buf.Parity = (int)(send_buf.heading + send_buf.airspeed + send_buf.position_x + send_buf.position_y + send_buf.position_z + send_buf.yaw );
    
    // cout<<"GPS time is : "<<GPS_time.time_ref.sec<<"."<<GPS_time.time_ref.nsec<<", size is : "<<sizeof(GPS_time.time_ref)<<endl;
    // std::cout<<"send heading    is:"<<send_buf.heading<<std::endl;
    // std::cout<<"send airspeed   is:"<<send_buf.airspeed<<std::endl;
    // std::cout<<"send position_x is:"<<send_buf.position_x<<std::endl;
    // std::cout<<"send position_y is:"<<send_buf.position_y<<std::endl;
    // std::cout<<"send position_z is:"<<send_buf.position_z<<std::endl;
    // std::cout<<"send yaw        is:"<<send_buf.yaw<<std::endl;
    // std::cout<<"message:"<<send_buf.id<<" Parity is:"<<send_buf.Parity<<std::endl;
    if (messagetype_UD == true)
    {
        cout<<"send UD use broadcast"<<endl;
        for (int i = 0; i < addr_serv.size(); i++){
          RunSend(sock_fd, UDP_buf, addr_serv[i], len[i]);
        }
      // if(/*(int)(addr_serv.size()) > 0*/0){//useless
      //   for (int i = 0; i < addr_serv_p2p.size(); i++){
      //     RunSend(sock_fd, UDP_buf, addr_serv_p2p[i], len_p2p[i]);
      //   }
      // }
      // else{
      //   cout<<"send UD use broadcast"<<endl;
      //   RunSend(sock_fd, UDP_buf, addr_serv[0], len[0]);
      // } 
    }
    if(messagetype_AC == true){
      for (int i = 0; i < addr_serv_p2p.size(); i++){
          cout<<"use p2p mode"<<endl;
          RunSend(sock_fd, ACK_buf, addr_serv_p2p[i], len_p2p[i]);
        }
      // if(addr_serv_p2p.size() > 0){
      //   for (int i = 0; i < addr_serv_p2p.size(); i++){
      //     cout<<"use p2p mode"<<endl;
      //     RunSend(sock_fd, ACK_buf, addr_serv_p2p[i], len_p2p[i]);
      //   }
      // }
      // else{//useless
      //   RunSend(sock_fd, ACK_buf, addr_serv[0], len[0]);
      // } 
    }
    if(messagetype_UH == true){
        cout<<"send UH use broadcast"<<endl;
        for (int i = 0; i < addr_serv.size(); i++){
          RunSend(sock_fd, UPDH_buf, addr_serv[i], len[i]);
        }
      // if(/*addr_serv.size() > 0*/0){//useless
      //   for (int i = 0; i < addr_serv.size(); i++){
      //     RunSend(sock_fd, UPDH_buf, addr_serv[i], len[i]);
      //   }
      // }
      // else{
      //   cout<<"send UH use broadcast"<<endl;
      //   RunSend(sock_fd, UPDH_buf, addr_serv[0], len[0]);
      // } 
    }
    if(messagetype_QC == true){
        cout<<"send QC use broadcast"<<endl;
        RunSend(sock_fd, QC_buf, addr_serv[0], len[0]);
      // if(/*addr_serv.size() > 0*/0){
      //   for (int i = 0; i < addr_serv.size(); i++){
      //     RunSend(sock_fd, QC_buf, addr_serv[i], len[i]);
      //   }
      // }
      // else{
      //   cout<<"send QC use broadcast"<<endl;
      //   RunSend(sock_fd, QC_buf, addr_serv[0], len[0]);
      // } 
    }
    printf("///////////////////////////Cycle End////////////////////////////////////////\n");
    rate.sleep();
    
  }

  close(sock_fd);
  return 0;
}
#endif
