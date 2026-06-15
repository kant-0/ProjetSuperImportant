
#ifndef JSON_H
#define JSON_H

#include "planet.h"
#include <stdio.h>


typedef struct json_object JsonObject;

// --- JSON SET ---
typedef struct json_set {
    char* key;
    JsonObject* value;

    struct json_set* next;
} JsonSet;
// --- --- ---

// --- JSON ARRAY ---
typedef struct json_array {
    JsonObject* value;

    struct json_array* next;
} JsonArray;
// --- --- ---

// --- JSON OBJECT ---
typedef enum json_obj_type {
    INT,
    DOUBLE,
    ARRAY,
    SET
} JsonObjType;

struct json_object {
    JsonObjType type;
    union {
        int Int;
        double Double;
        JsonArray* Array;
        JsonSet* Set;
    };
};
// --- --- ---

void appendPlanetToJson(JsonSet* json, int method, Planet* p);
JsonObject* newJsonObject(
    JsonObjType type, 
    int i,
    double d,
    JsonArray* arr,
    JsonSet* set
);
void print_json_array(FILE* out, JsonArray* array, int indent_level);
void print_json_set(FILE* out, JsonSet* set, int indent_level);

void write_json(FILE* out, Planet* trajectory);

#endif
