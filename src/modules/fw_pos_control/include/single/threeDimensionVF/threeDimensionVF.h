#include <iostream>
#include "../../../../../lib/mathlib/vector/three_dimensional_vector.hpp"

#include <sensor_msgs/NavSatFix.h> //GPS Fix.
#include <sensor_msgs/Imu.h>

class threeDimensionVF{
    private:

        // 初始参数
        double chi_psi_inf = M_PI / 2;     /* heading; the maximum of angles of approach to the trajectory */
        double chi_theta_inf = M_PI / 2;     /* pitch; the maximum of angles of approach to the trajectory */

        double epsilon_psi = 1;     // 围绕控制过程中减少震荡的平滑面的过度区域
        double epsilon_theta = 1;     // 围绕控制过程中减少震荡的平滑面的过度区域

        double s_psi = 0.11;           // 影响期望角度从 inf 到 0 的过度速率的正比例系数
        double s_theta = 0.4578;           // 影响期望角度从 inf 到 0 的过度速率的正比例系数
        // double s_theta = 0.04;           // 影响期望角度从 inf 到 0 的过度速率的正比例系数
        
        double k_psi = 2.22;       // yaw rate: 比例控制增益
        // double k_theta = 8;       // pitch rate: 比例控制增益
        double k_theta = 3.10;       // pitch rate: 比例控制增益

        double kappa_psi = 0.67;
        double kappa_theta = 7.06;

        double alpha;           // 两个航点在 XY 平面的上的方向角
        double beta;            // 两个航点在 XZ 平面的上的方向角
        
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
        threeDimensionVF();
        ~threeDimensionVF();

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
        void getEuler(const sensor_msgs::Imu, double&, double&);

        // 获取 yaw 
        double getYaw_sp(){     return r_d;  }
        double getPitch_sp(){   return q_d;  }
};