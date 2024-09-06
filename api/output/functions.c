#include "functions.h"
#include <stdlib.h>

#define DEFINE_MAKE_ELEMENT_IMPL(datatype, type_enum)       \
    Element make_##datatype##_element(datatype value) {     \
        datatype* ptr = (datatype*) malloc(sizeof(datatype));\
        *ptr = value;                                       \
        Element ret = {                                     \
            .data = ptr,                                    \
            .type = type_enum                               \
        };                                                  \
        return ret;                                         \
    }\

DEFINE_MAKE_ELEMENT_IMPL(int, INT)
DEFINE_MAKE_ELEMENT_IMPL(bool, BOOLEAN)

void freeEnv(Element env[], int size) {
    for (int i = 0; i < size; i++) {
        free(env[i].data);
    }
}
