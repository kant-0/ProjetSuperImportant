#ifndef VECTOR_H
#define VECTOR_H

typedef struct vec3_t {
    double x, y, z;
} Vec3;

Vec3* newVec3(double x, double y, double z);
Vec3* addVec3(Vec3* a, Vec3* b);
Vec3* scaleVec3(Vec3* vec, double scalar);
double normVec3(Vec3* vec);
Vec3* makeUnit(double x, double y, double z);

#endif
