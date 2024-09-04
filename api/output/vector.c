#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 


#include "vector.h"


#define DEFINE_APPEND_FUNC(datatype, function_name, type_enum)       \
    Vector* function_name(datatype value, Vector *vector) {        \
        if ((vector)->size == (vector)->capacity) {                \
            resizeVector(vector);                                  \
        }                                                        \
        vector->elements[vector->size].data = malloc(sizeof(datatype));\
        *((datatype*)vector->elements[vector->size].data) = value;     \
        vector->elements[vector->size].type = type_enum;           \
        vector->size++;                                           \
        return vector;                                            \
    }


Vector* initVector(size_t initialCapacity) {
    Vector *vector = (Vector*)malloc(sizeof(Vector));
    vector->elements = (Element*)malloc(initialCapacity * sizeof(Element));
    vector->size = 0;
    vector->capacity = initialCapacity;
    return vector;
}


void resizeVector(Vector *vector) {
    vector->capacity *= 2;
    vector->elements = (Element*)realloc(vector->elements, vector->capacity * sizeof(Element));
}

void freeVector(Vector *vector) {
    for (size_t i = 0; i < vector->size; i++) {
        free(vector->elements[i].data);
    }
    free(vector->elements);
    free(vector);
}


DEFINE_APPEND_FUNC(int, appendInt, INT)
DEFINE_APPEND_FUNC(float, appendFloat, FLOAT)
DEFINE_APPEND_FUNC(bool, appendBool, BOOLEAN)


