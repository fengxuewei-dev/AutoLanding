#pragma once

/////////////////////////UDP
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
// #define SERV_PORT_UAV1   8004
// #define SERV_PORT_UAV2   8005
///////////////////////////
//#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <inttypes.h>
#include <fstream>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <ros/ros.h>
#include <serial/serial.h>
// #include <mavros_msgs/Formation_fixed_wing.h>
#include "fw_msgs/commands.h"

#include <stdint.h>
#include <cstdint>
#include <iostream>

using namespace::std;

// Senddata
typedef struct Senddata {
	int id = 0;
	int Parity = 0;
	bool vfr_leader_valid = false;
	bool pose_leader_valid = false;
	bool command_leader_valid = false;
	bool home_valid = false;
	
	// mavros_msgs::VFR_HUD vfr_leader:
	// string header;
	float vfr_airspeed;
	float groundspeed;
	int16_t vfr_heading;
	// float32 throttle;
	// float32 altitude;
	
	// pose
	float pose_x;
	float pose_y;
	float pose_z;
	// command
	float command_altitude;
	float command_yaw;
	float command_throttle;

	// formationShap
	char formationShap;

	// 主机的home经纬度
	double home_lat;
	double home_lon;

  // timer
	long long msec; // 毫秒
}SendData;

class udpReceive{
	private:
	public:
		SendData dataleader;
		void CreatSocket(int* length, int* sockfd, int port);
		int Checkdata(	SendData recv_buf, int id);
};
