
#include <stdlib.h>
#include <math.h>

#include "vector.h"

#define SQ(x) ((x)*(x))

Vec3* origin() { // vecteur nul
    Vec3* vec = malloc(sizeof(Vec3));

    vec->x = 0.0;
    vec->y = 0.0;
    vec->z = 0.0;

    return vec;
}

Vec3* newVec3(double x, double y, double z) {
    Vec3* vec = malloc(sizeof(Vec3));

    vec->x = x;
    vec->y = y;
    vec->z = z;

    return vec;
}

Vec3* addVec3(Vec3* a, Vec3* b) {
    return newVec3(a->x + b->x,a->y + b->y,a->z + b->z);
}

Vec3* scaleVec3(Vec3* vec, double scalar) {
    return newVec3(vec->x * scalar,vec->y * scalar,vec->z * scalar);
}

double normVec3(Vec3* vec) {
    return sqrt(SQ(vec->x) + SQ(vec->y) + SQ(vec->z));
}

Vec3* normalize(Vec3* pos) { // old, not used
    Vec3* new_vec = scaleVec3(pos, 1/normVec3(pos));
    return new_vec;
}
