#include <stdio.h>

#include "planet.h"
#include "vector.h"
#include "formula.h"
#include "json.h"

#define N_ITERATIONS 2000

int main() {
    JsonSet* json = NULL;

    char* planets[] = {"mercure", "venus", "terre", "mars", "jupiter", "saturne", "uranus", "neptune", "pluton"};
    Vec3* pos0[] = {
        newVec3(46001200.0e3, 0.0, 0.0),
        newVec3(107476000.0e3, 0.0, 0.0),
        newVec3(147098074.0e3, 0.0, 0.0),
        newVec3(206655000.0e3, 0.0, 0.0),
        newVec3(740680000.0e3, 0.0, 0.0),
        newVec3(1349800000.0e3, 0.0, 0.0),
        newVec3(2735000000.0e3, 0.0, 0.0),
        newVec3(4459800000.0e3, 0.0, 0.0),
        newVec3(4436824613.0e3, 0.0, 0.0)
    };
    Vec3* speed0[] = {
        
    };
    
    
    Planet * mercure_e = newPlanet(
        newVec3(46001200.0e3, 0.0, 0.0),
        newVec3(0.0, 47362.0, 0.0), "mercure");
    for (int i = 0; i < N_ITERATIONS; i++) pushNextPlanetIteration(mercure_e, 1);
    Planet * mercure_rk = newPlanet(
        newVec3(46001200.0e3, 0.0, 0.0),
        newVec3(0.0, 47362.0, 0.0), "mercure");
    for (int i = 0; i < N_ITERATIONS; i++) pushNextPlanetIteration(mercure_rk, 2);
    Planet * mercure_ae = newPlanet(
        newVec3(46001200.0e3, 0.0, 0.0),
        newVec3(0.0, 47362.0, 0.0), "mercure");
    for (int i = 0; i < N_ITERATIONS; i++) pushNextPlanetIteration(mercure_ae, 3);
    appendPlanetToJson(&json, 1, mercure_e);
    appendPlanetToJson(&json, 2, mercure_rk);
    appendPlanetToJson(&json, 3, mercure_ae);
    
    Planet * venus_e = newPlanet(
        newVec3(107476000.0e3, 0.0, 0.0), 
        newVec3(0.0, 35025.0, 0.0), "venus");
    for (int i = 0; i < N_ITERATIONS; i++) pushNextPlanetIteration(venus_e, 1);
    Planet * venus_rk = newPlanet(
        newVec3(107476000.0e3, 0.0, 0.0), 
        newVec3(0.0, 35025.0, 0.0), "venus");
    for (int i = 0; i < N_ITERATIONS; i++) pushNextPlanetIteration(venus_rk, 2);
    Planet * venus_ae = newPlanet(
        newVec3(107476000.0e3, 0.0, 0.0), 
        newVec3(0.0, 35025.0, 0.0), "venus");
    for (int i = 0; i < N_ITERATIONS; i++) pushNextPlanetIteration(venus_ae, 3);
    appendPlanetToJson(&json, 1, venus_e);
    appendPlanetToJson(&json, 2, venus_rk);
    appendPlanetToJson(&json, 3, venus_ae);

    
    Planet * terre_e = newPlanet(
        newVec3(147098074.0e3, 0.0, 0.0), 
        newVec3(0.0, 29783.0, 0.0), "terre");
    for (int i = 0; i < N_ITERATIONS; i++) pushNextPlanetIteration(terre_e, 1);
    Planet * terre_rk = newPlanet(
        newVec3(147098074.0e3, 0.0, 0.0), 
        newVec3(0.0, 29783.0, 0.0), "terre");
    for (int i = 0; i < N_ITERATIONS; i++) pushNextPlanetIteration(terre_rk, 2);
    Planet * terre_ae = newPlanet(
        newVec3(147098074.0e3, 0.0, 0.0), 
        newVec3(0.0, 29783.0, 0.0), "terre");
    for (int i = 0; i < N_ITERATIONS; i++) pushNextPlanetIteration(terre_ae, 3);
    appendPlanetToJson(&json, 1, terre_e);
    appendPlanetToJson(&json, 2, terre_rk);
    appendPlanetToJson(&json, 3, terre_ae);
    
    Planet * mars = newPlanet(
        newVec3(206655000.0e3, 0.0, 0.0), 
        newVec3(0.0, 24080.0, 0.0), "mars");
    Planet * jupiter = newPlanet(
        newVec3(740680000.0e3, 0.0, 0.0), 
        newVec3(0.0, 13058.0, 0.0), "jupiter");
    Planet * saturne = newPlanet(
        newVec3(1349800000.0e3, 0.0, 0.0), 
        newVec3(0.0, 9640.0, 0.0), "saturne");
    Planet * uranus = newPlanet(
        newVec3(2735000000.0e3, 0.0, 0.0), 
        newVec3(0.0, 6796.0, 0.0), "uranus");
    Planet * neptune = newPlanet(
        newVec3(4459800000.0e3, 0.0, 0.0), 
        newVec3(0.0, 5432.0, 0.0), "neptune");
    Planet * pluton = newPlanet(
        newVec3(4436824613.0e3, 0.0, 0.0), 
        newVec3(0.0, 4740.0, 0.0), "pluton");

    return 0;
}