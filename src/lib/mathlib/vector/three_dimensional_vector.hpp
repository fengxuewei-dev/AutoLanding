#pragma once

#include <math.h>
#include <iostream>
#include "../math/mathlib.hpp"
using namespace std;
class Three_Dimensional_Vector;
typedef Three_Dimensional_Vector tri_Vec;

class Three_Dimensional_Vector
{
private:
    double x;
    double y;
    double z;
public:
    Three_Dimensional_Vector(double _x = 0, double _y = 0, double _z = 0) : x(_x), y(_y), z(_z) {}
    // Three_Dimensional_Vector(const Three_Dimensional_Vector& source){ // CHANGE ENU TO NED
    //     x = source.y;       // source.x E; source.y N; source U
    //     y = source.x;       // xyz: X N; Y E; Z D
    //     z = -source.z;
    // }
     Three_Dimensional_Vector(const Three_Dimensional_Vector& source){ // CHANGE ENU TO NED
        x = source.x;       // source.x E; source.y N; source U
        y = source.y;       // xyz: X N; Y E; Z D
        z = source.z;
    }
    ~Three_Dimensional_Vector(){}

    double getX(){
        return x;
    }
    void ConverseY(){
        y = -1.0f * y;
    }
    double getY(){
        return y;
    }
    double getZ(){
        return z;
    }
    
    // 点积
    double operator*(tri_Vec obj) { return x * obj.x + y * obj.y + z * obj.z; }

    tri_Vec operator*(double p) { return tri_Vec(x * p, y * p, z * p); }
    tri_Vec operator/(double p) { return tri_Vec(x / p, y / p, z / p); }
    tri_Vec operator-() { return tri_Vec(-x, -y, -z); }
    tri_Vec operator-(tri_Vec obj) { return tri_Vec(x - obj.x, y - obj.y, z - obj.z); }
    tri_Vec operator+(tri_Vec obj) { return tri_Vec(x + obj.x, y + obj.y, z + obj.z); }

    void update(double newx, double newy, double newz){
        x = newx;
        y = newy;
        z = newz;
    }

    double len() { return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); }

    //归一化
    tri_Vec normalized() { return 
        tri_Vec((*this).x, (*this).y, (*this).z) 
        / 
        (*this).len();  
    }

    void print_vec(){
        cout << "(" << x << ", " << y << ", " << z << ") " << endl;
    }
};