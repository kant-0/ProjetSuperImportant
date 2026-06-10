#include <stdio.h>
#include <stdlib.h>

#include "planet.h"
#include "vector.h"

planet * newPlanet(Vec3 pos0, Vec3 speed0) {
    planet* planet = malloc(sizeof(planet));
    sun->position = pos0;
    sun->speed = speed0;
    sun->time = 0;
    
    sun->next = NULL;
    return planet;
}

void pushElement(planet **previousPlanet, Vec3 newPosition, Vec3 newSpeed) {
    planet* newPlanet = malloc(sizeof(planet));
    newPlanet->position = newPosition;
    newPlanet->speed = newSpeed;
    newPlanet->time = (*previousPlanet)->time + 1;
    
    previousPlanet->next = newPlanet;
    return
}