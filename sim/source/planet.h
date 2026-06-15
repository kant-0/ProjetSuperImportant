#ifndef PLANET_H
#define PLANET_H

#include "vector.h"

typedef struct planet_ {
    char * name;
    Vec3* position;
    Vec3* speed;
    int time;
    double mass
    struct planet_* next;
} Planet;

typedef struct system_ {
    struct planet_ * planet;
    struct system_ * next;
} System;

Planet * newPlanet(Vec3* pos0, Vec3* speed0, char* name);
void pushElement(Planet **my_element, Vec3* newPosition, Vec3* newSpeed);
void pushNextPlanetIteration(Planet* p);

#endif