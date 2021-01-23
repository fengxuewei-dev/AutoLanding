// ros程序必备头文件
#ifndef _VIR_MYUDP_HPP_
#define _VIR_MYUDP_HPP_

//////////////////////udp
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

///////////////////////ros
#include <ros/ros.h>
#include <iostream>
#include <mavros_msgs/WaypointList.h>
#include <sensor_msgs/NavSatFix.h> 
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>
#include <mavros_msgs/VFR_HUD.h>




#define DEST_PORT 8002
#define DSET_IP_ADDRESS  "127.0.0.1"


struct Senddata {
  int id = 0;
  double globalposition_latitude = 0.0;
  double globalposition_longitude = 0.0;
  double globalposition_altitude = 0.0;
  double vecolity_x = 0.0;
  double vecolity_y = 0.0;
  double vecolity_z = 0.0;
  int heading = 0.0;
  int Parity = 0;
};

void RunSend (int sock_fd, double* send_buf, sockaddr_in addr_serv, int len){
  int send_num = 0;
  
  //printf("client send: %s\n", send_buf);
  std::cout<<"client send:"<<send_buf[0]<<std::endl;
  send_num = sendto(sock_fd, send_buf, sizeof(send_buf), 0, (struct sockaddr *)&addr_serv, len);
  if(send_num < 0)
  {
     perror("sendto error:");
     exit(1);
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
     exit(1);
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
     exit(1);
  }
}

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




///////////////////////////////////////////////////////////main/////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  ros::init(argc, argv, "myudp_send");
  ros::NodeHandle nh;

  if(argc == 8){
    
    int i = 0;

    current_gpsposition.latitude = atoi(argv[++i]);
    current_gpsposition.longitude= atoi(argv[++i]);
    current_gpsposition.altitude= atoi(argv[++i]);
    current_velocity.twist.linear.x= atoi(argv[++i]);
    current_velocity.twist.linear.y= atoi(argv[++i]);
    current_velocity.twist.linear.z = atoi(argv[++i]);
    current_state.heading = atoi(argv[++i]);

  }else
    return 0;

  ros::Rate rate(20.0);

  /*******************************************************************UDP*************************************************/
   /* socket文件描述符 */
  int sock_fd;

  /* 建立udp socket */
  sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sock_fd < 0)
  {
    perror("socket");
    exit(1);
  }
    /* 设置address */
  struct sockaddr_in addr_serv;
  int len;
  memset(&addr_serv, 0, sizeof(addr_serv));
  addr_serv.sin_family = AF_INET;
  addr_serv.sin_addr.s_addr = inet_addr(DSET_IP_ADDRESS);
  addr_serv.sin_port = htons(DEST_PORT);
  len = sizeof(addr_serv);
  
  int checkcount = 0;

  Senddata send_buf;

  send_buf.globalposition_latitude = current_gpsposition.latitude;
  send_buf.globalposition_longitude = current_gpsposition.longitude;
  send_buf.globalposition_altitude = current_gpsposition.altitude;
  send_buf.vecolity_x = current_velocity.twist.linear.x;
  send_buf.vecolity_y = current_velocity.twist.linear.y;
  send_buf.vecolity_z = current_velocity.twist.linear.z;
  send_buf.heading = current_state.heading;

  /*******************************************************************UDP*************************************************/
  while(ros::ok()){
        
    ros::spinOnce();

    send_buf.id++;
    send_buf.Parity = (int)(send_buf.globalposition_latitude + send_buf.globalposition_longitude + send_buf.globalposition_altitude
                            + send_buf.vecolity_x + send_buf.vecolity_y + send_buf.vecolity_z + send_buf.heading);

    std::cout<<"send longitude  is:"<<send_buf.globalposition_longitude<<std::endl;
    std::cout<<"send latitude   is:"<<send_buf.globalposition_latitude<<std::endl;
    std::cout<<"send altitude   is:"<<send_buf.globalposition_altitude<<std::endl;
    std::cout<<"send vecolity_x is:"<<send_buf.vecolity_x<<std::endl;
    std::cout<<"send vecolity_y is:"<<send_buf.vecolity_y<<std::endl;
    std::cout<<"send vecolity_z is:"<<send_buf.vecolity_z<<std::endl;
    std::cout<<"send heading    is:"<<send_buf.heading<<std::endl;
    std::cout<<"message:"<<send_buf.id<<" Parity is:"<<send_buf.Parity<<std::endl;

    RunSend(sock_fd, send_buf, addr_serv, len);

    rate.sleep();
    }

  close(sock_fd);
  return 0;
}
#endif