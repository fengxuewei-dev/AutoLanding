#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#include <cstdlib>
#include <cmath>
#include <inttypes.h>
#include <fstream>
#include <signal.h>
#include <time.h>
#include <sys/time.h>

#include <iostream>
#include <string.h>
#include <vector>

#include <ros/ros.h>
using namespace std;

#define DEFAULT_PORT 8002
#define DEFAULT_IP_ADDRESS  "127.0.0.1"

#define LOCALUAVID 0

#define UD 1    //UDP_Data
#define AC 2    //ack
#define UH 3    //upd_HP update homepoint
#define QC 4    //qgc_commands

struct Senddata {
  int id = 0;
  double yaw = 0.0;
  double position_x = 0.0;
  double position_y = 0.0;
  double position_z = 0.0;
  double heading = 0.0;
  double airspeed = 0.0;
  int Parity = 0;
};

// 无人机之间-广播-发送用于自组织和集群的消息
struct UDP_Data{
  unsigned short int message_id;//消息类型
  unsigned short int uav_id;//本机的总体编号
  unsigned short int plane_state;//本机的组内类型（主/从）
  unsigned short int plane_group;//本机的组号
  long int number{0};
  double longitude_x;
  double latitude_y;
  double altitude_z;  
  double heading;//本机的当前航向，主要用于
  double velocity;        // 掌机实时空速
  double command_yaw;//发送的主机计算后的yaw
  ros::Time GPS_time;//发送的GPS时间，unsign int
  int parity;              // 校验位
};



// 无人机之间-广播-发送自己的home点信息
struct Upd_HP{
  unsigned short int message_id;//消息类型
  unsigned short int uav_id;//本机的总体编号
  double longitude;
  double latitude;
  double altitude;  
  int parity;           
};

// 无人机到地面站-点对点-给地面站的ack
struct ACK{
  unsigned short int message_id;//消息类型
  unsigned short int uav_id;//本机的总体编号
  ros::Time GPS_time;//发送的GPS时间，unsign int
  bool judge;
  int parity;
};

// 地面站到无人机-广播-地面站给无人机的控制指令
struct Qgc_Commands{
  unsigned short int message_id;//消息类型
  unsigned short int gs_id;//地面站id，用于多个地面站区分
  unsigned short int uav_id;//指定控制的飞机
  unsigned short int vehicleNumber;   // 集群内飞机总数
  // 0: 集群 
  // 1: 自组织 
  // 2：集群和自组织  
  // 3：RTL mode
  // 4：loiter
  // 5：mission
  // 6：状态准备： 树莓派收到这个之后，开始广播 upd_HP
  int taskType; 
  short int plane_state;//设置组号+组内的还是状态 全0为自组织
  short int plane_group;//设置组号+组内的还是状态 全0为自组织
  short int gapx; 
  short int gapy; 
  double GPS_time;//发送的GPS时间，unsign int
  int parity;              // 校验位
};

struct EF{
  unsigned short int message_id; 
  int _flag;           
};
