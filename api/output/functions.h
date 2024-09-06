#pragma once

#include "data.h"

#include <stdbool.h>

#define DEFINE_MAKE_ELEMENT(datatype, type_enum) \
    Element make_##datatype##_element(datatype value);

DEFINE_MAKE_ELEMENT(int, INT)
DEFINE_MAKE_ELEMENT(bool, BOOLEAN)

void freeEnv(Element env[], int size);

