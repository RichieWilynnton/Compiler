#include "print.h"
#include "vector.h"
#include <stdio.h>
#include <stdbool.h>

void print_bool(bool value) {
    printf("%s", value ? "true" : "false");
}

void print_int(int value) {
    printf("%d", value);
}

void print_newline() {
    printf("\n");
}

void print_vector(Vector *vector) {
    printf("[");
    for (size_t i = 0; i < vector->size; i++) {
        switch (vector->elements[i].type) {
            case INT:
                print_int(*((int*)vector->elements[i].data));
                break;
            case BOOLEAN:
                print_bool(*((bool*)vector->elements[i].data));
                break;
            case STRING:
                // Handle string case if needed
                break;
            case FLOAT:
                // Handle float case if needed
                break;
        }

        if (i != vector->size - 1) {
            printf(", ");
        }
    }
    printf("]");
}
