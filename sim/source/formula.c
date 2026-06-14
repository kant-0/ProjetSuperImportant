#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "physics.h"

#define CB(x) ((x)*(x)*(x))

Vec3 * acceleration(Vec3 * pos) {
    double G = 6.6743e-11;
    double m_Sun = 1.989e30;
    a_norm = -(G*m_Sun)/CB(normVec3(pos));

    return scaleVec3(pos, a_norm);
}

Vec3 * eulerMethod(Vec3 * F, Vec3 * f, double deltaT) {
    return addVec3(
        F, 
        scaleVec3(f, deltaT)
    );  // Fn+1 = Fn + fn x /\t
}

Vec3 * rungeKutta(planet * trajectory, double deltaT) {
    Vec3 * k1r = scaleVec3(trajectory->speed, deltaT);
    Vec3 * k1v = scaleVec3(acceleration(trajectory->position), deltaT);

    Vec3 * k2r = scaleVec3();
    Vec3 * k2v = scaleVec3();
}