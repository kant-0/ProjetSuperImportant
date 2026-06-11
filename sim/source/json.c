
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
        pos = trajectory->pos
        fprintf(out, "[[%e, %e, %e]]",
    }



    fprintf(out, "}");
}