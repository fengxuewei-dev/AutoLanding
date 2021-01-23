#!/bin/bash

# killall -9 rosmaster
killall gzclient

# clean ros log Cache
rosclean purge -y

