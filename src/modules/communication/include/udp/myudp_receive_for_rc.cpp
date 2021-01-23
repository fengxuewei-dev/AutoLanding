#include "myudp_receive_for_rc.h"


void CreatSocket(int* length, int* sockfd){
  ///////////////////////////////////////////////////////
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
  addr_serv.sin_port = htons(SERV_PORT);              //端口
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
    int Parity = (int)(recv_buf.globalposition_latitude + recv_buf.globalposition_longitude + recv_buf.globalposition_altitude
                            + recv_buf.vecolity_x + recv_buf.vecolity_y + recv_buf.vecolity_z + recv_buf.heading);

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