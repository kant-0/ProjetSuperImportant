#ifndef FORMULA_H
#define FORMULA_H

double acceleration(double radius);

Vec3* radius(Vec3* pos1, Vec3* pos2);

Vec3* getAccelerationVec3(Vec3* pos);

Vec3* getNextSpeedVec3(Vec3* prevSpeed, Vec3* prevAccel);

Vec3* getNextPosVec3(Vec3* prevPos, Vec3* prevSpeed);

Vec3 * eulerMethodSpeed(Vec3 * F, Vec3 * f, double deltaT);

Vec3 * eulerMethodPosition(planet * trajectory, double deltaT);

Vec3 * eulerAsymetricSpeed(planet * trajectory, double deltaT);

Vec3 * eulerAsymetricPosition(planet * trajectory, double deltaT):

Vec3 * rungeKuttaSpeed(planet * trajectory, double deltaT);

Vec3 * rungeKuttaPosition(planet * trajectory, double deltaT);

double potentialEnergy(planet * trajectory);

double kineticEnergy(planet * trajectory, );

#endif