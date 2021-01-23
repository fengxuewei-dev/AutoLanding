#pragma once

#include <iostream>
#include <map>
#include <ros/ros.h>

#include <Eigen/Eigen>
#include <Eigen/Geometry>
#include <GeographicLib/Geocentric.hpp>

#include "../../../../lib/Macro.hpp"
#include "../../../../lib/mathlib/vector/vector.hpp"
#include "../../../../lib/mathlib/vector/three_dimensional_vector.hpp"
#include "../../../../lib/logger/LogStream.hpp"

#include <mavros_msgs/Waypoint.h>
#include <mavros_msgs/WaypointList.h>
#include <mavros_msgs/HomePosition.h>
#include <mavros/frame_tf.h>

#include <geometry_msgs/PoseStamped.h>

#define RADIUS_COEFFICIENT  0.915
#define ADVANCE_DISTANCE    70          // 提前转弯的距离（HITL 观察是需要62.5）

class Algorithms
{
private:
    bool hasNewWaypointList;

    int state{0};

    // logStream circle_;
    // logStream half_plane;
    // logStream Radius_;

public:
    Algorithms();
    ~Algorithms();

    // 订阅航线(ned 位置)
    ros::NodeHandle nh;

    mavros_msgs::WaypointList waypointList;
    mavros_msgs::WaypointList waypointList_previous;
    mavros_msgs::HomePosition current_home;

    /* algorithms will get them */
    int flag;
    mavros_msgs::Waypoint r;
    Three_Dimensional_Vector q;
    Three_Dimensional_Vector c;
    Three_Dimensional_Vector z1;
    Three_Dimensional_Vector z2;
    int lamda;
    float rho;

    mavros_msgs::Waypoint fillet_center;

    /*half_plane's arguements*/
    Three_Dimensional_Vector wp_;
    Three_Dimensional_Vector n_i_;
    Three_Dimensional_Vector position_;



    void waypointlist_cb(const mavros_msgs::WaypointList msg);
    void print_wp(const mavros_msgs::Waypoint& wp);
    void getENUoffset(mavros_msgs::Waypoint startlistposition, mavros_msgs::Waypoint endlistposition, Eigen::Vector3d* enu_offset);

    bool arrive_half_plane(Three_Dimensional_Vector, Three_Dimensional_Vector, Three_Dimensional_Vector);
    
    // void algorithm5(mavros_msgs::WaypointList, geometry_msgs::PoseStamped, uint16_t&);
    void StraightLineSwitching(mavros_msgs::WaypointList, geometry_msgs::PoseStamped, uint16_t&);
    
    // void algorithm6(mavros_msgs::WaypointList, geometry_msgs::PoseStamped, float, uint16_t&); // Follow_Waypoints_with_Fillets
    void StraightLineSwitching_Fillet(mavros_msgs::WaypointList, geometry_msgs::PoseStamped, float, uint16_t&); // Follow_Waypoints_with_Fillets


    // dubins path
    void dubins_path(mavros_msgs::WaypointList, geometry_msgs::PoseStamped, float, uint16_t&); // Follow_Waypoints_with_Fillets
    
    map<int, double> waypointYaw;
    void getMapYaw();

    /*  algorithm 7  >>>>>>>>>>>>>>>> */
    void findDubinsParameters( mavros_msgs::Waypoint,  mavros_msgs::Waypoint,  double, double, float);

    /* output parameter saving */
    Three_Dimensional_Vector Center_s;       // 计算出来的初始圆心
    Three_Dimensional_Vector Center_e;       // 最后的圆心
    int lamda_s;        // 开始圆心处loiter的方向
    int lamda_e;        // 最后圆心处loiter的方向
    Three_Dimensional_Vector q_1;       // 圆心连线的方向向量
    Three_Dimensional_Vector z_1;       // 第一个半平面
    Three_Dimensional_Vector z_2;       // 第二个半平面
    Three_Dimensional_Vector z_3;       // 保留最终的ned位置, 为下一次计算做准备
    Three_Dimensional_Vector q_3;       
    double LENGTH;

    /* the Parameters saving */
    Three_Dimensional_Vector e_1{1, 0, 0};
    Three_Dimensional_Vector position_s_;
    Three_Dimensional_Vector position_e_;
    double dubins_path_radius;      // Dubins path's Radius
    double chi_s;
    double chi_e;

    /* four types center */
    Three_Dimensional_Vector Center_L;
    Three_Dimensional_Vector Center_L_S;
    Three_Dimensional_Vector Center_L_E;
    Three_Dimensional_Vector Center_R;
    Three_Dimensional_Vector Center_R_S;
    Three_Dimensional_Vector Center_R_E;


    double vartheta;    // 圆心直线的夹角(与north), 需要先求两个圆心
    double Length_min{0}; int Length_min_number{0};
    double Length_1{0};
    double Length_2{0};
    double Length_3{0};
    double Length_4{0};

    double mod(double);
    double min(double, double);

    void getMiniLengthAndNumber();

    void getCenter_R(Three_Dimensional_Vector position, double chi);
    void getCenter_L(Three_Dimensional_Vector position, double chi);

    void _length_R_S_R();
    void _length_R_S_L();
    void _length_L_S_R();
    void _length_L_S_L();

    /* 三维旋转矩阵 */
    double Rotation[3][3];
    void setRotation(double);
    void printRotation();
    Three_Dimensional_Vector Rotation_multiplied_vector(Three_Dimensional_Vector);

    /* <<<<<<<<<<<<<<<<<<<< algorithm 7 */

    void generateFilletCenter(Three_Dimensional_Vector, float);
    int getState(){ return state; }
    void ENU_change_NED();
    bool isSame();

};