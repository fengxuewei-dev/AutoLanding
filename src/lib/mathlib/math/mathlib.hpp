// #ifndef _MATHLIB_H_
// #define _MATHLIB_H_
#pragma once
#include <math.h>
#include <iostream>

using namespace std;
#ifndef PI
#define PI 3.1415926535
#endif

#define CONSTANTS_RADIUS_OF_EARTH 6371000
#define EARTH_RADIUS 6378137
#define CONSTANTS_ONE_G 9.80665

float constrain(float val, float min, float max);
float max(const float a, const float b);
float min(const float a, const float b);

void quaternion_2_euler(float quat[4], float angle[3]);

void euler_2_quaternion(float angle[3], float quat[4]);
void matrix_plus_vector_3(float vector_a[3], float rotmax[3][3], float vector_b[3]);

/**
	 * create rotation matrix for the quaternion
	 */
void quat_2_rotmax(float q[4], float R[3][3]);
float rad_2_deg(float rad);

float deg_2_rad(float deg);

//ref,result---lat,long,alt
void cov_m_2_lat_long_alt(double ref[3], float x, float y, float z, double result[3]);
void cov_lat_long_2_m(double a_pos[2], double b_pos[2], double m[2]);
float abs_num(float a);

// #endif