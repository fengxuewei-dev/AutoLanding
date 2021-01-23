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
#include <mavros_msgs/State.h>
#include "../../../../lib/Macro.hpp"
#include "communication/Yaw.h"
#include <typeinfo>

#include "communication/udpDataTypes.h"
#include <fstream>
#define DEFAULT_IP_ADDRESS  "127.0.0.1"

#define LEADER_DATA_PATH \
  "/home/pi/fixedWing_ws/src/logs/"
  
#define LEADER_LOCAL_Z_PATH \
   "/home/pi/fixedWing_ws/src/logs/leader/local/z/"
   
#define LOG_NAME \
  "2020-09-23 16:42:22.log"
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

mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
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

communication::Yaw current_leaderCommand;
void new_leaderCommands(const communication::Yaw::ConstPtr& msg){
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

communication::udpDataTypes processer_control;
void processer_cb(const communication::udpDataTypes::ConstPtr& msg){
	processer_control = *msg;
}

int main(int argc, char **argv)
{
  
  std::string nodeName = "myudp_sendtxt";
  int uavid = 0;
  std::string uavName = "";
  if(argc >= 2){
    if(argv[1] == (string)("0")){
      cout<<"single mode"<<endl;\
      uavid = LOCALUAVID;
      
    }
    else{
      std::string number = argv[1];
      nodeName = nodeName.append(number, 3, 1);
      uavName = argv[1];
      uavName = uavName + "/";
      char s_id = uavName[3];
      uavid = s_id - '0';
      cout<<"use mulit sitl mode, current id is : "<<uavid<<", uav name is : "<<uavName<<endl;;
    } 
  }
  
  ros::init(argc, argv, nodeName);
  
  ros::NodeHandle nh;

	ros::Subscriber leader_state_sub = nh.subscribe<mavros_msgs::VFR_HUD>  (uavName + "msgsFromPx4/vfr_hud", 1, newLeaderState);
  ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>(uavName + "msgsFromPx4/state", 1, state_cb);
	ros::Subscriber leader_localPos_sub = nh.subscribe<geometry_msgs::PoseStamped> (uavName + "msgsFromPx4/local_position/pose",1,new_leaderPose);
	ros::Subscriber GPStime_sub = nh.subscribe<sensor_msgs::TimeReference>(uavName + "msgsFromPx4/time_reference",1,new_GPSTime);
  ros::Subscriber home_sub = nh.subscribe<mavros_msgs::HomePosition> (uavName + "msgsFromPx4/home_position/home", 10, homePosition_cb);
  ros::Subscriber leaderCommands_sub = nh.subscribe<communication::Yaw>(uavName + "communication/yaw",1,new_leaderCommands);

  ros::Subscriber processer_sub = nh.subscribe<communication::udpDataTypes>( "uav0/communication/taskTypes/udpDataTypes",1,processer_cb);
  
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
    // while (argnum < argc)
    // {
    //   // rosrun communication UDP_Send -t p -mt AC -ip 192.168.1.198
    //   // -t p 点对点模式 需要后面加上对应的IP地址
    //   // 没有 -t p 的时候, 是发送不同的消息
    //   if(argv[argnum] == (string)("-t")){//广播type
    //     if(argv[argnum + 1] == (string)("p")){
    //       cout<<"at "<<argnum<<endl;
    //       cout<<"send type is point to point"<<endl;
    //       isradio = false;
    //     }  
    //     argnum = argnum + 2;
    //   }
    //   else if(argv[argnum] == (string)("-mt")){//messagetype
    //     cout<<"at "<<argnum<<endl;
    //     if(argv[argnum + 1] == (string)("UD")){
    //         // messagetype = UD;
    //         messagetype_UD = true;
    //         cout<<"UD is choiced, id:"<<messagetype_UD<<endl;            
    //     }
    //     else if(argv[argnum + 1] == (string)("AC")){
    //         // messagetype = AC;
    //         messagetype_AC = true;
    //         cout<<"AC is choiced, id:"<<messagetype_AC<<endl;
    //     }
    //     else if(argv[argnum + 1] == (string)("UH")){
    //         // messagetype = UH;
    //         messagetype_UH = true;
    //         cout<<"UH is choiced, id:"<<messagetype_UH<<endl;
    //     }
    //     else if(argv[argnum + 1] == (string)("QC")){
    //         // messagetype = QC;
    //         messagetype_QC = true;
    //         cout<<"QC is choiced, id:"<<messagetype_QC<<endl;
    //     }
    //     argnum = argnum + 2;  
    //   }
    //   else if(argv[argnum] == (string)("-ip") && isradio == false ){ // get the ports
    //     while(argv[argnum+1] != (string)("-p")){
    //       ipaddress.push_back(argv[++argnum]);
    //       cout<<"at "<<argnum<<", using IP : "<<ipaddress[ipaddress.size()-1]<<endl;
    //     }
        
    //   }
    //   else if(argv[argnum] == (string)("-p")){
    //     while((argnum + 1 < argc)){
    //       port.push_back(atoi(argv[++argnum]));        // 数组添加
    //       cout<<"at "<<argnum<<", port : "<<port[port.size()-1]<<endl;
    //     }
    //   }
    //   else{
    //     argnum++;
    //     cout<<"param error : "<< argnum<<endl;
    //   }
        
    // }
  } 
  
  cout<<"send type is radio? "<<isradio<<endl;



  char* ip_p2p = (char*)"127.0.0.1";
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
    addr_serv_temp.sin_port = htons(8002);
    // addr_serv_temp.sin_port = htons(port[i]);
    len.push_back(sizeof(addr_serv_temp));
    addr_serv.push_back(addr_serv_temp);
  }   
  

  Senddata send_buf;
  UDP_Data UDP_buf;
  Upd_HP UPDH_buf;
  ACK ACK_buf;
  Qgc_Commands QC_buf;

  std::vector<string> txtname(11);
  txtname[0] = "/home/fengxuewei/GitHub/uav_project_1/fixedWing_ws/src/leader_date/yaw_date.txt";
  txtname[1] = "/home/fengxuewei/GitHub/uav_project_1/fixedWing_ws/src/leader_date/local_x.txt";
  txtname[2] = "/home/fengxuewei/GitHub/uav_project_1/fixedWing_ws/src/leader_date/local_y.txt";
  txtname[3] = "/home/fengxuewei/GitHub/uav_project_1/fixedWing_ws/src/leader_date/local_z.txt";
  double buf[4];
  ifstream fin[4];

  for (int i = 0; i < 4; i++)
  {
    fin[i].open(txtname[i]);
    if (fin[i].peek() == EOF)
    {
      cout <<"No."<< i+1<< " file is empty."<<endl;
      return 0;
    }
  }
  string __buf__ = "";
  char __buf__data[20];

  string buf_home = "";
  char buf_home_x[20];
  char buf_home_y[20];
  char buf_home_z[20];
  double home_x = 0;
  double home_y = 0;
  double home_z = 0;
  
  while(ros::ok && current_state.mode != "ALTCTL")
  {
    ROS_INFO("Waiting for being the ALTCTL mode!");
    ros::spinOnce();
    rate.sleep();
  }

  /*******************************************************************UDP*************************************************/
  while(ros::ok()){

  
  
  for (int i = 0; i < 4; i++)
  { 
    // if(i == 4){ // home 的位置点
    //   if (getline(fin[i], buf_home))
    //   {
    //     cout <<"No."<< i+1<<" file data : "<< buf_home <<endl;
    //     // strcpy(buf_home_v, buf_home.c_str());
    //     strncpy(buf_home_x, buf_home.c_str()+30, 7); // 赋值n个字符出来
    //     strncpy(buf_home_y, buf_home.c_str()+39, 7);
    //     strncpy(buf_home_z, buf_home.c_str()+48, 7);
    //     // cout <<"buf_home_x : "<< buf_home_x <<" buf_home_y : "<< buf_home_y<<" buf_home_z : "<< buf_home_z<<endl;
    //     home_x = strtod(buf_home_x, NULL); // 将字符串的内容转化为double类型
    //     home_y = strtod(buf_home_y, NULL);
    //     home_z = strtod(buf_home_z, NULL);
    //     cout<<"No."<< i+1<<" home data x : "<<home_x<<endl;
    //     cout<<"No."<< i+1<<" home data y : "<<home_y<<endl;
    //     cout<<"No."<< i+1<<" home data z : "<<home_z<<endl;
    //   }
    //   else
    //   {
    //     cout<<"No."<< i+1<<" File end"<<endl;
    //   }
    // }
    // else 
    // if (fin[i] >> buf[i])
    // {
      
    //   cout <<"No."<< i+1<<" file data : "<< buf[i] <<endl;
    // }
    // else
    // {
    //   cout<<"No."<< i+1<<" File end"<<endl;
    // }
    if (getline(fin[i], __buf__))
    {
      std::cout << "size : " << sizeof(__buf__) << std::endl;
      strncpy(__buf__data, __buf__.c_str(), 18); // 赋值n个字符出来
      buf[i] = strtod(__buf__data, NULL); // 将字符串的内容转化为double类型
      std::cout << "buf[" << i << "] = " << buf[i] << std::endl;
    }
  }

   
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
      UDP_buf.longitude_x = buf[1]; 
      UDP_buf.latitude_y = buf[2];
      UDP_buf.altitude_z = buf[3];
      
      UDP_buf.heading = buf[0] * 180.0 / M_PI ;
      
      // 改动
      UDP_buf.velocity = 17;

      UDP_buf.command_yaw = buf[0];

      UDP_buf.GPS_time.sec = 1600850543;
      UDP_buf.GPS_time.nsec = 1;
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
    }
    if(messagetype_UH == true){
      UPDH_buf.message_id = UH;
      UPDH_buf.uav_id = uavid;
      UPDH_buf.longitude = 112.451;
      UPDH_buf.latitude = 37.9018;
      UPDH_buf.altitude = 911.252;
      UPDH_buf.parity = (int)(UPDH_buf.message_id + UPDH_buf.uav_id + UPDH_buf.longitude  + UPDH_buf.latitude + UPDH_buf.altitude);
      printf("///////////////////////////UH//////////////////////////////////////\n");
      std::cout<<"send message_id    is:"<<UPDH_buf.message_id<<std::endl;
      std::cout<<"send uav_id   is:"<<UPDH_buf.uav_id<<std::endl;
      std::cout<<"send longitude_x is:"<<UPDH_buf.longitude<<std::endl;
      std::cout<<"send latitude_y is:"<<UPDH_buf.latitude<<std::endl;
      std::cout<<"send altitude_z is:"<<UPDH_buf.altitude<<std::endl;
      std::cout<<"send Parity is:"<<UPDH_buf.parity<<std::endl; 
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
    
    if (messagetype_UD == true)
    {
        cout<<"send UD use broadcast"<<endl;
        for (int i = 0; i < addr_serv.size(); i++){
          RunSend(sock_fd, UDP_buf, addr_serv[i], len[i]);
        }
    }
    if(messagetype_AC == true){
      for (int i = 0; i < addr_serv_p2p.size(); i++){
          cout<<"use p2p mode"<<endl;
          RunSend(sock_fd, ACK_buf, addr_serv_p2p[i], len_p2p[i]);
        }
    }
    if(messagetype_UH == true){
        cout<<"send UH use broadcast"<<endl;
        for (int i = 0; i < addr_serv.size(); i++){
          RunSend(sock_fd, UPDH_buf, addr_serv[i], len[i]);
        }
    }
    if(messagetype_QC == true){
        cout<<"send QC use broadcast"<<endl;
        RunSend(sock_fd, QC_buf, addr_serv[0], len[0]);
    }
    printf("///////////////////////////Cycle End////////////////////////////////////////\n");
    rate.sleep();
    
  }

  close(sock_fd);
  return 0;
}
#endif
