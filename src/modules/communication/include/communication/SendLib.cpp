#include "SendLib.h"

void RunSend (int sock_fd, double* send_buf, sockaddr_in addr_serv, int len){
  int send_num = 0;
  
  //printf("client send: %s\n", send_buf);
  std::cout<<"client send:"<<send_buf[1]<<std::endl;
  send_num = sendto(sock_fd, send_buf, 2*sizeof(double), 0, (struct sockaddr *)&addr_serv, len);
  if(send_num < 0)
  {
     perror("sendto error:");
     //exit(1);
  }
}

void RunSend (int sock_fd, double send_buf, sockaddr_in addr_serv, int len){
  int send_num = 0;
  
  //printf("client send: %s\n", send_buf);
  std::cout<<"client send:"<<send_buf<<std::endl;
  send_num = sendto(sock_fd, &send_buf, sizeof(send_buf), 0, (struct sockaddr *)&addr_serv, len);
  if(send_num < 0)
  {
     perror("sendto error:");
     //exit(1);
  }
}
void RunSend (int sock_fd, Senddata send_buf, sockaddr_in addr_serv, int len){
  int send_num = 0;
  
  //printf("client send: %s\n", send_buf);
  //std::cout<<"client send:"<<send_buf.localposition_x<<std::endl;
  send_num = sendto(sock_fd, &send_buf, sizeof(send_buf), 0, (struct sockaddr *)&addr_serv, len);
  if(send_num < 0)
  {
     perror("sendto error:");
     //exit(1);
  }
}

void RunSend (int sock_fd, UDP_Data send_buf, sockaddr_in addr_serv, int len){
  int send_num = 0;
  
  //printf("client send: %s\n", send_buf);
  //std::cout<<"client send:"<<send_buf.localposition_x<<std::endl;
  send_num = sendto(sock_fd, &send_buf, sizeof(send_buf), 0, (struct sockaddr *)&addr_serv, len);
  if(send_num < 0)
  {
     perror("sendto error:");
     //exit(1);
  }
}

void RunSend (int sock_fd, ACK send_buf, sockaddr_in addr_serv, int len){
  int send_num = 0;
  
  //printf("client send: %s\n", send_buf);
  //std::cout<<"client send:"<<send_buf.localposition_x<<std::endl;
  send_num = sendto(sock_fd, &send_buf, sizeof(send_buf), 0, (struct sockaddr *)&addr_serv, len);
  if(send_num < 0)
  {
     perror("sendto error:");
     //exit(1);
  }
}

void RunSend (int sock_fd, Upd_HP send_buf, sockaddr_in addr_serv, int len){
  int send_num = 0;
  
  //printf("client send: %s\n", send_buf);
  //std::cout<<"client send:"<<send_buf.localposition_x<<std::endl;
  send_num = sendto(sock_fd, &send_buf, sizeof(send_buf), 0, (struct sockaddr *)&addr_serv, len);
  if(send_num < 0)
  {
     perror("sendto error:");
     //exit(1);
  }
}

void RunSend (int sock_fd, Qgc_Commands send_buf, sockaddr_in addr_serv, int len){
  int send_num = 0;
  
  //printf("client send: %s\n", send_buf);
  //std::cout<<"client send:"<<send_buf.localposition_x<<std::endl;
  send_num = sendto(sock_fd, &send_buf, sizeof(send_buf), 0, (struct sockaddr *)&addr_serv, len);
  if(send_num < 0)
  {
     perror("sendto error:");
     //exit(1);
  }
}

void RunSend (int sock_fd, EF send_buf, sockaddr_in addr_serv, int len){
  int send_num = 0;
  send_num = sendto(sock_fd, &send_buf, sizeof(send_buf), 0, (struct sockaddr *)&addr_serv, len);
  if(send_num < 0)
  {
     perror("sendto error:");
     //exit(1);
  }
}
