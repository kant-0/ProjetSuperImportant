#include <stdio.h>
#include <stdlib.h>

#include "planet.h"
#include "vector.h"

planet * newSun() {
    planet* sun = malloc(sizeof(planet));
    sun->position = newVec3(0.0, 0.0, 0.0);
    sun->speed = newVec3(0.0, 0.0, 0.0);
    sun->time = 0;
    
    sun->next = NULL;
    return 
}

void pushElement(planet **previousPlanet, Vec3 newPosition, Vec3 newSpeed) {
    planet* newPlanet = malloc(sizeof(planet));
    newPlanet->position = newPosition;
    newPlanet->speed = newSpeed;
    newPlanet->time = (*previousPlanet)->time + 1;
    
    previousPlanet->next = newPlanet;
    return
}