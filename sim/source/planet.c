#include <stdio.h>
#include <stdlib.h>

#include "planet.h"
#include "vector.h"
#include "formula.h"

Planet * newPlanet(Vec3* pos0, Vec3* speed0) {
    Planet* planet = malloc(sizeof(planet));
    planet->position = pos0;
    planet->speed = speed0;
    planet->time = 0;
    
    planet->next = NULL;
    return planet;
}

void pushNextPlanetIteration(Planet* p) {
    while (p->next) p = p->next; // go to end of linked list
    
    Vec3* prevAccel = getAccelerationVec3(p->position);
    Vec3* newSpeed = getNextSpeedVec3(p->speed, prevAccel);

    free(prevAccel);
    
    Vec3* newPosition = getNextPosVec3(p->position, p->speed);
    
    p->next = newPlanet(newPosition, newSpeed);
    p->next->time = p->time + 1;
}