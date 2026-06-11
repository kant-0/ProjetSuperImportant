#include <stdio.h>
#include <stdlib.h>

#include "planet.h"
#include "vector.h"

planet * newPlanet(Vec3 pos0, Vec3 speed0) {
    planet* planet = malloc(sizeof(planet));
    planet->position = pos0;
    planet->speed = speed0;
    planet->time = 0;
    
    planet->next = NULL;
    return planet;
}

void pushElement(planet **previousPlanet, Vec3* newPosition, Vec3* newSpeed) {
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
            normalize(pos2),
            acceleration(radius(origin(), pos2))
        )
    );
    newPlanet->time = (*previousPlanet)->time + 1;

    newPlanet->name = (*previousPlanet)->name;
    
    previousPlanet->next = newPlanet;
}