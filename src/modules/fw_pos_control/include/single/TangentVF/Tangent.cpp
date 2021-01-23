#include "Tangent.h"

Tangent::Tangent():
    p_modified(0.0f,0.0f,0.0f),
    p_current(0.0f,0.0f,0.0f),
    Wind(0.0f, 0.0f)
{

}

Tangent::~Tangent(){

}

/* Dubins path */
double Tangent::mod(double x){ // %
    x = x + 2 * M_PI;
    x = fmod(x, 2 * M_PI);
    return x;
}
// 绕着 Z 轴旋转 theta_ 角度的旋转矩阵
void Tangent::setRotation_T3(){

    double chi_r = mod(chi_current);
    double gamma_r = mod(gamma_current);

    double ang[9] = { 
        -sin(chi_r),                cos(chi_r),                 0, 
        -sin(gamma_r) * cos(chi_r), -sin(gamma_r) * sin(chi_r), cos(gamma_r), 
        cos(gamma_r) * cos(chi_r),  cos(gamma_r) * sin(chi_r),  sin(gamma_r) 
    };
    size_t k = 0;
    for(size_t i = 0; i < 3; i++){ 
        for(size_t j = 0; j < 3; j++){ 
            Rotation_T3[i][j] = ang[k++];
        } 
    }
}

// 设置中间量
// 将矩阵旋转到新的坐标系下
void Tangent::setPosition(Three_Dimensional_Vector current_local_postion){
    p_current.update(
        current_local_postion.getX(), 
        current_local_postion.getY(), 
        current_local_postion.getZ()
    );
    Three_Dimensional_Vector Rotation_1(Rotation_T3[0][0], Rotation_T3[0][1], Rotation_T3[0][2]);
    Three_Dimensional_Vector Rotation_2(Rotation_T3[1][0], Rotation_T3[1][1], Rotation_T3[1][2]);
    Three_Dimensional_Vector Rotation_3(Rotation_T3[2][0], Rotation_T3[2][1], Rotation_T3[2][2]);

    p_modified.update( Rotation_1 * p_current, Rotation_2 * p_current, Rotation_3 * p_current );
}
void Tangent::setChi_Gamma_r(){ // 就是当前期望航点的切线
    chi_current = atan2(ENU_End.getX() - ENU_Start.getX(), ENU_End.getY()- ENU_Start.getY());
    gamma_current = 
        atan2(
            ENU_End.getZ() - ENU_Start.getZ(), 
            sqrt(pow(ENU_End.getX() - ENU_Start.getX(), 2) + pow(ENU_End.getY()- ENU_Start.getY(), 2))
        );
}
// void Tangent::setRotated_Matrix(){
//     setRotation_T3();
// }
void Tangent::updateDistanceError(){
    r_error = sqrt(pow(p_modified.getX(), 2) + pow(p_modified.getY(), 2));
}
void Tangent::setAirspeed(){
    Airspeed = 20;
}
void Tangent::setGroundSpeed(){
    double part1 = Wind.x * cos(chi_current) + Wind.y * sin(chi_current);
    double part2 = 
        4 * pow(Airspeed, 2) - 
        3 * (pow(Wind.x, 2) + pow(Wind.y, 2)) + (pow(Wind.x, 2) - pow(Wind.y, 2)) * cos(2 * chi_current);
    double part3 = 
        2 * pow(Wind.x * cos(chi_current) + Wind.y * sin(chi_current), 2) 
        * cos(2 * chi_current) + 2 * Wind.x * Wind.y * sin(2 * chi_current);
    
    GroundSpeed = part1 + 0.5 * sqrt(part2 + part3);
}

// 主要处理逻辑
double Tangent::Run(){
    // 函数参数
    Three_Dimensional_Vector current_local_position;
    Three_Dimensional_Vector Start;
    Three_Dimensional_Vector End;

    ENU_Start = Start;
    ENU_End = End;
    
    // 中间变量设置
    setAirspeed();
    setGroundSpeed();
    setPosition(current_local_position);
    updateDistanceError();

    setChi_Gamma_r();
    setRotation_T3();
    
    

    dot_chi_d = 0;
    dot_gamma_d = 0; 
}

// 获得期望值
double Tangent::getChi_d(){
    return dot_chi_d;
}

double Tangent::getGamma_d(){
    return dot_gamma_d;
}