#include <stdio.h>

#include "planet.h"
#include "vector.h"
#include "physics.h"

int main() {
    planet * mercure = newPlanet(
        newVec3(46001200.0e3, 0.0, 0.0),
        newVec3(0.0, 47362.0, 0.0));
    planet * venus = newPlanet(
        newVec3(107476000.0e3, 0.0, 0.0), 
        newVec3(0.0, 35025.0, 0.0));
    planet * terre = newPlanet(
        newVec3(147098074.0e3, 0.0, 0.0), 
        newVec3(0.0, 29783.0, 0.0));
    planet * mars = newPlanet(
        newVec3(206655000.0e3, 0.0, 0.0), 
        newVec3(0.0, 24080.0, 0.0));
    planet * jupiter = newPlanet(
        newVec3(740680000.0e3, 0.0, 0.0), 
        newVec3(0.0, 13058.0, 0.0));
    planet * saturne = newPlanet(
        newVec3(1349800000.0e3, 0.0, 0.0), 
        newVec3(0.0, 9640.0, 0.0));
    planet * uranus = newPlanet(
        newVec3(2735000000.0e3, 0.0, 0.0), 
        newVec3(0.0, 6796.0, 0.0));
    planet * neptune = newPlanet(
        newVec3(4459800000.0e3, 0.0, 0.0), 
        newVec3(0.0, 5432.0, 0.0));
    planet * pluton = newPlanet(
        newVec3(4436824613.0e3, 0.0, 0.0), 
        newVec3(0.0, 4740.0, 0.0));
    return 0;
}