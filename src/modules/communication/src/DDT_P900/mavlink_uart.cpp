/**
 * @file mavlink_uart.cpp
 *
 * @brief An example uart communication via mavlink, definition
 *
 * This process connects an external MAVLink UART device to send and receive data,
 * For multi-UAV mission plan
 *	
 * 参考自 c_uart_interface_example 修改而来
 *
 */

using namespace std;
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <string.h>
#include <inttypes.h>
#include <fstream>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
using std::string;
#include <stdlib.h>
#include <ros/ros.h>
#include <serial/serial.h>

#include <DDT_P900/mavlink_uart.h>

// ros msg
//#include <std_msgs/Int32.h>
//#include <nav_msgs/Odometry.h>
//#include <geometry_msgs/Twist.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/VFR_HUD.h>
#include <mavros_msgs/State.h>
#include "fw_msgs/Yaw.h"
#include "fw_msgs/UDPData.h"
#include "fw_msgs/QgcCommands.h"
#include<mavros_msgs/Formation_fixed_wing.h>

#define LEADER_DATA_PATH \
  "/home/fengxuewei/GitHub/uav_project_1/fixedWing_ws/src/logs/send/UdpData/"
  
#define LOG_NAME \
  "2020-11-06 19:43:38.log"
//待处理， 用于多端口接收端头处理
const uint8_t CONFIG_Header_0 = 0xEB;               //帧头0 

//串口相关
serial::Serial sp;			//创建一个serial类
//默认串口参数
int uart_name_No;	//打开"/dev/ttyUSB*"的编号
int baudrate = 57600;

uint8_t Rbuffer_rx[1024];          //串口接收Raw 
size_t  Rn;                                         //串口接收Raw 字节数
uint8_t Wbuffer_tx[1024];		//串口发送Raw 
size_t  Wn;   									//串口发送Raw 字节数

mavlink_message_t message;

Mavlink_Messages current_messages;
Time_Stamps this_timestamps;

int system_id = 1;	//设备编号
int companion_id = 2; //用作接收编号？
int write_flag = 0;
int case0r_1s=0;
int UDPdataflag = 0;
int QGCflag = 0;
int gs_id = 0;
int vehicleNumber = 0;
int taskType = 0;
int plane_state = 0;
int plane_group = 0;
int gapx = 0;
int gapy = 0;


//函数申明
// mavlink解包相关
int read_message(mavlink_message_t &message, uint8_t cp);
void handle_message(DDTReceive&);

// quit handler 退出相关
void quit_handler(int sig);
// 时间 helper
uint64_t get_time_usec();


mavros_msgs::Formation_fixed_wing Leader_DroneState;                          //Leader位置速度
mavros_msgs::Formation_fixed_wing Receive_DroneState;                         //从机接收到的Leader位置速度
int flag_leader_state_send = 0;


ros::Publisher drone_state_pub;
ros::Publisher UDPData_pub[40];

ros::Publisher qgcommands_pub;

geometry_msgs::PoseStamped current_leaderPose;
void new_leaderPose(const geometry_msgs::PoseStamped::ConstPtr& msg){
	current_leaderPose = *msg;
	cout<<"1"<<endl;
}

mavros_msgs::VFR_HUD current_Leader_state;
void newLeaderState(const mavros_msgs::VFR_HUD::ConstPtr& msg){
    current_Leader_state = *msg;
	cout<<"2"<<endl;
}

fw_msgs::Yaw current_leaderCommand;
void new_leaderCommands(const fw_msgs::Yaw::ConstPtr& msg){
	current_leaderCommand = *msg;
	flag_leader_state_send = 1;//topic更新标志
	cout<<"3"<<endl;
}



//ROS回调函数
void drone_state_cb(const mavros_msgs::Formation_fixed_wing::ConstPtr& msg)
{
    Leader_DroneState = *msg;

	flag_leader_state_send = 1;//topic更新标志
}

mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}

fw_msgs::UDPData udpdatamsg;
fw_msgs::QgcCommands ddtqgcommands;
// ------------------------------------------------------------------------------
//   Main
// ------------------------------------------------------------------------------
int main(int argc, char **argv)
{	
	std::string nodeName = "mavlink_mission";
	int uavid = 0;
	std::string uavName = "";
	if(argc >= 2){
		char* argv_1 = argv[1];
		if(argv_1[0] != 'u'){
		cout<<"single mode"<<endl;
		uavid = atoi(argv[1]);
		
		}
		else{
		std::string number = argv[1];
		nodeName = nodeName.append(number, 0, 1);
		uavName = argv[1];
		uavName = uavName + "/";
		char s_id = uavName[3];
		uavid = s_id - '0';
		cout<<"use mulit sitl mode, current id is : "<<uavid<<", uav name is : "<<uavName<<endl;;
		} 
	}
	ros::init(argc, argv, nodeName);
	ros::NodeHandle nh("~");


	//【订阅】需要通过串口通信模块发送出去的信息
    // 接收leader的位置速度信息
    ros::Subscriber drone_state_sub = nh.subscribe<mavros_msgs::Formation_fixed_wing>("/mavros/fixed_wing_formation/status", 10, drone_state_cb);

    // 【发布】通过串口通信模块接收到的信息
	// 发布接收到的leader的位置速度信息
    drone_state_pub = nh.advertise<mavros_msgs::Formation_fixed_wing>("/mavros/fixed_wing_formation/status", 10);

	qgcommands_pub = nh.advertise<fw_msgs::QgcCommands>("/communication/DDT/qgcommands", 10);

	ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>(uavName + "/msgsFromPx4/state", 1, state_cb);
	// UDPData_pub = nh.advertise<fw_msgs::UDPData>(uavName + "/communication/UDPData",10,false);
	ros::Subscriber leader_state_sub = nh.subscribe<mavros_msgs::VFR_HUD>(uavName + "/msgsFromPx4/vfr_hud", 1, newLeaderState);
	ros::Subscriber leader_localPos_sub = nh.subscribe<geometry_msgs::PoseStamped>(uavName + "/msgsFromPx4/local_position/pose",1,new_leaderPose);
	ros::Subscriber leaderCommands_sub = nh.subscribe<fw_msgs::Yaw>(uavName + "/communication/yaw",1,new_leaderCommands);
	
	for(int i = 0; i <40; i++){ 
		string s_i = to_string(i);
		UDPData_pub[i]          = nh.advertise<fw_msgs::UDPData>(uavName + "/communication/UDPData" + s_i,10,false);
	}

	// 设置 Rate
	ros::Rate loop_rate(2);

	//Responds to early exits signaled with Ctrl-C. 
	signal(SIGINT, quit_handler);

	// ----------------------------------------------------------------------
	//   读取param参数
	// ----------------------------------------------------------------------
	nh.param<int>("baudrate", baudrate, 57600);
	nh.param<int>("system_id", system_id, 1);
	nh.param<int>("uart_name_No", uart_name_No, 0);
    nh.param<int>("case0r_1s", case0r_1s, 0);

	nh.param<int>("UDPdataflag", UDPdataflag, 0);
	nh.param<int>("QGCflag", QGCflag, 0);
	nh.param<int>("gs_id", gs_id, 0);
	nh.param<int>("vehicleNumber", vehicleNumber, 0);
	nh.param<int>("taskType", taskType, 0);
	nh.param<int>("plane_state", plane_state, 0);
	nh.param<int>("plane_group", plane_group, 0);
	nh.param<int>("gapx", gapx, 0);
	nh.param<int>("gapy", gapy, 0);

	string serial_port_adr("/dev/ttyUSB" + to_string(uart_name_No));

	cout << "baudrate: " << baudrate << endl;
	cout << "system_id: " << system_id << endl;
    cout << "0read_1send: " << case0r_1s << endl;
	cout << "uart_name_No: " << uart_name_No << endl;
	cout << "serial_port_adr: " << serial_port_adr.c_str() << endl;

	cout << "UDPdataflag " << UDPdataflag << endl;
	cout << "QGCflag " << QGCflag << endl;
	cout << "gs_id " << gs_id << endl;
	cout << "vehicleNumber " << vehicleNumber << endl;
	cout << "taskType " << taskType << endl;
	cout << "plane_state " << plane_state	 << endl;
	cout << "plane_group " << plane_group << endl;
	cout << "gapx " << gapx << endl;
	cout << "gapy " << gapy << endl;

	DDTReceive	_DDTLOGGER_RECEIVE("DDT/Receive", uavName);

	// ----------------------------------------------------------------------
	//   串口serial设置&开启
	// ----------------------------------------------------------------------
	serial::Timeout to = serial::Timeout::simpleTimeout(10); //创建timeout
	sp.setPort(serial_port_adr.c_str());					 	//设置要打开的串口名称
	//sp.setPort("/dev/ttyUSB0");
	sp.setBaudrate(baudrate);									 	//设置串口通信的波特率
	sp.setTimeout(to);										 				//串口设置timeout
	//打开串口
	try
	{
		sp.open();
	}
	catch (serial::IOException &e)
	{
		ROS_ERROR_STREAM("Unable to open port.");
		return -1;
	}
	//判断串口是否打开成功
	if (sp.isOpen())
	{
		ROS_INFO_STREAM("/dev/ttyUSB"+to_string(uart_name_No)+ " is Opened.");
	}
	else
	{
		ROS_INFO_STREAM("/dev/ttyUSB"+to_string(uart_name_No)+ " Open Failed!.");
		return -1;
	}

	//初始化
	int i = 0;
	flag_leader_state_send = 0;

	std::vector<string> txtname(11);
	double buf[10];
	ifstream fin[10];

	// 打开数据文件 ======================================================================
	if(case0r_1s){	
		txtname[0] = std::string(LEADER_DATA_PATH) + "command_yaw/" + std::string(LOG_NAME);
		txtname[1] = std::string(LEADER_DATA_PATH) + "number/" + std::string(LOG_NAME);
		txtname[2] = std::string(LEADER_DATA_PATH) + "GPS_time_sec/" + std::string(LOG_NAME);
		txtname[3] = std::string(LEADER_DATA_PATH) + "heading/" + std::string(LOG_NAME);
		txtname[4] = std::string(LEADER_DATA_PATH) + "GPS_time_nsec/" + std::string(LOG_NAME);
		txtname[5] = std::string(LEADER_DATA_PATH) + "parity/" + std::string(LOG_NAME);
		txtname[6] = std::string(LEADER_DATA_PATH) + "longitude_x/" + std::string(LOG_NAME);
		txtname[7] = std::string(LEADER_DATA_PATH) + "latitude_y/" + std::string(LOG_NAME);
		txtname[8] = std::string(LEADER_DATA_PATH) + "altitude_z/" + std::string(LOG_NAME);
		txtname[9] = std::string(LEADER_DATA_PATH) + "velocity/" + std::string(LOG_NAME);
		for (int i = 0; i < 10; i++)
		{
			fin[i].open(txtname[i]);
			if (fin[i].peek() == EOF)
			{
			cout <<"No."<< i+1<< " file is empty."<<endl;
			return 0;
			}
		}
	}
	
	string __buf__ = "";
	char __buf__data[20];

	string buf_home = "";
	char buf_home_x[20];
	char buf_home_y[20];
	char buf_home_z[20];
	double home_x = 0;
	double home_y = 0;
	double home_z = 0;


	// while(ros::ok && current_state.mode != "ALTCTL")
	// {
	//	ROS_INFO("Waiting for being the ALTCTL mode!");
	//	ros::spinOnce();
	//	loop_rate.sleep();
	// }
	// 打开数据文件 ======================================================================



	while (	ros::ok()	)
	{	
		ros::spinOnce();

                switch (case0r_1s)
		{
                        //case1 发送		//case0 接收
			case 0:
				// ----------------------------------------------------------------------
				//   进行串口字节读取，并解包 
				// ----------------------------------------------------------------------
				Rn = sp.available();	//获取缓冲区内的字节数
				// 如果有待读取字节数
				if (Rn != 0)
				{
					Rn = sp.read(Rbuffer_rx, Rn); //读出数据

					// 打印读取的字节到屏幕上
					cout << endl << endl <<"Receive " << (int)Rn << " byte: " << endl;
					for (int i = 0; i < Rn; i++)
					{
						cout << hex << (Rbuffer_rx[i] & 0xff) << " ";
					}
					cout << dec << endl;
				
					// ----------------------------------------------------------------------
					//   字节解析Message
					// ----------------------------------------------------------------------
					//  通信模块配置	ATS153=1 Address Tag 启用后， 可辨别来自多个模块的信息
					//	其消息格式 待确认
					/**Type 1: First 2 bytes - size (high byte first), one byte - RSSI, one reserved byte
					 *				 (0x00), last six bytes - source unit address (high byte first).
					 */
					bool success;	//mavlink 信息正确标志
					for (int i = 0; i < Rn; i++)
					{
						success = read_message(message, Rbuffer_rx[i] & 0xff);
						if (success)
						{		
							cout<<"Receive a complete Mavlink message"  << endl;
							handle_message(_DDTLOGGER_RECEIVE);	
						}
					}

					if (!success)
					{
						//cout<<"Not a complete"  << endl;
					}

				}// end 如果有接收到if (Rn != 0)

			break;			//end case 0:

			case 1:

				// ----------------------------------------------------------------------
				//   进行串口字节发送，并解包 
				// ----------------------------------------------------------------------
				/**
				 	Wbuffer_tx[0] = CONFIG_Header_0;     //配置帧头 0xEB
			 		Wbuffer_tx[1] = 0x99;           
				*/

					i = i+1;//心跳包计数

					mavlink_self_fax_formation_t sp_mavlink;
					mavlink_heartbeat_t hb_mavlink;
					mavlink_message_t message_to_send;//需要发送的mavlink message

					if ( flag_leader_state_send)	//rostopic 有更新
					{
    				// --------------------------------------------------------------------------
					//   PACK PAYLOAD
					sp_mavlink.ned_vel_x       = Leader_DroneState.ned_vel_x;
					sp_mavlink.ned_vel_y       = Leader_DroneState.ned_vel_y;
					sp_mavlink.ned_vel_z       = Leader_DroneState.ned_vel_z;
					sp_mavlink.latitude       = Leader_DroneState.latitude;
					sp_mavlink.altitude       = Leader_DroneState.altitude;
					sp_mavlink.longtitude  = Leader_DroneState.longtitude;

					flag_leader_state_send = 0;	//topic更新标志置 0 

				 	// --------------------------------------------------------------------------
					//   ENCODE
					mavlink_msg_self_fax_formation_encode(system_id, companion_id, &message_to_send, &sp_mavlink);
					write_flag = 1;
					}
					else if ( (i%20) == 19) //1s一个心跳包
					{
						// --------------------------------------------------------------------------
						//   PACK PAYLOAD
						hb_mavlink.custom_mode = 66;/*<  A bitfield for use for autopilot-specific flags*/
						hb_mavlink.type = MAV_TYPE_FIXED_WING;/*<  Type of the MAV (quadrotor, helicopter, etc.)*/
						hb_mavlink.autopilot = MAV_AUTOPILOT_PX4; /*<  Autopilot type / class.*/
						hb_mavlink.base_mode = MAV_MODE_FLAG_GUIDED_ENABLED;/*<  System mode bitmap.*/
						hb_mavlink.system_status = MAV_STATE_ACTIVE;/*<  System status flag.*/
					
						// --------------------------------------------------------------------------
						//   ENCODE
						mavlink_msg_heartbeat_encode(system_id, companion_id, &message_to_send, &hb_mavlink);
						write_flag = 1;

						i = 0;
					}
					
				// --------------------------------------------------------------------------
				//   WRITE
				// Translate message to buffer
				if (write_flag)
				{
					unsigned len;
					len  = mavlink_msg_to_send_buffer((uint8_t*)Wbuffer_tx, &message_to_send);
					// Write buffer to serial port
					sp.write(Wbuffer_tx, len);

					// 打印到屏幕上
					cout<<"Send " << (int)len << " byte: " << endl;
					for (int i = 0; i < len; i++)
					{
						cout << dec << hex << (Wbuffer_tx[i] & 0xff) << " ";
					}
					cout << endl << endl;

					write_flag = 0;
				}
			break;			//end case 1

			case 2:

				// ----------------------------------------------------------------------
				//   进行串口字节发送，并解包 
				// ----------------------------------------------------------------------
				/**
				 	Wbuffer_tx[0] = CONFIG_Header_0;     //配置帧头 0xEB
			 		Wbuffer_tx[1] = 0x99;           
				*/
				
				// 获取数据 =======================================
				for (int i = 0; i < 10; i++)
				{ 
					if (getline(fin[i], __buf__))
					{
						std::cout << "size : " << sizeof(__buf__) << std::endl;
						strncpy(__buf__data, __buf__.c_str()+14, 18); // 赋值n个字符出来
						buf[i] = strtod(__buf__data, NULL); // 将字符串的内容转化为double类型
						std::cout << "buf[" << i << "] = " << buf[i] << std::endl;
					}
				}
				// 获取数据 =======================================


				i = i+1;//心跳包计数

				mavlink_self_fax_formation_rc_t sp_rc_mavlink;
				mavlink_qgcommands_t sp_qgcommands;
				mavlink_heartbeat_t hb_rc_mavlink;
				mavlink_message_t message_rc_to_send;//需要发送的mavlink message
				mavlink_message_t message_qgcommands;
				// cout<<"/////////////flag is "<<flag_leader_state_send<<endl;
				if (UDPdataflag)	//rostopic 有更新
				{
					// --------------------------------------------------------------------------
					//   PACK PAYLOAD
					sp_rc_mavlink.message_id 		= 1;
					sp_rc_mavlink.uav_id 			= uavid;
					sp_rc_mavlink.plane_state 		= 1;
					sp_rc_mavlink.plane_group 		= 1;
					sp_rc_mavlink.command_yaw  		= buf[0];
					sp_rc_mavlink.longitude_x       = buf[6];
					sp_rc_mavlink.latitude_y       	= buf[7];
					//sp_rc_mavlink.altitude_z       	= buf[8];
					sp_rc_mavlink.altitude_z       	= 120;
					sp_rc_mavlink.heading       	= buf[3];
					sp_rc_mavlink.velocity      	= buf[9];

					cout<<"sp_rc_mavlink.message_id : "<<sp_rc_mavlink.message_id<<endl;
					cout<<"sp_rc_mavlink.uav_id : "<<sp_rc_mavlink.uav_id<<endl;
					cout<<"sp_rc_mavlink.plane_state : "<<sp_rc_mavlink.plane_state<<endl;
					cout<<"sp_rc_mavlink.plane_group : "<<sp_rc_mavlink.plane_group<<endl;
					cout<<"sp_rc_mavlink.longitude_x : "<<sp_rc_mavlink.longitude_x<<endl;
					cout<<"sp_rc_mavlink.latitude_y : "<<sp_rc_mavlink.latitude_y<<endl;
					cout<<"sp_rc_mavlink.altitude_z : "<<sp_rc_mavlink.altitude_z<<endl;
					cout<<"sp_rc_mavlink.heading : "<<sp_rc_mavlink.heading<<endl;
					cout<<"sp_rc_mavlink.velocity : "<<sp_rc_mavlink.velocity<<endl;
					cout<<"sp_rc_mavlink.command_yaw : "<<sp_rc_mavlink.command_yaw<<endl;

					flag_leader_state_send = 0;	//topic更新标志置 0 

					// --------------------------------------------------------------------------
					//   ENCODE
					mavlink_msg_self_fax_formation_rc_encode(system_id, companion_id, &message_rc_to_send, &sp_rc_mavlink);
					write_flag = 1;
				}

				if (write_flag)
				{
					unsigned len;
					if(UDPdataflag){
						len  = mavlink_msg_to_send_buffer((uint8_t*)Wbuffer_tx, &message_rc_to_send);
						// Write buffer to serial port
						sp.write(Wbuffer_tx, len);

						// 打印到屏幕上
						cout<<"Send " << (int)len << " byte: " << endl;
						for (int i = 0; i < len; i++)
						{
							cout << hex << (Wbuffer_tx[i] & 0xff) << " ";
						}
						cout << endl << endl;
					}
					write_flag = 0;
				}


				if(QGCflag){
					sp_qgcommands.message_id = 4;
					sp_qgcommands.gs_id = gs_id;
					sp_qgcommands.uav_id = uavid;
					sp_qgcommands.vehicleNumber = vehicleNumber;
					sp_qgcommands.taskType = taskType;
					sp_qgcommands.plane_state = plane_state;
					sp_qgcommands.plane_group = plane_group;
					sp_qgcommands.gapx = gapx;
					sp_qgcommands.gapy = gapy;

					cout<<"sp_qgcommands.message_id : "<<sp_qgcommands.message_id<<endl;
					cout<<"sp_qgcommands.uav_id : "<<sp_qgcommands.uav_id<<endl;
					cout<<"sp_qgcommands.gs_id : "<<sp_qgcommands.gs_id<<endl;
					cout<<"sp_qgcommands.vehicleNumber : "<<sp_qgcommands.vehicleNumber<<endl;
					cout<<"sp_qgcommands.taskType : "<<sp_qgcommands.taskType<<endl;
					cout<<"sp_qgcommands.plane_state : "<<sp_qgcommands.plane_state<<endl;
					cout<<"sp_qgcommands.plane_group : "<<sp_qgcommands.plane_group<<endl;
					cout<<"sp_qgcommands.gapx : "<<sp_qgcommands.gapx<<endl;
					cout<<"sp_qgcommands.gapy : "<<sp_qgcommands.gapy<<endl;

					mavlink_msg_qgcommands_encode(system_id, companion_id, &message_qgcommands, &sp_qgcommands);
					write_flag = 1;
				}
					
				// --------------------------------------------------------------------------
				//   WRITE
				// Translate message to buffer
				if (write_flag)
				{
					unsigned len;
					if(QGCflag){
						len  = mavlink_msg_to_send_buffer((uint8_t*)Wbuffer_tx, &message_qgcommands);
						// Write buffer to serial port
						sp.write(Wbuffer_tx, len);

						// 打印到屏幕上
						cout<<"Send " << (int)len << " byte: " << endl;
						for (int i = 0; i < len; i++)
						{
							cout << hex << (Wbuffer_tx[i] & 0xff) << " ";
						}
						cout << dec << endl << endl;
					}
					

					write_flag = 0;
				}
			break;

			default:
				cout << "Open port Error! " << endl;
				return -1;
			break;
		}

		loop_rate.sleep();

	}

	//关闭串口s
    sp.close();
	return 0;
}

// ------------------------------------------------------------------------------
//   Quit Signal Handler	This function is called when you press Ctrl-C
void quit_handler(int sig)
{
	printf("\n");
	printf("TERMINATING AT USER REQUEST\n");
	printf("\n");
	
	sp.close();
	// end program here
	exit(0);
}


int read_message(mavlink_message_t &message, uint8_t cp)
{
	mavlink_status_t status;
	uint8_t          msgReceived = false;

	// --------------------------------------------------------------------------
	//   PARSE MESSAGE
		msgReceived = mavlink_parse_char(MAVLINK_COMM_1, cp, &message, &status);
		//MAVLINK_COMM_1 处可更改为通道数，用于处理来自于不同终端的信息

	return msgReceived;
}


void handle_message(DDTReceive& _DDTReceive_)
{
	// Store message sysid and compid.
	// Note this doesn't handle multiple message sources.
	current_messages.sysid  = message.sysid;
	current_messages.compid = message.compid;

	// Handle Message ID
	switch (message.msgid)
		{

			case MAVLINK_MSG_ID_HEARTBEAT:
				{
					printf("MAVLINK_MSG_ID_HEARTBEAT\n");
					mavlink_msg_heartbeat_decode(&message, &(current_messages.heartbeat));
					current_messages.time_stamps.heartbeat = get_time_usec();
					this_timestamps.heartbeat = current_messages.time_stamps.heartbeat;
					
					mavlink_heartbeat_t heart_rc = current_messages.heartbeat;

					printf(" Datefrom  sysid=%i ,  compid=%i  \n",  current_messages.sysid,  current_messages.compid);
					printf(" custom_mode = %i ,",  heart_rc.custom_mode);
					printf(" type = %i ,",  heart_rc.type);
					printf(" autopilot = %i ,",  heart_rc.autopilot);
					printf(" \n ");
					printf(" base_mode = %i ,",  heart_rc.base_mode);
					printf(" system_status = %i ,",  heart_rc.system_status);
					printf(" mavlink_version = %i ,",  heart_rc.mavlink_version);
					printf(" \n ");
					break;
				}

			case MAVLINK_MSG_ID_SYS_STATUS:
				{
					//printf("MAVLINK_MSG_ID_SYS_STATUS\n");
					mavlink_msg_sys_status_decode(&message, &(current_messages.sys_status));
					current_messages.time_stamps.sys_status = get_time_usec();
					this_timestamps.sys_status = current_messages.time_stamps.sys_status;
					break;
				}

			case MAVLINK_MSG_ID_BATTERY_STATUS:
				{
					//printf("MAVLINK_MSG_ID_BATTERY_STATUS\n");
					mavlink_msg_battery_status_decode(&message, &(current_messages.battery_status));
					current_messages.time_stamps.battery_status = get_time_usec();
					this_timestamps.battery_status = current_messages.time_stamps.battery_status;
					break;
				}

			case MAVLINK_MSG_ID_RADIO_STATUS:
				{
					//printf("MAVLINK_MSG_ID_RADIO_STATUS\n");
					mavlink_msg_radio_status_decode(&message, &(current_messages.radio_status));
					current_messages.time_stamps.radio_status = get_time_usec();
					this_timestamps.radio_status = current_messages.time_stamps.radio_status;
					break;
				}

			case MAVLINK_MSG_ID_LOCAL_POSITION_NED:
				{
					//printf("MAVLINK_MSG_ID_LOCAL_POSITION_NED\n");
					mavlink_msg_local_position_ned_decode(&message, &(current_messages.local_position_ned));
					current_messages.time_stamps.local_position_ned = get_time_usec();
					this_timestamps.local_position_ned = current_messages.time_stamps.local_position_ned;
					break;
				}

			case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
				{
					//printf("MAVLINK_MSG_ID_GLOBAL_POSITION_INT\n");
					mavlink_msg_global_position_int_decode(&message, &(current_messages.global_position_int));
					current_messages.time_stamps.global_position_int = get_time_usec();
					this_timestamps.global_position_int = current_messages.time_stamps.global_position_int;
					break;
				}

			case MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED:
				{
					//printf("MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED\n");
					mavlink_msg_position_target_local_ned_decode(&message, &(current_messages.position_target_local_ned));
					current_messages.time_stamps.position_target_local_ned = get_time_usec();
					this_timestamps.position_target_local_ned = current_messages.time_stamps.position_target_local_ned;
					break;
				}

			case MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT:
				{
					//printf("MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT\n");
					mavlink_msg_position_target_global_int_decode(&message, &(current_messages.position_target_global_int));
					current_messages.time_stamps.position_target_global_int = get_time_usec();
					this_timestamps.position_target_global_int = current_messages.time_stamps.position_target_global_int;
					break;
				}

			case MAVLINK_MSG_ID_HIGHRES_IMU:
				{
					//printf("MAVLINK_MSG_ID_HIGHRES_IMU\n");
					mavlink_msg_highres_imu_decode(&message, &(current_messages.highres_imu));
					current_messages.time_stamps.highres_imu = get_time_usec();
					this_timestamps.highres_imu = current_messages.time_stamps.highres_imu;
					break;
				}

			case MAVLINK_MSG_ID_ATTITUDE:
				{
					//printf("MAVLINK_MSG_ID_ATTITUDE\n");
					mavlink_msg_attitude_decode(&message, &(current_messages.attitude));
					current_messages.time_stamps.attitude = get_time_usec();
					this_timestamps.attitude = current_messages.time_stamps.attitude;
					break;
				}

			//add test
				case MAVLINK_MSG_ID_SELF_FAX_FORMATION:
				{
					printf("MAVLINK_MSG_ID_SELF_FAX_FORMATION\n");
					mavlink_msg_self_fax_formation_decode(&message, &(current_messages.self_fax_formation));
					current_messages.time_stamps.self_fax_formation = get_time_usec();
					this_timestamps.self_fax_formation = current_messages.time_stamps.self_fax_formation;
					
					mavlink_self_fax_formation_t position = current_messages.self_fax_formation;

					Receive_DroneState.ned_vel_x = position.ned_vel_x;
					Receive_DroneState.ned_vel_y = position.ned_vel_y;
					Receive_DroneState.ned_vel_z = position.ned_vel_z;
					Receive_DroneState.latitude 	= position.latitude;
					Receive_DroneState.altitude 	= position.altitude;
					Receive_DroneState.longtitude = position.longtitude;
										
					drone_state_pub.publish(Receive_DroneState);

					cout << "[vx, vy] = " << Receive_DroneState.ned_vel_x << ", " << Receive_DroneState.ned_vel_y<< endl;

					break;
				}

			case MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC:
				{
					printf("MAVLINK_MSG_ID_SELF_FAX_FORMATION_RC\n");
					mavlink_msg_self_fax_formation_rc_decode(&message, &(current_messages.self_fax_formation_rc));
					current_messages.time_stamps.self_fax_formation_rc = get_time_usec();
					this_timestamps.self_fax_formation_rc = current_messages.time_stamps.self_fax_formation_rc;
					
					mavlink_self_fax_formation_rc_t position = current_messages.self_fax_formation_rc;

					udpdatamsg.messageid = position.message_id;
					udpdatamsg.uavid = position.uav_id;
					udpdatamsg.number = position.number;
					udpdatamsg.plane_state = position.plane_state;
					udpdatamsg.plane_group = position.plane_group;
					udpdatamsg.longitudex = position.longitude_x;
					udpdatamsg.latitudey = position.latitude_y;
					udpdatamsg.altitudez = position.altitude_z;
					udpdatamsg.heading = position.heading;
					udpdatamsg.velocity = position.velocity;
					udpdatamsg.commandyaw = position.command_yaw;

					_DDTReceive_.UdpData_altitude_z.logPrint(udpdatamsg.altitudez);
					_DDTReceive_.UdpData_latitude_y.logPrint(udpdatamsg.latitudey);
					_DDTReceive_.UdpData_longitude_x.logPrint(udpdatamsg.longitudex);
					_DDTReceive_.UdpData_command_yaw.logPrint(udpdatamsg.commandyaw);
					_DDTReceive_.UdpData_heading.logPrint(udpdatamsg.heading);
					_DDTReceive_.UdpData_GPS_time_nsec.logPrint(udpdatamsg.messageid);
					_DDTReceive_.UdpData_number.logPrint(udpdatamsg.number);
					_DDTReceive_.UdpData_plane_group.logPrint(udpdatamsg.plane_group);
					_DDTReceive_.UdpData_plane_state.logPrint(udpdatamsg.plane_state);
					_DDTReceive_.UdpData_uav_id.logPrint(udpdatamsg.uavid);
					_DDTReceive_.UdpData_velocity.logPrint(udpdatamsg.velocity);
					// _DDTReceive_.UdpData_GPS_time_sec.logPrint(udpdatamsg.GPS_time.sec);

					cout<<"udpdatamsg.messageid : "<<udpdatamsg.messageid<<endl;
					cout<<"udpdatamsg.uavid : "<<udpdatamsg.uavid<<endl;
					cout<<"udpdatamsg.plane_state : "<<udpdatamsg.plane_state<<endl;
					cout<<"udpdatamsg.plane_group : "<<udpdatamsg.plane_group<<endl;
					cout<<"udpdatamsg.longitudex : "<<udpdatamsg.longitudex<<endl;
					cout<<"udpdatamsg.latitudey : "<<udpdatamsg.latitudey<<endl;
					cout<<"udpdatamsg.altitudez : "<<udpdatamsg.altitudez<<endl;
					cout<<"udpdatamsg.heading : "<<udpdatamsg.heading<<endl;
					cout<<"udpdatamsg.velocity : "<<udpdatamsg.velocity<<endl;
					cout<<"udpdatamsg.commandyaw : "<<udpdatamsg.commandyaw<<endl;
					
					
					UDPData_pub[udpdatamsg.uavid].publish(udpdatamsg);
					cout<<UDPData_pub[udpdatamsg.uavid].getTopic()<<endl;

					break;
				}

			case MAVLINK_MSG_ID_QGCOMMANDS:
				{
					printf("MAVLINK_MSG_ID_QGCOMMANDS\n");
					mavlink_msg_qgcommands_decode(&message, &(current_messages.qgcomands));
					current_messages.time_stamps.qgcommands = get_time_usec();
					this_timestamps.qgcommands = current_messages.time_stamps.qgcommands;
					
					mavlink_qgcommands_t qgccommans_state = current_messages.qgcomands;

					ddtqgcommands.messageid = qgccommans_state.message_id;
					ddtqgcommands.uavid = qgccommans_state.uav_id;
					ddtqgcommands.gsid = qgccommans_state.gs_id;
					ddtqgcommands.plane_state = qgccommans_state.plane_state;
					ddtqgcommands.plane_group = qgccommans_state.plane_group;
					ddtqgcommands.uavnumber = qgccommans_state.vehicleNumber;
					ddtqgcommands.tasktype = qgccommans_state.taskType;
					ddtqgcommands.gapx = qgccommans_state.gapx;
					ddtqgcommands.gapy = qgccommans_state.gapy;

					cout<<"ddtqgcommands.messageid : "<<ddtqgcommands.messageid<<endl;
					cout<<"ddtqgcommands.uavid : "<<ddtqgcommands.uavid<<endl;
					cout<<"ddtqgcommands.gsid : "<<ddtqgcommands.gsid<<endl;
					cout<<"ddtqgcommands.plane_state : "<<ddtqgcommands.plane_state<<endl;
					cout<<"ddtqgcommands.plane_group : "<<ddtqgcommands.plane_group<<endl;
					cout<<"ddtqgcommands.uavnumber : "<<ddtqgcommands.uavnumber<<endl;
					cout<<"ddtqgcommands.tasktype : "<<ddtqgcommands.tasktype<<endl;
					cout<<"uddtqgcommands.gapx : "<<ddtqgcommands.gapx<<endl;
					cout<<"uddtqgcommands.gapy : "<<ddtqgcommands.gapy<<endl;
					
					
					qgcommands_pub.publish(ddtqgcommands);

					break;
				}

			default:
				{
					printf("Warning, did not handle message id %i\n",message.msgid);
					break;
				}

		} // end: switch msgid

};

// ----------------------------------------------------------------------------------
//   Time
// ------------------- ---------------------------------------------------------------
uint64_t
get_time_usec()
{
	static struct timeval _time_stamp;
	gettimeofday(&_time_stamp, NULL);
	return _time_stamp.tv_sec*1000000 + _time_stamp.tv_usec;
}

