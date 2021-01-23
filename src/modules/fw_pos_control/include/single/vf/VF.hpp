#pragma once

#include <math.h>
#include <ros/ros.h>
#include "../../../../../lib/mathlib/vector/vector.hpp"
#include "../../../../../lib/logger/LogStream.hpp"
#include "../../../../../lib/mathlib/vector/three_dimensional_vector.hpp"
#include "../../../../../lib/Macro.hpp"


#include <sensor_msgs/NavSatFix.h> //GPS Fix.
#include <sensor_msgs/Imu.h>

#include <iostream>
#include <fstream>

using namespace std;

#ifndef STEP
#define STEP (1.0/20)
#endif

#define K2_HAT_PREVIOUS (M_PI/100/alpha) 
#define K2_HAT_PREVIOUS_O (M_PI/100/alphaOrbit) 

#define LOWLIMIT_2  (0.95*M_PI/100/alpha)
#define UPPERLIMIT_2    (1.05*M_PI/100/alpha)

#define LOWLIMIT_O_2  (0.95*16/alphaOrbit)
#define UPPERLIMIT_O_2    (1.05*16/alphaOrbit)
class VF
{
private:
    // PARAMETERS  alpha k; alpha pitch; simulink; offboard
    // offboard lee 的固件：四元数的修改； 油门方向的数组的不同位置的修改
    double k = 1; //transition gain > 1
    double S_groundSpeed = M_PI/100;
    double chi_MAVHeading = M_PI/100;
    double chi_infinite = M_PI/2;
    double alpha = 0.4578; //TODO find what is this
    double alphaOrbit = 16; 
    unsigned int distanceThreshold = 100; 
    
    // 标准纵向控制
    const int height_distanceThreshold = 30; 
    double height_theta_infinite = M_PI / 3;
    double k_pitch = 3; //transition gain > 1  表示调节的快慢
    double alpha_pitch = 0.4578; //TODO find what is this

    // modify
    double lambda = 0;
    double k_m = 0.1;
    double xi_0 = 0.01;
    double xi_1 = 0.01;
    double xi_2 = 0.0001;
    double eta = 1;
    
    double k_sl = 1;
    //改动： 新增加的 k_o 变量
    double k_o = 1;
    double zeta2 = 0;
    double k2_hat_previous = 0;
    double k2_hat_previous_O =0;
    double Lowlimit_2 = 0;
    double Upperlimit_2 = 0;
    double Lowlimit_O_2 = 0;
    double Upperlimit_O_2 = 0;


    /*   three dimension vector field    */

        // 初始参数
        double chi_psi_inf = M_PI / 2;     /* heading; the maximum of angles of approach to the trajectory */
        double chi_theta_inf = M_PI / 2;     /* pitch; the maximum of angles of approach to the trajectory */

        double epsilon_psi = 1;     // 围绕控制过程中减少震荡的平滑面的过度区域
        double epsilon_theta = 1;     // 围绕控制过程中减少震荡的平滑面的过度区域

        double s_psi = 0.11;                // 影响期望角度从 inf 到 0 的过度速率的正比例系数
        double s_theta = 0.4578;            // 影响期望角度从 inf 到 0 的过度速率的正比例系数
        // double s_theta = 0.04;           // 影响期望角度从 inf 到 0 的过度速率的正比例系数
        
        double k_psi = 2.22;                // yaw rate: 比例控制增益
        // double k_theta = 8;                 // pitch rate: 比例控制增益
        double k_theta = 3.10;           // pitch rate: 比例控制增益

        double kappa_psi = 0.67;
        double kappa_theta = 7.06;

        double course_alpha;           // 两个航点在 XY 平面的上的方向角
        double course_beta;            // 两个航点在 XZ 平面的上的方向角
        
        // 算法输出量
        double r_d;             // VF 输出量: yaw rate
        double q_d;             // VF 输出量: pitch rate

        // 航迹坐标系下的航点
        Three_Dimensional_Vector Previous_Waypoint_R;               // 旋转到 路径坐标系 下的 previous waypoint
        Three_Dimensional_Vector Current_Waypoint_R;                // 旋转到 路径坐标系 下的 current waypoint

        // ERROR 误差向量
        Three_Dimensional_Vector _error_;

        // 计算过程中保存的变量
        double Rotation[3][3];  /* 三维旋转矩阵 */
	    float att_angle_Euler[3];  //无人机当前欧拉角(从飞控中读取)

public:
    ros::NodeHandle nh;
    VF(double  newk, double newchi_infinite, double newalpha, unsigned int newdistanceThreshold);
    VF();

    ~VF( );

    // void publishCom(){
    //     communication_pub.publish(com1);
    // }
    double satFunction(double x);
    double cal_sl_K2_hat(double chi_tilde, double Gamma, double rho, double epy, double Heading, double chi_q, double va );
    // double getHeading(Point Z, Point Start, Point End,  double S_groundSpeed, double chi_MAVHeading);
    double getHeading(Point Z, Point Start, Point End, double S_groundSpeed, double chi_MAVHeading, double chi_MAVTheta, double airspeed
            ,const double, const double
        );
    double getPitch(Three_Dimensional_Vector Z, Three_Dimensional_Vector Start, Three_Dimensional_Vector End, double S_groundSpeed, double theta_MAV, double psi_MAV, const double, const double);
    
    double getHeading_10_8(Point Z, Point Start, Point End, double S_groundSpeed, double chi_MAVHeading, double airspeed);
    // double getHeadingOrbit(Point Z, Point Center, double radius, double groundSpeed, double chi_MAVHeading);
    double getHeadingOrbit(Point Z, Point Center, double radius, double groundSpeed, double chi_MAVHeading, float dir, double airspeed);
    double getPositionOnLine(Point Z, Point Start, Point End);

    // 改动：增加了 函数 cal_o_k2_hat 在类中的声明 
    double cal_o_k2_hat(double gamma, double radius, double distance, double chi, double dir, double Gamma, double d_tilde, double chi_tilde);


    /*  3Dimension VF  */
     // 旋转矩阵
        void setRotation_Z(double);
        void setRotation_Y_(double);
        void printRotation();

        double mod(double);
        double sat(double);     // saturation function: 饱和函数; 避免震荡带来的不利影响

        Three_Dimensional_Vector Rotation_multiplied_vector(Three_Dimensional_Vector);
        
        void THREEDVF( 
            Three_Dimensional_Vector, Three_Dimensional_Vector, Three_Dimensional_Vector,
            double, double, double
        );      // 3维VF 控制逻辑

        // 将 四元数 转换 到 欧拉角
        void getEuler(const sensor_msgs::Imu, double&, double&, double&);

        // 计算三维的 中间量
        void getErrorXYZ(Three_Dimensional_Vector, Three_Dimensional_Vector, Three_Dimensional_Vector, double&, double&);     
        void getMAV_side(Three_Dimensional_Vector, Three_Dimensional_Vector, Three_Dimensional_Vector, double&, double&);    

        // 获取 yaw 
        double getYaw_sp(){     return r_d;  }
        double getPitch_sp(){   return q_d;  }
};

// 概述， 问题描述，方法介绍，对比仿真，结论
// 航向、位置、速度、目标位置，作为状态量（参数），设计关于bpu的控制率，再计算bpu和theta的关系，再计算alpha