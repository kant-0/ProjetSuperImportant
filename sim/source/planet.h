#ifndef PLANET_H
#define PLANET_H

#include "vector.h"

typedef struct planet_ {
    char * name;
    Vec3* position;
    Vec3* speed;
    int time;
    struct planet_* next;
} Planet;

Planet * newPlanet(Vec3* pos0, Vec3* speed0);

void pushElement(Planet **my_element, Vec3* newPosition, Vec3* newSpeed);

#endif