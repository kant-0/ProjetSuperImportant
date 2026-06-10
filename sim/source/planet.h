#ifndef PLANET_H
#define PLANET_H

#include "vector.h"

typedef struct _planet {
    Vec3 position;
    Vec3 speed;
    int time;
    struct _planet *next;
} planet;

planet* newPlanet();

void pushElement(planet **my_element, Vec3 newPosition, Vec3 newSpeed);

#endif