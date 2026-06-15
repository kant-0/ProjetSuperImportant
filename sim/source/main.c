#include <stdio.h>

#include "planet.h"
#include "vector.h"
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
        newVec3(0.0, 47362.0, 0.0),
        newVec3(0.0, 35025.0, 0.0),
        newVec3(0.0, 29783.0, 0.0),
        newVec3(0.0, 24080.0, 0.0),
        newVec3(0.0, 13058.0, 0.0),
        newVec3(0.0, 9640.0, 0.0),
        newVec3(0.0, 6796.0, 0.0),
        newVec3(0.0, 5432.0, 0.0),
        newVec3(0.0, 4740.0, 0.0)
    };
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 3; j++) {
            Planet* p = newPlanet(
                pos0[i],
                speed0[i],
                planets[i]
            );
            for (int k = 0; k < N_ITERATIONS; k++) pushNextPlanetIteration(p, j+1);
            appendPlanetToJson(&json, j+1, p);
        }
    }
    FILE* f = fopen("data.json", "w");

    if (!f) return 1;

    print_json_set(f, json);

    fclose(f);
    return 0;
}