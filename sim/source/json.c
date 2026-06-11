
#include <stdio.h>
#include <stdlib.h>

#include "json.h"
#include "vector.h"


void write_json(FILE* out, planet * trajectory) {
    if (!monFichier) {
        fprint("Impossible d'ouvrir le fichier");
        return;
    }
    fprintf(out, "{\"%s\" : ", trajectory->name);
    while (1) {
        if (!trajectory) // et si tu n'existais pas... dis moi comment j'existerais ?
            break;

        Vec3* pos = trajectory->pos;
        Vec3* speed = trajectory->speed;
        fprintf(out, "[[%e, %e, %e], [%e, %e, %e], %d],\n", pos->x, pos->y, pos->z, speed->x, speed->y, speed->z, trajectory->time);

        trajectory = trajectory->next;
    }



    fprintf(out, "}");
}