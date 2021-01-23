#include <iostream>
#include <string.h>
#include <vector>

#include <ros/ros.h>
#include "fw_msgs/processer.h"
#include "fw_msgs/QgcCommands.h"
#include "fw_msgs/uavflag.h"
#include <mavros_msgs/Mavlink.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/SetMode.h>
#include <geometry_msgs/PoseStamped.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;
#define QC 4    //qgc_commands

fw_msgs::processer processer_control;
void processer_cb(const fw_msgs::processer::ConstPtr& msg){
	processer_control = *msg;
}
mavros_msgs::Mavlink sysid_m;
void sysid_cb(const mavros_msgs::Mavlink::ConstPtr &msg){
    sysid_m = *msg;
}
mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}
geometry_msgs::PoseStamped current_localPose;
void new_localPose(const geometry_msgs::PoseStamped::ConstPtr& msg){
	current_localPose = *msg;	
}

struct Qgc_Commands{
  unsigned short int message_id;//消息类型
  unsigned short int gs_id;//地面站id，用于多个地面站区分
  unsigned short int uav_id;//指定控制的飞机
  unsigned short int vehicleNumber;   // 集群内飞机总数
  // 1: 集群 
  // 2: 自组织 
  // 3：集群和自组织  
  // 4：RTL mode
  // 5：loiter
  // 6：mission
  // 7：状态准备： 树莓派收到这个之后，开始广播 upd_HP
  // 11: offboard+集群
  // 12: offboard+自组织
  // 13: offboard+集群和自组织
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

void CreatSocket(int* length, int* sockfd, int port){
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

int Checkdata(Qgc_Commands QC_buf, int messageid){
  int parity = 0;
  if (messageid == QC){
    parity = (int)(QC_buf.message_id + QC_buf.gs_id + QC_buf.uav_id + QC_buf.vehicleNumber + QC_buf.taskType + QC_buf.plane_state + 
                            QC_buf.gapx + QC_buf.gapy + QC_buf.GPS_time);
    cout<<"receive parity is : "<<QC_buf.parity<<", calculate parity is : "<<parity<<endl;
    return parity == QC_buf.parity;
  }
  else{
    cout<<"message wrong at message id!"<<endl;
    return 0;
  }
}

void initQCbuf(Qgc_Commands* QC_buf){
  QC_buf->GPS_time = 0;
  QC_buf->gs_id = 0;
  QC_buf->uav_id = 0;
  QC_buf->vehicleNumber = 0;
  QC_buf->gapx = 0;
  QC_buf->gapy = 0;
  QC_buf->message_id = 0;
  QC_buf->parity = 0;
  QC_buf->plane_group = 0;
  QC_buf->plane_state = 0;
  QC_buf->taskType = 0;
}






int main(int argc, char **argv)
{ 
  int flag = 0;
  int initflag = 0;
  int port = 9000;
  int sock_fd, len;
  int recv_num;
  struct sockaddr_in addr_client;
  Qgc_Commands QC_buf;
  Qgc_Commands QC_buf_sv[40];
  EF exec_flag;
  unsigned short int temtreat;
  void *tempsave_v = new char[100];
  int messageid_check = 0;

  string uavName = "";
  string nodeName = "procosser";
  int uavid = -1;

  fw_msgs::QgcCommands qgccommansmsg;

  ros::Subscriber uav_sysid_sub;
  ros::Publisher uavstate_pub;

  ros::ServiceClient set_mode_client;
  ros::Subscriber state_sub;
  ros::Subscriber  uav_localPos_sub;

  fw_msgs::uavflag uavstate;
  fw_msgs::uavflag uavstate_wrong;

  mavros_msgs::SetMode set_mode;
  // rosrun processer processer "$2" 0 "$leader"
  // source _4_startFormation.sh uav0 9000

  if (argc > 1)
  {
    port = atoi(argv[1]);
    ROS_INFO("Set port to : %d", port);
  }
  if (argc > 2)
  {
    initflag = atoi(argv[2]);
    ROS_INFO("Not init with QC msg : %d", initflag);
  }
  if(argc > 3){
    uavName = argv[3];
    uavName = uavName + "/";
    nodeName = nodeName.append(uavName, 3, 1);
  }

  
  ros::init(argc, argv, nodeName);
  ros::NodeHandle nh;

  fw_msgs::processer promsg;
  ros::Publisher processer_pub = nh.advertise<fw_msgs::processer>( uavName + "processer/attitude" ,1,false);

  state_sub = nh.subscribe<mavros_msgs::State>(uavName + "msgsFromPx4/state", 10, state_cb);
  set_mode_client = nh.serviceClient<mavros_msgs::SetMode>(uavName + "mavros/set_mode");
  uav_localPos_sub = nh.subscribe<geometry_msgs::PoseStamped>(uavName + "msgsFromPx4/local_position/pose", 10, new_localPose);

  uav_sysid_sub = nh.subscribe<mavros_msgs::Mavlink>("mavlink/from", 1,sysid_cb);
  uavstate_pub = nh.advertise<fw_msgs::uavflag>(uavName + "processer/uavflag",false);
  set_mode.request.custom_mode = "AUTO.RTL";


  ros::Rate rate(20);

  CreatSocket(&len, &sock_fd, port);
  
  initQCbuf(&QC_buf);
  for (int i = 0; i < 40; i++)
  {
    initQCbuf(&QC_buf_sv[i]);
  }
  uavstate.group = -1;
  uavstate.isleader = -1;
  uavstate.leaderid = -1;

  uavstate_wrong.group = -1;
  uavstate_wrong.isleader = -1;
  uavstate_wrong.leaderid = -1;


  // while(ros::ok()){
  //   ROS_INFO("init QC_buf : %d", QC_buf_sv[12].message_id);
  //   ROS_INFO("init uavstate : %f", uavstate.group);
  // }

  // while(ros::ok() && sysid_m.sysid == 0){
  //   ROS_INFO("Waiting for the sysid...");
  //   ros::spinOnce();
  //   rate.sleep();
  // }

  

  if(argc == 4){
    const char* id_c = &uavName[3];
    uavid = atoi(id_c);
    cout<<"/////////////////////////"<<uavid<<endl;
  }
  else
  {
    uavid = sysid_m.sysid - 1;//从0开始，和消息中的编号一致
    while(ros::ok() && uavid == -1){
      uavid = sysid_m.sysid - 1;//从0开始，和消息中的编号一致
      ROS_INFO("Waiting for id...");
      ros::spinOnce();
      rate.sleep();
    }
  }
  
  
  
  while(ros::ok()){
    printf("///////////////////////////Cycle start//////////////////////////////////////\n");
    recv_num = recvfrom(sock_fd, tempsave_v, sizeof(QC_buf), MSG_DONTWAIT, (struct sockaddr *)&addr_client, (socklen_t *)&len);
    // uavid = sysid_m.sysid - 1;//从0开始，和消息中的编号一致
    if(recv_num < 0)
    {
      perror("recvfrom error:");
      ROS_ERROR("recvfrom error");
    } 
    
    memcpy(&temtreat,tempsave_v,sizeof(char)*2); 
    ROS_INFO("Message id is : %d", temtreat);
    ROS_INFO("UAV id is : %d", uavid);
    ROS_INFO("Mode flag is : %d", flag);
    ROS_INFO("port is : %d", port);


    if(temtreat == QC){//QC == 4
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
      int revflag = Checkdata(QC_buf, messageid_check);

      uavstate.myid = uavid;
      if(revflag == 1){
        cout<<"received right!"<<endl;
        QC_buf_sv[QC_buf.uav_id] = QC_buf;
        if (QC_buf.uav_id == uavid)
        {
          ROS_INFO("For this");
          uavstate.leaderid = -1;
          uavstate.group = QC_buf.plane_group;
          std::cout << "QC_buf.plane_state: " << QC_buf.plane_state << std::endl;
          // getchar();
          uavstate.isleader = QC_buf.plane_state == 1 ? 1 : 0;
          uavstate.gapx = QC_buf.gapx;
          uavstate.gapy = QC_buf.gapy;
          uavstate.controlmode = qgccommansmsg.tasktype < 10 ? 1 : 2;//1:rc
          for (int i = 0; i < 40; i++)
          {
            if( QC_buf_sv[i].plane_group == QC_buf.plane_group && QC_buf_sv[i].plane_state == 1){
              uavstate.leaderid = QC_buf_sv[i].uav_id;
              ROS_INFO("Find leader!");
            }
          }
          
        }
        else if(uavstate.group != -1 && QC_buf.plane_group == uavstate.group && QC_buf.plane_state == 1)
        {
          ROS_INFO("Get leader id");
          uavstate.leaderid = QC_buf.uav_id;
        }
        else
        {
          ROS_INFO("Not for this, no leader");
        } 
      }

      else{
        cout<<"received wrong!"<<endl;
      }

    }
    else if(temtreat == 5){
      memcpy(&exec_flag,tempsave_v,sizeof(exec_flag));
      std::cout<<"receive message_id    is:"<<exec_flag.message_id<<std::endl;
      std::cout<<"receive execflag   is:"<<exec_flag._flag<<std::endl;
      flag = exec_flag._flag;

    }
    else
    {
      std::cout<<"receive message_id    is:"<<temtreat<<std::endl;
      ROS_INFO("Not QGCommands, reject!");
    }



    if (uavstate.group == -1)
    {
      ROS_INFO("Dont get my message");
    }
    else
    {
      ROS_INFO("Get my message, isleader: %d, group is %d, id is %d", (int)uavstate.isleader, (int)uavstate.group, (int)uavstate.myid);
    }
    
    if(uavstate.leaderid == -1){
      ROS_INFO("Dont get my leader message");
    }
    else
    {
      ROS_INFO("Get my leader message, id is %d", (int)uavstate.leaderid);
    }

    promsg.execflag = flag;
    ROS_INFO("execflag is %d", (int)promsg.execflag);
    processer_pub.publish(promsg);
    
    
    
    if (uavstate.group != -1 && uavstate.leaderid != -1)
    {
      uavstate_pub.publish(uavstate);
      ROS_INFO("pub my message");
    }
    else
    {
      uavstate_pub.publish(uavstate_wrong);
      ROS_INFO("Not ready, pub stop flag");
    }
    std::cout << "processor : uavstate.isleader = " << uavstate.isleader << std::endl;
    // getchar();
    /*
    if(promsg.execflag == 0 && current_state.mode != "AUTO.LOITER" && current_localPose.pose.position.z < 10.0){
      set_mode.request.custom_mode = "AUTO.LOITER";
        if(set_mode_client.call(set_mode) && set_mode.response.mode_sent){
          ROS_INFO("%s enabled", 	set_mode.request.custom_mode.c_str());
          ROS_INFO("In mode : %s, atlitude is : %f, compare result : %d", current_state.mode.c_str(), 
            current_localPose.pose.position.z, "AUTO.LOITER" == current_state.mode);
            ros::spinOnce();
            rate.sleep();
        }
    }
    */
    if(current_state.mode == "ALTCTL"){
      ROS_INFO("In ALTCTL/Altitude mode, atlitude is : %f", current_localPose.pose.position.z);
      if(current_localPose.pose.position.z < -40.0){
        set_mode.request.custom_mode = "AUTO.RTL";
        while ("AUTO.RTL" != current_state.mode){
          if(set_mode_client.call(set_mode) && set_mode.response.mode_sent){
            ROS_INFO("%s enabled", 	set_mode.request.custom_mode.c_str());
            ROS_INFO("In mode : %s, atlitude is : %f, compare result : %d", current_state.mode.c_str(), 
              current_localPose.pose.position.z, "AUTO.RTL" == current_state.mode);
              ros::spinOnce();
              rate.sleep();
          }
        }
      }
    }
    
    else{
      ROS_INFO("In mode : %s, atlitude is : %f", current_state.mode.c_str(), current_localPose.pose.position.z);
      // cout<<current_state.mode<<endl;
    }


    printf("///////////////////////////Cycle End////////////////////////////////////////\n"); 
    ros::spinOnce();
    rate.sleep();

  }
  return 0;
}
