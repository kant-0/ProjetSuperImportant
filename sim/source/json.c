
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "json.h"
#include "vector.h"
#include "planet.h"

char* euler = "method-euler";
char* rk = "method-runge-kutta";
char* asym_euler = "method-asymetric-euler";

void write_json(FILE* out, Planet * trajectory) {
    if (!out) {
        fprintf(stderr, "Impossible d'ouvrir le fichier");
        return;
    }
    fprintf(out, "{\"%s\" : ", trajectory->name);
    while (1) {
        if (!trajectory) // et si tu n'existais pas... dis moi comment j'existerais ?
            break;

        Vec3* pos = trajectory->position;
        Vec3* speed = trajectory->speed;
        fprintf(out, "[[%e, %e, %e], [%e, %e, %e], %d],\n", pos->x, pos->y, pos->z, speed->x, speed->y, speed->z, trajectory->time);

        trajectory = trajectory->next;
    }



    fprintf(out, "}");
}

void appendToJsonSet(JsonSet** set, char* key, JsonObject* value) {
    JsonSet* new = malloc(sizeof(JsonSet));
    new->key = key;
    new->value = value;
    new->next = NULL;
    JsonSet* temp = *set;
    if (!temp) {
        *set = new;
        return;
    }
    while (temp->next) temp = temp->next;
    temp->next = new;
}
void appendToJsonArray(JsonArray** array, JsonObject* value) {
    JsonArray* new = malloc(sizeof(JsonArray));
    new->value = value;
    new->next = NULL;
    JsonArray* temp = *array;
    if (!temp) {
        *array = new;
        return;
    }
    while (temp->next) temp = temp->next;
    temp->next = new;
}
JsonObject* newJsonObject(
    JsonObjType type,
    int i,
    double d,
    JsonArray* arr,
    JsonSet* set
) {
    JsonObject* obj = malloc(sizeof(JsonObject));
    obj->type = type;

    switch (type) {
        case INT:
            obj->Int = i;
            break;
        case DOUBLE:
            obj->Double = d;
            break;
        case ARRAY:
            obj->Array = arr;
            break;
        case SET:
            obj->Set = set;
            break;
        default: // error handling
            break;
    };
    return obj;
}



void print_json_set(FILE* out, JsonSet* set) {
    // note : out must be writeable !!!
    fprintf(out, "{");

    while (set) {
        JsonObject* v = set->value;
        fprintf(out, "\"%s\": ", set->key);

        switch (v->type) {
            case INT:
                fprintf(out, "%d", v->Int);
                fprintf(out, "%s", (set->next) ? ",": "");
                break;
            case DOUBLE:
                fprintf(out, "%le", v->Double);
                fprintf(out, "%s", (set->next) ? ",": "");
                break;
            case ARRAY:
                print_json_array(out, v->Array);
                fprintf(out, "%s", (set->next) ? ",": "");
                break;
            case SET:
                print_json_set(out, v->Set);
                fprintf(out, "%s", (set->next) ? ",": "");
        }

        set = set->next;
    }
    fprintf(out, "}");
}

void print_json_array(FILE* out, JsonArray* array) {
    // note : out must be writeable !!!
    fprintf(out, "[");

    while (array) {
        JsonObject* v = array->value;

        switch (v->type) {
            case INT:
                fprintf(out, "%d", v->Int);
                fprintf(out, "%s", (array->next) ? ",": "");
                break;
            case DOUBLE:
                fprintf(out, "%le", v->Double);
                fprintf(out, "%s", (array->next) ? ",": "");
                break;
            case ARRAY:
                print_json_array(out, v->Array);
                fprintf(out, "%s", (array->next) ? ",": "");
                break;
            case SET:
                print_json_set(out, v->Set);
                fprintf(out, "%s", (array->next) ? ",": "");
        }

        array = array->next;
    }
    fprintf(out, "]");
}

void appendPlanetToJson(JsonSet** json, int method, Planet* p) {

    char* name = p->name;
    JsonArray* planetArray = NULL;
    while (p) {

        Vec3* pos = p->position;
        Vec3* speed = p->speed;
        int time = p->time;

        JsonArray* posArray = NULL;
        JsonArray* speedArray = NULL;
        JsonArray* triplet = NULL;

        appendToJsonArray(&posArray, newJsonObject(DOUBLE, 0, pos->x, NULL, NULL));
        appendToJsonArray(&posArray, newJsonObject(DOUBLE, 0, pos->y, NULL, NULL));
        appendToJsonArray(&posArray, newJsonObject(DOUBLE, 0, pos->z, NULL, NULL));

        appendToJsonArray(&speedArray, newJsonObject(DOUBLE, 0, speed->x, NULL, NULL));
        appendToJsonArray(&speedArray, newJsonObject(DOUBLE, 0, speed->y, NULL, NULL));
        appendToJsonArray(&speedArray, newJsonObject(DOUBLE, 0, speed->z, NULL, NULL));

        appendToJsonArray(&triplet, newJsonObject(ARRAY, 0, 0, posArray, NULL));
        appendToJsonArray(&triplet, newJsonObject(ARRAY, 0, 0, speedArray, NULL));
        appendToJsonArray(&triplet, newJsonObject(INT, time, 0, NULL, NULL));

        appendToJsonArray(&planetArray, newJsonObject(ARRAY, 0, 0, triplet, NULL));

        p = p->next;
    }

    char* m = NULL;

    switch (method) {
        case 1:
            m = euler;
            break;
        case 2:
            m = rk;
            break;
        case 3:
            m = asym_euler;
    }

    if (!m) return;

    if (!*json) {
        JsonSet* s = NULL;
        appendToJsonSet(&s, name, newJsonObject(ARRAY, 0, 0, planetArray, NULL));
        appendToJsonSet(json, m, newJsonObject(SET, 0, 0, NULL, s));
        return;
    }
    JsonSet* s = *json;
    JsonSet* methodSet = NULL;
    while (s) {

        if (!strcmp(m, s->key)) {
            methodSet = s->value->Set;
        }

        s = s->next;
    }
    if (!methodSet) {
        appendToJsonSet(&methodSet, name, newJsonObject(ARRAY, 0, 0, planetArray, NULL));
        appendToJsonSet(json, m, newJsonObject(SET, 0, 0, NULL, methodSet));
        return;
    }
    appendToJsonSet(&methodSet, name, newJsonObject(ARRAY, 0, 0, planetArray, NULL));
}
