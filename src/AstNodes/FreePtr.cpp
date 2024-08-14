#include "FreePtr.h"

#include <string>

std::string FreePtr::genCode() {
    return freeFunctions.find(type) == freeFunctions.end() ? "" : (freeFunctions[type] + "(" + variable + ")");
}

std::string FreePtr::printNode() {
    return "";
}