#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "physics.h"

#define CUBED(x) ((x)*(x)*(x))

double acceleration(double radius) {
    double G = 6.6743e-11;
    double m_Sun = 1.989e30;
    return -(G*m_Sun)/(radius*radius);
}

Vec3* radius(Vec3* pos1, Vec3* pos2) {
    Vec3 * r = malloc(sizeof(Vec3));
    r = addVec3(pos2, scaleVec3(pos1, -1.0)); // B - A
    return r;
}

Vec3* getAccelerationVec3(Vec3* pos) {
    const double G = 6.6743e-11;
    const double m_S = 1.989e30;
    const double dist = normVec3(pos);
    const double accel_value = -(G*m_S)/(CUBED(dist));
    Vec3* accel = scaleVec3(pos, accel_value);

    return accel;
}

Vec3* getNextSpeedVec3(Vec3* prevSpeed, Vec3* prevAccel) {
    return addVec3(prevSpeed, prevAccel);
}

Vec3* getNextPosVec3(Vec3* prevPos, Vec3* prevSpeed) {
    return addVec3(prevPos, prevSpeed);
}
