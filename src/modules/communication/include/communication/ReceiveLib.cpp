#include "ReceiveLib.h"




void CreatSocket(int* length, int* sockfd, int port){
  ///////////////////////////////////////////////////////
  cout<<port<<endl;
  /* sock_fd --- socket文件描述符 创建udp套接字*/
  int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sock_fd < 0)
  {
    perror("socket");
    exit(1);
  }

  /* 将套接字和IP、端口绑定 */
  struct sockaddr_in addr_serv;
  int len;
  memset(&addr_serv, 0, sizeof(struct sockaddr_in));  //每个字节都用0填充
  addr_serv.sin_family = AF_INET;                     //使用IPV4地址
  addr_serv.sin_port = htons(port);              //端口
  /* INADDR_ANY表示不管是哪个网卡接收到数据，只要目的端口是SERV_PORT，就会被该应用程序接收到 */
  addr_serv.sin_addr.s_addr = htonl(INADDR_ANY);  //自动获取IP地址
  len = sizeof(addr_serv);

  /* 绑定socket */
  if(bind(sock_fd, (struct sockaddr *)&addr_serv, sizeof(addr_serv)) < 0)
  {
    perror("bind error:");
    exit(1);
  }
  *length = len;
  *sockfd = sock_fd;
}

int Checkdata(Senddata recv_buf, int id){
    int Parity = (int)(recv_buf.heading + recv_buf.airspeed + recv_buf.position_x + recv_buf.position_y + recv_buf.position_z + 
                  recv_buf.yaw );

    if (Parity == recv_buf.Parity && id == recv_buf.id)
    {
      std::cout<< "Parity succeed " <<endl;
      return 1;
    }
    else{
      std::cout<<"receive Parity : "<<Parity<<" calculate Parity: "<<recv_buf.Parity<<endl;
      std::cout<<"receive id     : "<<id<<" calculate id     : "<<recv_buf.id<<endl;
      std::cout<< "Parity failed " <<endl;
      return 0;
    }
}

int Checkdata(UDP_Data UDP_buf, int messageid){
  int parity = 0;
  if (messageid == UD){
    parity = (int)(UDP_buf.message_id + UDP_buf.uav_id + UDP_buf.plane_state  + UDP_buf.longitude_x + UDP_buf.latitude_y + 
                    UDP_buf.altitude_z + UDP_buf.heading + UDP_buf.velocity + UDP_buf.command_yaw + UDP_buf.GPS_time.nsec + 
                    UDP_buf.GPS_time.sec);
    cout<<"receive parity is : "<<UDP_buf.parity<<", calculate parity is : "<<parity<<endl;
    return parity == UDP_buf.parity;
  }
  else{
    cout<<"message wrong at message id!"<<endl;
    return 0;
  }
}

int Checkdata(ACK ACK_buf, int messageid){
  int parity = 0;
  if (messageid == AC){
    parity = (int)(ACK_buf.message_id + ACK_buf.uav_id + ACK_buf.judge + ACK_buf.GPS_time.nsec + ACK_buf.GPS_time.sec);
    cout<<"receive parity is : "<<ACK_buf.parity<<", calculate parity is : "<<parity<<endl;
    return parity == ACK_buf.parity;
  }
  else{
    cout<<"message wrong at message id!"<<endl;
    return 0;
  }
}

int Checkdata(Qgc_Commands QC_buf, int messageid){
  int parity = 0;
  if (messageid == QC){
    parity = (int)(QC_buf.message_id + QC_buf.gs_id + QC_buf.uav_id + QC_buf.vehicleNumber + QC_buf.taskType + QC_buf.plane_state + 
                            QC_buf.gapx + QC_buf.gapx + QC_buf.GPS_time);
    cout<<"receive parity is : "<<QC_buf.parity<<", calculate parity is : "<<parity<<endl;
    return parity == QC_buf.parity;
  }
  else{
    cout<<"message wrong at message id!"<<endl;
    return 0;
  }
}

int Checkdata(Upd_HP UPDH_buf, int messageid){
  int parity = 0;
  if (messageid == UH){
    parity = (int)(UPDH_buf.message_id + UPDH_buf.uav_id + UPDH_buf.longitude  + UPDH_buf.latitude + UPDH_buf.altitude);
    cout<<"receive parity is : "<<UPDH_buf.parity<<", calculate parity is : "<<parity<<endl;
    return parity == UPDH_buf.parity;
  }
  else{
    cout<<"message wrong at message id!"<<endl;
    return 0;
  }
}