#include <stdio.h>
#include <stdlib.h>

#include "planet.h"
#include "vector.h"

planet * newPlanet() {
    return NULL;
}

void pushElement(planet **previousPlanet, Vec3 newPosition, Vec3 newSpeed) {
    planet* newPlanet = malloc(sizeof(planet));
    newPlanet->position = newPosition;
    newPlanet->speed = newSpeed;
    newPlanet->time = (*previousPlanet)->time + 1;
    
    previousPlanet->next = newPlanet;
    return
}