#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef enum {
    INT,
    FLOAT,
    BOOLEAN,
    STRING
} DataType;

typedef struct {
    void *data;
    DataType type;
} Element;

// Structure for the vector itself
typedef struct {
    Element *elements;
    size_t capacity;
    size_t size;
} Vector;

Vector* initVector(size_t initialCapacity);

void resizeVector(Vector *vector);

void freeVector(Vector *vector);

#define DECLARE_APPEND_FUNC(datatype, function_name) \
    Vector* function_name(datatype value, Vector *vector);

DECLARE_APPEND_FUNC(int, appendInt)
DECLARE_APPEND_FUNC(float, appendFloat)
DECLARE_APPEND_FUNC(float, appendBool)
