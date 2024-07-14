#include "VarLit.h"
#include "../DataType.h"
#include <string>

VarLit::VarLit(std::string name, DataType::DataType type) : name(name) {
    this->type = type;
    inferType();
    optimizable = false;
}


std::string VarLit::genCode() {
    return name;
}

std::string VarLit::printNode() {
    return "(VarLit " + name + ")";
}

void VarLit::inferType() {}
