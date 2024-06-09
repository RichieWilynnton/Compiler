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
    };
    extern const std::vector<std::string> dataTypeStrings;
}

