#pragma once

#include "data.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 

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
DECLARE_APPEND_FUNC(bool, appendBool)
