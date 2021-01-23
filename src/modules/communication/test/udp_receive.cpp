#include "../include/udp/myudp_receive_for_rc.h"

int main(int argc, char **argv)
 {
  ros::init(argc, argv, "myudp_receive");
  ros::NodeHandle nh;
	// 设置 Rate
	ros::Rate loop_rate(20);

  int sock_fd, len;
  CreatSocket(&len, &sock_fd);

  int recv_num;
  Senddata recv_buf;

  int Parity = 0;
  int id = 1;

  struct sockaddr_in addr_client;

  while(ros::ok())
  {
    // ros::spinOnce();
    printf("server wait:\n");

    recv_num = recvfrom(sock_fd, &recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)&addr_client, (socklen_t *)&len);

    Parity = (int)(recv_buf.globalposition_latitude + recv_buf.globalposition_longitude + recv_buf.globalposition_altitude
                            + recv_buf.vecolity_x + recv_buf.vecolity_y + recv_buf.vecolity_z + recv_buf.heading);

    int flag = Checkdata(recv_buf, id);
    std::cout<<"////////////////"<<flag<<endl;

    ++id;

    if(recv_num < 0)
    {
      perror("recvfrom error:");
      exit(1);
    }
    
    std::cout<< "server receive longitude  : " << recv_buf.globalposition_longitude <<endl;
    std::cout<< "server receive latitude   : " << recv_buf.globalposition_latitude <<endl;
    std::cout<< "server receive altitude   : " << recv_buf.globalposition_altitude <<endl;
    std::cout<< "server receive vecolity_x : " << recv_buf.vecolity_x <<endl;
    std::cout<< "server receive vecolity_y : " << recv_buf.vecolity_y <<endl;
    std::cout<< "server receive vecolity_z : " << recv_buf.vecolity_z <<endl;
    std::cout<< "server receive heading    : " << recv_buf.heading <<endl;
    
    loop_rate.sleep();
  }

  close(sock_fd);

  return 0;
}