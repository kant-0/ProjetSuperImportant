#include <stdlib.h>

#include "planet.h"
#include "vector.h"
#include "formula.h"

Planet * newPlanet(Vec3* pos0, Vec3* speed0, char* name) { // création d'une nouvelle
    Planet* planet = malloc(sizeof(Planet));
    planet->name = name;
    planet->position = pos0;
    planet->speed = speed0;
    planet->time = 0;
    
    planet->next = NULL;
    return planet;
}

void pushNextPlanetIteration(Planet* p, int method) { // ajoute le point suivant d'une planète dans sa trajectoire
    // method 1 : euler
    // method 2 : runge-kutta
    // method 3 : asymetric euler
    
    while (p->next) p = p->next; // go to end of linked list
    
    const double deltaT = 86400;

    Vec3* newSpeed = NULL;
    Vec3* newPosition = NULL;
    switch (method) { // en fonction de la méthode de calcul utilisé
        case 1:
            newSpeed = eulerMethodSpeed(p, deltaT);
            newPosition = eulerMethodPosition(p, deltaT);
            break;
        case 2:
            newSpeed = rungeKuttaSpeed(p, deltaT);
            newPosition = rungeKuttaPosition(p, deltaT);
            break;
        case 3:
            newSpeed = eulerAsymetricSpeed(p, deltaT);
            newPosition = eulerAsymetricPosition(p, deltaT);
    }
    
    p->next = newPlanet(newPosition, newSpeed, p->name);
    p->next->time = p->time + 1;
}