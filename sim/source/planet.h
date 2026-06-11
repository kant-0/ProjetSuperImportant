#ifndef PLANET_H
#define PLANET_H

#include "vector.h"

typedef struct _planet {
    char * name;
    Vec3* position;
    Vec3* speed;
    int time;
    struct _planet *next;
} planet;

planet * newPlanet(Vec3* pos0, Vec3* speed0);

void pushElement(planet **my_element, Vec3* newPosition, Vec3* newSpeed);

#endif