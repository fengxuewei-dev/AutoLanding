/////////////////////////UDP
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <inttypes.h>
#include <fstream>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <ros/ros.h>
#include <serial/serial.h>


#include "Conmon.h"


void CreatSocket(int* length, int* sockfd, int port);

int Checkdata(Senddata recv_buf, int id);

int Checkdata(UDP_Data UDP_buf, int messageid);

int Checkdata(ACK ACK_buf, int messageid);

int Checkdata(Qgc_Commands QC_buf, int messageid);

int Checkdata(Upd_HP UPDH_buf, int messageid);