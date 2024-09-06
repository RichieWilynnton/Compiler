#include "FreePtr.h"

#include <string>

std::string FreePtr::genCode() {
    switch(type) {
        case DataType::ARRAY:
            return "freeVector(" + variable + ")";
        case DataType::LAMBDA:
             return "freeEnv(" + variable + ", " 
                + "(sizeof(" + variable + ") ? sizeof(" + variable + ") / sizeof(" + variable + "[0]) : 0))";
        default:
            return "";
    }
}

std::string FreePtr::printNode() {
    return "";
}