#include "threeDimensionVF.h"

threeDimensionVF::threeDimensionVF(){}
threeDimensionVF::~threeDimensionVF(){}


double threeDimensionVF::sat(double x){
    if(abs(x) <= 1)                 return x;
    else if(abs(x) > 1 && x > 0)    return 1;
    else if(abs(x) > 1 && x == 0)   return 0;
    else if(abs(x) > 1 && x < 0)    return -1;
}

/* Dubins path */
double threeDimensionVF::mod(double x){ // %
    x = x + 2 * M_PI;
    x = fmod(x, 2 * M_PI);
    return x;
}
// 绕着 Z 轴旋转 theta_ 角度的旋转矩阵
void threeDimensionVF::setRotation_Z(double theta_){

    double theta = mod(theta_);
    double ang[9] = { 
        cos(theta), -sin(theta), 0, 
        sin(theta), cos(theta), 0, 
        0, 0, 1 
    };
    size_t k = 0;
    for(size_t i = 0; i < 3; i++){ 
        for(size_t j = 0; j < 3; j++){ 
            Rotation[i][j] = ang[k++];
        } 
    }
}
// 绕着 Y' 轴旋转 theta_ 角度的旋转矩阵
void threeDimensionVF::setRotation_Y_(double theta_){

    double theta = mod(theta_);
    double ang[9] = { 
        cos(theta), 0, sin(theta), 
        0, 1, 0,
        -sin(theta), 1, cos(theta)
    };
    size_t k = 0;
    for(size_t i = 0; i < 3; i++){ 
        for(size_t j = 0; j < 3; j++){ 
            Rotation[i][j] = ang[k++];
        } 
    }
}
void threeDimensionVF::printRotation(){
    for(size_t i = 0; i < 3; i++){
        for(size_t j = 0; j < 3; j++){ cout << Rotation[i][j] << "\t\t"; } cout << endl;
    }
}
// 右手坐标系进行变换时将T与需要变换的点或向量A（列向量）相乘，即TA。也就是说原始矩阵A放右边。
Three_Dimensional_Vector threeDimensionVF::Rotation_multiplied_vector(Three_Dimensional_Vector _vector_){

    Three_Dimensional_Vector Rotation_1(Rotation[0][0], Rotation[0][1], Rotation[0][2]);
    Three_Dimensional_Vector Rotation_2(Rotation[1][0], Rotation[1][1], Rotation[1][2]);
    Three_Dimensional_Vector Rotation_3(Rotation[2][0], Rotation[2][1], Rotation[2][2]);

    Three_Dimensional_Vector reasult;
    reasult.update( Rotation_1 * _vector_, Rotation_2 * _vector_, Rotation_3 * _vector_ );

    return reasult;
}


void threeDimensionVF::getEuler(const sensor_msgs::Imu msg, double& yaw, double& pitch){
    std::cout << "3D vf 四元数转欧拉角" << std::endl;
	float q[4];

    q[0] = msg.orientation.w;
    q[1] = msg.orientation.x;
    q[2] = msg.orientation.y;
    q[3] = msg.orientation.z;

    quaternion_2_euler(q, att_angle_Euler);

    double roll_angle = att_angle_Euler[0];
    pitch = -att_angle_Euler[1];

    if (att_angle_Euler[2] + deg_2_rad(90.0) > 0)
        yaw = att_angle_Euler[2] + deg_2_rad(90.0); //添加符号使增加方向相同，而且领先于px490°
    else
        yaw = att_angle_Euler[2] + deg_2_rad(90.0) + deg_2_rad(360.0);
}

void threeDimensionVF::THREEDVF(
    Three_Dimensional_Vector previous_waypoint,
    Three_Dimensional_Vector current_waypoint,
    Three_Dimensional_Vector local_position,
    double psi,
    double theta,
    double v            // 没有明确是空速还是地速度
){
    std::cout << "3D vf 控制核心逻辑执行" << std::endl;

    // 1. 角度转换, 变量赋值
    alpha = atan2(
        current_waypoint.getY() - previous_waypoint.getY(),
        current_waypoint.getX() - previous_waypoint.getX()
    );

    setRotation_Z(alpha);
    Previous_Waypoint_R = Rotation_multiplied_vector(previous_waypoint);
    Current_Waypoint_R  = Rotation_multiplied_vector(current_waypoint);

    beta = atan2(
        Current_Waypoint_R.getZ() - Previous_Waypoint_R.getZ(),
        Current_Waypoint_R.getX() - Previous_Waypoint_R.getX()
    );
    std::cout << "beta : " << beta << std::endl;
    Three_Dimensional_Vector error_enu; // enu坐标系下的 当前位置和 previous 航点的矢量误差
    error_enu = local_position - current_waypoint;

    setRotation_Z(alpha);
    _error_ = Rotation_multiplied_vector(error_enu);
    setRotation_Y_(beta);
    _error_ = Rotation_multiplied_vector(_error_);

    double psi_R = psi - alpha;
    double theta_R = theta - beta;
    
    double tilde_chi_psi;   // VF 定义的期望角速度; XY 平面
    double tilde_chi_theta;   // VF 定义的期望角速度; XZ 平面
    
    // 2. 控制律计算
    tilde_chi_psi = psi_R - (-chi_psi_inf * 2 / M_PI * atan(s_psi * _error_.getY()));
    tilde_chi_theta = theta_R - (-chi_theta_inf * 2 / M_PI * atan(s_theta * _error_.getY()));

    double psi_d = 
        psi_R - 
        chi_psi_inf / k_psi * 2 / M_PI * (s_psi * v * sin(psi)) / (1 - pow(s_psi * _error_.getY(), 2)) - 
        kappa_psi / k_psi * sat(tilde_chi_psi / epsilon_psi);
    
    double theta_d = 
        theta_R - 
        chi_theta_inf / k_theta * 2 / M_PI * (s_theta * v * sin(theta)) / (1 - pow(s_theta * _error_.getZ(), 2)) - 
        kappa_theta / k_theta * sat(tilde_chi_theta / epsilon_theta);
    
    psi_d = psi_d + alpha;
    theta_d = theta_d + beta;

    r_d = k_psi * (psi_d - psi);
    q_d = k_theta * (theta_d - theta);
}

