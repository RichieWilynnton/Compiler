#pragma once
#include <string>
#include <vector>

namespace DataType {
    enum DataType {
        UNKNOWN,
        VOID,
        NUMBER,
        BOOLEAN,
        STRING,
        ARRAY,
        LAMBDA,
    };
    extern const std::vector<std::string> dataTypeStrings;
}

