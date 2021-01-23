#include "Conmon.h"



void RunSend (int sock_fd, double* send_buf, sockaddr_in addr_serv, int len);
void RunSend (int sock_fd, double send_buf, sockaddr_in addr_serv, int len);
void RunSend (int sock_fd, Senddata send_buf, sockaddr_in addr_serv, int len);

void RunSend (int sock_fd, UDP_Data send_buf, sockaddr_in addr_serv, int len);

void RunSend (int sock_fd, ACK send_buf, sockaddr_in addr_serv, int len);

void RunSend (int sock_fd, Upd_HP send_buf, sockaddr_in addr_serv, int len);

void RunSend (int sock_fd, Qgc_Commands send_buf, sockaddr_in addr_serv, int len);

void RunSend (int sock_fd, EF send_buf, sockaddr_in addr_serv, int len);
