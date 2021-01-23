
#include <ros/ros.h>

#include <Eigen/Eigen>
#include <Eigen/Geometry>
#include <GeographicLib/Geocentric.hpp>
#include <mavros/frame_tf.h>
#include <mavros_msgs/Waypoint.h>
#include <mavros_msgs/HomePosition.h>
#include <mavros_msgs/VFR_HUD.h>
#include <mavros_msgs/WaypointReached.h>
#include <mavros_msgs/WaypointList.h>
#include <geometry_msgs/PoseStamped.h>

#include "fw_msgs/EXITflag.h"

#include "../../lib/logger/LogStream.hpp"
#include "../../lib/mathlib/vector/three_dimensional_vector.hpp"
#include "../../lib/mathlib/vector/vector.hpp"
#include "../../lib/Macro.hpp"

class TestData{
    private:
        std::string uavName;
    public:
        TestData(std::string);
        ~TestData();
        // run
        void run();

        ros::NodeHandle nh;

        ros::Subscriber home_sub_0;
        ros::Subscriber home_sub_1;
        ros::Subscriber home_sub_2;
        ros::Subscriber home_sub_3;
        ros::Subscriber home_sub_4;

        ros::Subscriber mission_reached_sub;
        ros::Subscriber mission_waypointList_sub;

        ros::Subscriber leader_state_sub;
    	ros::Subscriber leader_localPos_sub;

        ros::Publisher uav_exitflag_pub;

        ros::Timer timer;

        void newHomePosition_0(const mavros_msgs::HomePosition::ConstPtr& msg);
        void newHomePosition_1(const mavros_msgs::HomePosition::ConstPtr& msg);
        void newHomePosition_2(const mavros_msgs::HomePosition::ConstPtr& msg);
        void newHomePosition_3(const mavros_msgs::HomePosition::ConstPtr& msg);
        void newHomePosition_4(const mavros_msgs::HomePosition::ConstPtr& msg);


        void missionReached(const mavros_msgs::WaypointReached::ConstPtr& msg);
        void missionWaypointList(const mavros_msgs::WaypointList::ConstPtr& msg);

        void new_leaderPose(const geometry_msgs::PoseStamped::ConstPtr& msg);
        void newLeaderState(const mavros_msgs::VFR_HUD::ConstPtr& msg);

        void timerCallback(const ros::TimerEvent& e);

        // 验证 home 点测试距离
        void getENUoffset(mavros_msgs::Waypoint startlistposition, mavros_msgs::Waypoint endlistposition, Eigen::Vector3d* enu_offset);
        Point calculate_configuration_error(mavros_msgs::HomePosition);
        
        // 五家飞机的home点的位置
        mavros_msgs::HomePosition leader_home;
        mavros_msgs::HomePosition follower1_home;
        mavros_msgs::HomePosition follower2_home;
        mavros_msgs::HomePosition follower3_home;
        mavros_msgs::HomePosition follower4_home;

        mavros_msgs::WaypointReached _waypointReached_;
        mavros_msgs::WaypointList _waypointLists_;

        geometry_msgs::PoseStamped current_leaderPose;
        mavros_msgs::VFR_HUD current_Leader_state;

        fw_msgs::EXITflag exitflag;

        ros::TimerEvent timerEvent;

        // 四个间隔的距离
        Point dist_0_1{0.0f};
        Point dist_0_2{0.0f};
        Point dist_0_3{0.0f};
        Point dist_0_4{0.0f};

        // 打印距离
        void print_dists();

        void sendTo(bool is);
        
        void print_wp(const mavros_msgs::Waypoint& wp)
        {
            ROS_INFO("waypoint: x_lat = %f y_long = %f z_alt = %f ", wp.x_lat,wp.y_long,wp.z_alt);
            ROS_INFO("command = %d frame = %d autocontinue = %d ",wp.command,wp.frame,wp.autocontinue);
            ROS_INFO("param:%f %f %f %f", wp.param1,wp.param2,wp.param3,wp.param4);
        }


};