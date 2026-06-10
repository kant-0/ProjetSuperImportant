#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "physics.h"

double acceleration(double radius) {
    double G = 6.6743e-11;
    double m_Sun = 1.989e30;
    return -(G*m_Sun)/(radius*radius);
}

Vec3 radius(Vec3 pos1, Vec3 pos2) {
    Vec3 * r = malloc(sizeof(Vec3));
    r = addVec3(Vec3* pos2, scaleVec3(Vec3* pos1, double -1.0)); // B - A
    return r;
}