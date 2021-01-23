#pragma once

#include <iostream>
#include "../../../../../lib/mathlib/vector/three_dimensional_vector.hpp"
#include "../../../../../lib/mathlib/vector/vector.hpp"

// #include <sensor_msgs/NavSatFix.h> //GPS Fix.
// #include <sensor_msgs/Imu.h>

class Tangent{
    private:
        // 常参
        double alpha{0.0f};
        double beta{0.0f};

        // 旋转之后的点
        Three_Dimensional_Vector p_modified;
        Three_Dimensional_Vector p_current;

        Three_Dimensional_Vector ENU_Start;
        Three_Dimensional_Vector ENU_End;

        // 距离误差
        double r_error{0.0f};

        // 旋转矩阵
        double Rotation_T3[3][3]; 

        // 环境因素
        Point Wind;

        // 飞机的状态变量
        double chi_current{0.0f};
        double gamma_current{0.0f};
        double Airspeed{0.0f};
        double GroundSpeed{0.0f};

        // 期望值保存
        double dot_chi_d{0.0f};
        double dot_gamma_d{0.0f};

    public:
        Tangent();
        ~Tangent();

        // 约束角度，限幅度为 [0, 2 * M_PI]
        double mod(double);

        // 得到旋转矩阵
        void setRotation_T3();
        void setPosition(Three_Dimensional_Vector);
        void setChi_Gamma_r();
        void setRotated_Matrix();
        void setGroundSpeed();
        void setAirspeed();
        void updateDistanceError();

        // 获得期望值
        double getChi_d();
        double getGamma_d();

        double Run();
};