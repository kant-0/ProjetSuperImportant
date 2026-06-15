#ifndef FORMULA_H
#define FORMULA_H

#include "vector.h"
#include "planet.h"

double acceleration(double radius);

Vec3* radius(Vec3* pos1, Vec3* pos2);

Vec3* getAccelerationVec3(Vec3* pos);

Vec3* getNextSpeedVec3(Vec3* prevSpeed, Vec3* prevAccel);

Vec3* getNextPosVec3(Vec3* prevPos, Vec3* prevSpeed);

Vec3 * eulerMethodSpeed(Planet * trajectory, double deltaT);

Vec3 * eulerMethodPosition(Planet * trajectory, double deltaT);

Vec3 * eulerAsymetricSpeed(Planet * trajectory, double deltaT);

Vec3 * eulerAsymetricPosition(Planet * trajectory, double deltaT);

Vec3 * rungeKuttaSpeed(Planet * trajectory, double deltaT);

Vec3 * rungeKuttaPosition(Planet * trajectory, double deltaT);

double potentialEnergy(Planet * trajectory);

double kineticEnergy(Planet * trajectory);

#endif