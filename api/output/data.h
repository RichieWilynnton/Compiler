#pragma once

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
