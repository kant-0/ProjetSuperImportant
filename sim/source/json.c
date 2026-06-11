
#include <stdio.h>
#include <stdlib.h>

#include "json.h"
#include "vector.h"
#include "planet.h"


void write_json(FILE* out, planet * trajectory) {
    if (!out) {
        fprintf(stderr, "Impossible d'ouvrir le fichier");
        return;
    }
    fprintf(out, "{\"%s\" : [", trajectory->name);
    while (1) {
        if (!trajectory) // et si tu n'existais pas... dis moi comment j'existerais ?
            break;

<<<<<<< HEAD
        pos = trajectory->pos;
        speed = trajectory->speed;
        fprintf(out, "[[%e, %e, %e], [%e, %e, %e], %d]", pos->x, pos->y, pos->z, speed->x, speed->y, speed->z, trajectory->time);
=======
        Vec3* pos = trajectory->position;
        Vec3* speed = trajectory->speed;
        fprintf(out, "[[%e, %e, %e], [%e, %e, %e], %d],\n", pos->x, pos->y, pos->z, speed->x, speed->y, speed->z, trajectory->time);
>>>>>>> 533552c04863035ebdf7c2c698f7a2da569762f2

        trajectory = trajectory->next;
    }



    fprintf(out, "]}");
}