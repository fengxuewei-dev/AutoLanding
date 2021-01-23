// #ifndef _FIXED_WING_MATHLIB_HPP_
// #define _FIXED_WING_MATHLIB_HPP_
#pragma once
#include <math.h>

class _FIXED_WING_MATHLIB
{
private:
public:
    void quaternion_2_euler(float quat[4], float angle[3]); //四元数转欧拉角
    void euler_2_quaternion(float angle[3], float quat[4]);
};
