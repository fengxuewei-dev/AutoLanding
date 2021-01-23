#include "udpReceive.hpp"

void udpReceive::CreatSocket(int* length, int* sockfd, int port){
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
    addr_serv.sin_port = htons(port);                   //端口
    /* INADDR_ANY表示不管是哪个网卡接收到数据，只要目的端口是 SERV_PORT，就会被该应用程序接收到 */
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
int udpReceive::Checkdata(Senddata recv_buf, int id){
    int Parity = (int)(
			sizeof(dataleader.command_altitude)
			);

    if (Parity == recv_buf.Parity && id == recv_buf.id)
    {
      return 1;
    }
    else{
      return 0;
    }
    return 0;
}