
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
    JsonSet* temp = NULL;
    if (!temp) {
        *set = new;
        return;
    }
    while (temp->next) temp = temp->next;
    temp->next = new;
}
void appendToJsonArray(JsonArray** array, JsonObject* value) {
    JsonArray* new = malloc(sizeof(JsonSet));
    new->value = value;
    JsonArray* temp = NULL;
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

void appendPlanetToJson(JsonSet* json, int method, Planet* p) {

    // method 1: euler
    // method 2: runge-kutta
    // method 3: asymetric-euler

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

    Vec3* current_pos;
    Vec3* current_speed;
    int current_time;

    // first find the method used and if not defined yet, create it
    JsonSet* temp = json;
    JsonSet* methodSet = NULL;
    for (; temp->next; temp = temp->next) {
        if (!strcmp(m, temp->key)) {
            methodSet = temp->value->Set;
        }
    }
    JsonObject* planetArrayObj = newJsonObject(ARRAY, 0, 0, NULL, NULL);
    if (!methodSet) {
        appendToJsonSet(&json, m, planetArrayObj);
    }
    
    for (; p->next; p = p->next) {
        current_pos = p->position;
        current_speed = p->speed;
        current_time = p->time;

        JsonArray* pos_array;
        JsonArray* speed_array;

        appendToJsonArray(&pos_array, newJsonObject(DOUBLE, 0, current_pos->x, NULL, NULL));
        appendToJsonArray(&pos_array, newJsonObject(DOUBLE, 0, current_pos->y, NULL, NULL));
        appendToJsonArray(&pos_array, newJsonObject(DOUBLE, 0, current_pos->z, NULL, NULL));

        appendToJsonArray(&speed_array, newJsonObject(DOUBLE, 0, current_pos->x, NULL, NULL));
        appendToJsonArray(&speed_array, newJsonObject(DOUBLE, 0, current_pos->y, NULL, NULL));
        appendToJsonArray(&speed_array, newJsonObject(DOUBLE, 0, current_pos->z, NULL, NULL));

        JsonArray* triplet;

        appendToJsonArray(&triplet, newJsonObject(ARRAY, 0, 0, pos_array, NULL));
        appendToJsonArray(&triplet, newJsonObject(ARRAY, 0, 0, speed_array, NULL));
        appendToJsonArray(&triplet, newJsonObject(INT, current_time, 0, NULL, NULL));

        appendToJsonArray(&(planetArrayObj->Array), newJsonObject(ARRAY, 0, 0, triplet, NULL));
    }
}



void print_json_set(FILE* out, JsonSet* set, int indent_level) {
    // note : out must be writeable !!!
    fprintf(out, "{\n");

    while (set->next) {
        JsonObject* v = set->value;

        for (int i = 0; i < indent_level * 4; i++) fprintf(out, " ");
        fprintf(out, "\"%s\": ", set->key);

        switch (v->type) {
            case INT:
                fprintf(out, "%d", v->Int);
                fprintf(out, "%s\n", (set->next) ? ",": "");
                break;
            case DOUBLE:
                fprintf(out, "%le", v->Double);
                fprintf(out, "%s\n", (set->next) ? ",": "");
            case ARRAY:
                print_json_array(out, v->Array, indent_level +1);
                fprintf(out, "%s\n", (set->next) ? ",": "");
            case SET:
                print_json_set(out, v->Set, indent_level +1);
                fprintf(out, "%s\n", (set->next) ? ",": "");
        }

        set = set->next;
    }


    for (int i = 0; i < indent_level * 4; i++) fprintf(out, " ");
    fprintf(out, "}\n");
}

void print_json_array(FILE* out, JsonArray* array, int indent_level) {
    // note : out must be writeable !!!
    fprintf(out, "[\n");

    while (array->next) {
        JsonObject* v = array->value;

        switch (v->type) {
            case INT:
                fprintf(out, "%d", v->Int);
                fprintf(out, "%s\n", (array->next) ? ",": "");
                break;
            case DOUBLE:
                fprintf(out, "%le", v->Double);
                fprintf(out, "%s\n", (array->next) ? ",": "");
            case ARRAY:
                print_json_array(out, v->Array, indent_level +1);
                fprintf(out, "%s\n", (array->next) ? ",": "");
            case SET:
                print_json_set(out, v->Set, indent_level +1);
                fprintf(out, "%s\n", (array->next) ? ",": "");
        }

        array = array->next;
    }


    for (int i = 0; i < indent_level * 4; i++) fprintf(out, " ");
    fprintf(out, "]\n");
}