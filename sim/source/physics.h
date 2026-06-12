#ifndef MATH_H
#define MATH_H

#include "vector.h"

double acceleration(double radius);

Vec3* radius(Vec3* pos1, Vec3* pos2);

Vec3* getAccelerationVec3(Vec3* pos);
Vec3* getNextSpeedVec3(Vec3* prevSpeed, Vec3* prevAccel);
Vec3* getNextPosVec3(Vec3* prevPos, Vec3* prevSpeed);

#endif