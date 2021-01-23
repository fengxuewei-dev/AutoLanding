/////////////////////////UDP
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#define SERV_PORT   8002
///////////////////////////
using namespace std;
#include <iostream>
//#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <inttypes.h>
#include <fstream>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
using std::string;
#include <ros/ros.h>
#include <serial/serial.h>
#include<mavros_msgs/Formation_fixed_wing.h>

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

void CreatSocket(int* length, int* sockfd);

int Checkdata(Senddata recv_buf, int id);