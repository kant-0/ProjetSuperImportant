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
    Vec3 * pos1 = newPlanet->position;
    Vec3 * pos2 = newPosition;
    planet* newPlanet = malloc(sizeof(planet));
    
    newPlanet->position = addVec3(
        (*previousPlanet)->position, 
        (*previousPlanet)->speed
    );

    newPlanet->speed = addVec3(
        (*previousPlanet)->speed,
        scaleVec(
            makeUnit(pos2), 
            acceleration(radius(origin(), pos2))
        )
    );
    newPlanet->time = (*previousPlanet)->time + 1;
    
    previousPlanet->next = newPlanet;
    return
}