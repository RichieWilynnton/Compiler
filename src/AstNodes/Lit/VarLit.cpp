#include "VarLit.h"

#include <string>

VarLit::VarLit(std::string name = "") : name(name) {
    inferType();
}


std::string VarLit::genCode() {
    return name;
}

std::string VarLit::printNode() {
    return "VarLit " + name;
}

void VarLit::inferType() {
    type = UNKNOWN;
}