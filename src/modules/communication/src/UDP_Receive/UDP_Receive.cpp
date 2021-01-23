#include "../../include/communication/ReceiveLib.h"
#include "../../../../lib/logger/LoggerUdp.hpp"

#include "fw_msgs/ACK.h"
#include "fw_msgs/UDPData.h"
#include "fw_msgs/UpdHP.h"
#include "fw_msgs/QgcCommands.h"
#include "fw_msgs/ACKflag.h"
#include "../../../../lib/Macro.hpp"


fw_msgs::UDPData current;
void new_WayPointList(const fw_msgs::UDPData::ConstPtr& msg){
	current = *msg;
	ROS_INFO("NEW WAYPOINT LIST");
}

// rosrun communication UDP_Receive 8002
int main(int argc, char **argv)
 {

  std::string uavName = "";
  std::string nodeName = "myudp_receive";

  int sock_fd, len;
  int port = 8002; // 默认端口为8002

  /* nodeName & uavName & port */
  if(argc == 3){
    uavName = argv[1];
    uavName = uavName + "/";
    port = atoi(argv[2]);
    nodeName = nodeName.append(uavName, 3, 1);
  }
  int uavid = LOCALUAVID;
  if(argc >= 2){
    port = atoi(argv[1]);
    cout<<"use port "<<port<<endl;
  }
  
  if(argc >= 3){
    uavName = argv[2];
    uavName = uavName + "/";
    nodeName = nodeName.append(uavName, 3, 1);
    char c_id = uavName[3];
    uavid = atoi(&c_id);
    cout<<"use sitl, node name is "<<nodeName;
  }
  cout<<", uav id is : "<<uavid<<endl;
  
 	
  ros::init(argc, argv, nodeName);

  loggerReceive LOGGERRECEIVE("receive", uavName);
  
  fw_msgs::ACK ackmsg;
  fw_msgs::UDPData udpdatamsg;
  fw_msgs::UpdHP homedatamsg;
  fw_msgs::QgcCommands qgccommansmsg;
  fw_msgs::ACKflag ACKflag;

  ros::NodeHandle nh;
	// 设置 Rate
	ros::Rate rate(UDP_COMMUNICATION_RECEIVE);
  
  ros::Publisher ACK_pub[40];
  ros::Publisher UpdHP_pub[40];
  ros::Publisher UDPData_pub[40];
  ros::Publisher QgcCommands_pub[40];
 


  for(int i = 0; i <40; i++){ 
    string s_i = to_string(i);
    ACK_pub[i]              = nh.advertise<fw_msgs::ACK>(uavName + "communication/ACK" + s_i,10,false);
    UpdHP_pub[i]            = nh.advertise<fw_msgs::UpdHP>(uavName + "communication/UpdHP" + s_i,10,false);
    UDPData_pub[i]          = nh.advertise<fw_msgs::UDPData>(uavName + "communication/UDPData" + s_i,10,false);
    QgcCommands_pub[i]      = nh.advertise<fw_msgs::QgcCommands>(uavName + "communication/QgcCommands" + s_i,10,false);
  }
  
  
  
  CreatSocket(&len, &sock_fd, port);

  int recv_num;
  
  UDP_Data UDP_buf;
  Upd_HP UPDH_buf;
  ACK ACK_buf;
  Qgc_Commands QC_buf;

  char tempsave[72];
  unsigned short int temtreat;
  void *tempsave_v = new char[100];
  int messageid_check = 0;

  struct sockaddr_in addr_client;

  while(ros::ok())
  {
    // ros::spinOnce();
    printf("///////////////////////////Cycle start//////////////////////////////////////\n");
    printf("server wait:\n");

    // recv_num = recvfrom(sock_fd, &UDP_buf, sizeof(recv_buf), MSG_DONTWAIT, (struct sockaddr *)&addr_client, (socklen_t *)&len);
    recv_num = recvfrom(sock_fd, tempsave_v, sizeof(UDP_buf), MSG_DONTWAIT, (struct sockaddr *)&addr_client, (socklen_t *)&len);
    
    memcpy(&temtreat,tempsave_v,sizeof(char)*2); 
    cout<<"message id is : "<<temtreat<<endl;

    

    if(temtreat == UD){
      messageid_check = UD;
      memcpy(&UDP_buf,tempsave_v,sizeof(UDP_buf));
      udpdatamsg.messageid = UDP_buf.message_id;
      udpdatamsg.uavid = UDP_buf.uav_id;
      udpdatamsg.number = UDP_buf.number;
      udpdatamsg.plane_state = UDP_buf.plane_state;
      udpdatamsg.plane_group = UDP_buf.plane_group;
      udpdatamsg.longitudex = UDP_buf.longitude_x;
      udpdatamsg.latitudey = UDP_buf.latitude_y;
      udpdatamsg.altitudez = UDP_buf.altitude_z;
      udpdatamsg.heading = UDP_buf.heading;
      udpdatamsg.velocity = UDP_buf.velocity;
      udpdatamsg.commandyaw = UDP_buf.command_yaw;
      udpdatamsg.GPStime = UDP_buf.GPS_time;
      printf("///////////////////////////UD//////////////////////////////////////\n");
      cout<<"GPS time is : "<<UDP_buf.GPS_time.sec<<"."<<UDP_buf.GPS_time.nsec<<", size is : "<<sizeof(UDP_buf.GPS_time)<<endl;
      std::cout<<"receive message_id    is:"<<UDP_buf.message_id<<std::endl;
      std::cout<<"receive number    is:"<<UDP_buf.number<<std::endl;
      std::cout<<"receive uav_id   is:"<<UDP_buf.uav_id<<std::endl;
      std::cout<<"receive plane_state is:"<<UDP_buf.plane_state<<std::endl;
      std::cout<<"receive plane_group is:"<<UDP_buf.plane_group<<std::endl;
      std::cout<<"receive longitude_x is:"<<UDP_buf.longitude_x<<std::endl;
      std::cout<<"receive latitude_y is:"<<UDP_buf.latitude_y<<std::endl;
      std::cout<<"receive altitude_z is:"<<UDP_buf.altitude_z<<std::endl;
      std::cout<<"receive heading        is:"<<UDP_buf.heading<<std::endl;
      std::cout<<"receive velocity    is:"<<UDP_buf.velocity<<std::endl;
      std::cout<<"receive command_yaw   is:"<<UDP_buf.command_yaw<<std::endl;
      std::cout<<"receive Parity is:"<<UDP_buf.parity<<std::endl;

      cout<<"now is at message : "<<UDP_buf.message_id<<endl;
      int flag = Checkdata(UDP_buf, messageid_check);
      if(flag == 1){
        UDPData_pub[udpdatamsg.uavid].publish(udpdatamsg);//UAVid从1开始
        cout<<"received right!"<<endl;
      }
      else{
        cout<<"received wrong!"<<endl;
      }
      LOGGERRECEIVE.UdpData_altitude_z.logPrint(UDP_buf.altitude_z);
      LOGGERRECEIVE.UdpData_latitude_y.logPrint(UDP_buf.latitude_y);
      LOGGERRECEIVE.UdpData_longitude_x.logPrint(UDP_buf.longitude_x);


      LOGGERRECEIVE.UdpData_command_yaw.logPrint(UDP_buf.command_yaw);
      LOGGERRECEIVE.UdpData_heading.logPrint(UDP_buf.heading);
      LOGGERRECEIVE.UdpData_GPS_time_sec.logPrint(UDP_buf.GPS_time.sec);
      LOGGERRECEIVE.UdpData_GPS_time_nsec.logPrint(UDP_buf.message_id);
      LOGGERRECEIVE.UdpData_number.logPrint(UDP_buf.number);
      LOGGERRECEIVE.UdpData_parity.logPrint(UDP_buf.parity);
      LOGGERRECEIVE.UdpData_plane_group.logPrint(UDP_buf.plane_group);
      LOGGERRECEIVE.UdpData_plane_state.logPrint(UDP_buf.plane_state);
      LOGGERRECEIVE.UdpData_uav_id.logPrint(UDP_buf.uav_id);
      LOGGERRECEIVE.UdpData_velocity.logPrint(UDP_buf.velocity);
    }

    else if(temtreat == AC){
      messageid_check = AC;
      memcpy(&ACK_buf,tempsave_v,sizeof(ACK_buf));
      ackmsg.messageid = ACK_buf.message_id;
      ackmsg.uavid = ACK_buf.uav_id;
      ackmsg.judge = ACK_buf.judge;
      ackmsg.GPStime = ACK_buf.GPS_time;
      printf("///////////////////////////AC//////////////////////////////////////\n");
      cout<<"GPS time is : "<<ACK_buf.GPS_time.sec<<"."<<ACK_buf.GPS_time.nsec<<", size is : "<<sizeof(ACK_buf.GPS_time)<<endl;
      std::cout<<"receive message_id    is:"<<ACK_buf.message_id<<std::endl;
      std::cout<<"receive uav_id   is:"<<ACK_buf.uav_id<<std::endl;
      std::cout<<"receive plane_state is:"<<ACK_buf.judge<<std::endl;
      std::cout<<"receive Parity is:"<<ACK_buf.parity<<std::endl;

      cout<<"now is at message : "<<ACK_buf.message_id<<endl;
      int flag = Checkdata(ACK_buf, messageid_check);
      if(flag == 1){
        ACK_pub[ACK_buf.uav_id].publish(ackmsg);//UAVid从1开始
        cout<<"received right!"<<endl;
      }
      else{
        cout<<"received wrong!"<<endl;
      }

      LOGGERRECEIVE.ACK_judge.logPrint(ACK_buf.judge);
      LOGGERRECEIVE.ACK_message_id.logPrint(ACK_buf.message_id);
      LOGGERRECEIVE.ACK_uav_id.logPrint(ACK_buf.uav_id);
      LOGGERRECEIVE.ACK_parity.logPrint(ACK_buf.parity);
      LOGGERRECEIVE.ACK_Gps_time_sec.logPrint(ACK_buf.GPS_time.sec);
      LOGGERRECEIVE.ACK_Gps_time_nsec.logPrint(ACK_buf.GPS_time.nsec);
    }
    else if(temtreat == UH){
      messageid_check = UH;
      memcpy(&UPDH_buf,tempsave_v,sizeof(UPDH_buf));
      homedatamsg.messageid = UPDH_buf.message_id;
      homedatamsg.uavid = UPDH_buf.uav_id;
      homedatamsg.longitude = UPDH_buf.longitude;
      homedatamsg.latitude = UPDH_buf.latitude;
      homedatamsg.altitude = UPDH_buf.altitude;
      // printf("///////////////////////////UH//////////////////////////////////////\n");
      // std::cout<<"receive message_id    is:"<<UPDH_buf.message_id<<std::endl;
      // std::cout<<"receive uav_id   is:"<<UPDH_buf.uav_id<<std::endl;
      // std::cout<<"receive longitude_x is:"<<UPDH_buf.longitude<<std::endl;
      // std::cout<<"receive latitude_y is:"<<UPDH_buf.latitude<<std::endl;
      // std::cout<<"receive altitude_z is:"<<UPDH_buf.altitude<<std::endl;
      // std::cout<<"receive Parity is:"<<UPDH_buf.parity<<std::endl; 


      std::cout<<"now is at message : "<<UPDH_buf.message_id<<std::endl;
      int flag = Checkdata(UPDH_buf, messageid_check);
      if(flag == 1){
        UpdHP_pub[UPDH_buf.uav_id].publish(homedatamsg);//UAVid从1开始
        cout<<"received right!"<<endl;
      }
      else{
        cout<<"received wrong!"<<endl;
      }

      LOGGERRECEIVE.Home_message_id.logPrint(UPDH_buf.message_id);
      LOGGERRECEIVE.Home_uav_id.logPrint(UPDH_buf.uav_id);
      LOGGERRECEIVE.Home_longitude.logPrint(UPDH_buf.longitude);
      LOGGERRECEIVE.Home_latitude.logPrint(UPDH_buf.latitude);
      LOGGERRECEIVE.Home_altitude.logPrint(UPDH_buf.altitude);
      LOGGERRECEIVE.Home_parity.logPrint(UPDH_buf.parity);
    }
    else if(temtreat == QC){
      messageid_check = QC;
      memcpy(&QC_buf,tempsave_v,sizeof(QC_buf));
      qgccommansmsg.messageid = QC_buf.message_id;
      qgccommansmsg.uavid = QC_buf.uav_id;
      qgccommansmsg.gsid = QC_buf.gs_id;
      qgccommansmsg.tasktype = QC_buf.taskType;
      qgccommansmsg.plane_state = QC_buf.plane_state;
      qgccommansmsg.plane_group = QC_buf.plane_group;
      qgccommansmsg.gapx = QC_buf.gapx;
      qgccommansmsg.gapy = QC_buf.gapy;
      qgccommansmsg.GPStime = QC_buf.GPS_time;
      printf("///////////////////////////QC//////////////////////////////////////\n");
      cout<<"GPS time is : "<<QC_buf.GPS_time<<endl;
      std::cout<<"receive message_id    is:"<<QC_buf.message_id<<std::endl;
      std::cout<<"receive uav_id   is:"<<QC_buf.uav_id<<std::endl;
      std::cout<<"receive gs_id    is:"<<QC_buf.gs_id<<std::endl;
      std::cout<<"receive vehicleNumber   is:"<<QC_buf.vehicleNumber<<std::endl;
      std::cout<<"receive taskType    is:"<<QC_buf.taskType<<std::endl;
      std::cout<<"receive plane_state   is:"<<QC_buf.plane_state<<std::endl;
      std::cout<<"receive plane_group   is:"<<QC_buf.plane_group<<std::endl;
      std::cout<<"receive gapx    is:"<<QC_buf.gapx<<std::endl;
      std::cout<<"receive gapy    is:"<<QC_buf.gapy<<std::endl;
      std::cout<<"receive Parity is:"<<QC_buf.parity<<std::endl; 

      cout<<"now is at message : "<<QC_buf.message_id<<endl;
      int flag = Checkdata(QC_buf, messageid_check);
      if(flag == 1 && qgccommansmsg.uavid == uavid){
        QgcCommands_pub[UPDH_buf.uav_id].publish(qgccommansmsg);//UAVid从1开始
        cout<<"received right!"<<endl;
      }
      else if(qgccommansmsg.uavid != uavid){
        cout<<"not command for this!"<<endl;
      }
      else{
        cout<<"received wrong!"<<endl;
      }
      LOGGERRECEIVE.QGC_Command_gapx.logPrint(QC_buf.gapx);
      LOGGERRECEIVE.QGC_Command_gapy.logPrint(QC_buf.gapy);
      LOGGERRECEIVE.QGC_Command_GPS_time.logPrint(QC_buf.GPS_time);
      LOGGERRECEIVE.QGC_Command_gs_id.logPrint(QC_buf.gs_id);
      LOGGERRECEIVE.QGC_Command_message_id.logPrint(QC_buf.message_id);
      LOGGERRECEIVE.QGC_Command_plane_group.logPrint(QC_buf.plane_group);
      LOGGERRECEIVE.QGC_Command_taskType.logPrint(QC_buf.taskType);
      LOGGERRECEIVE.QGC_Command_uav_id.logPrint(QC_buf.uav_id);
      LOGGERRECEIVE.QGC_Command_parity.logPrint(QC_buf.parity);
      LOGGERRECEIVE.QGC_Command_plane_state.logPrint(QC_buf.plane_state);
    }

    if(recv_num < 0)
    {
      perror("recvfrom error:");
    } 
    printf("///////////////////////////Cycle End////////////////////////////////////////\n");
    rate.sleep();
  }

  close(sock_fd);

  return 0;
}
