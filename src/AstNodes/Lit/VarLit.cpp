#include "VarLit.h"
#include "../DataType.h"
#include <string>

VarLit::VarLit(std::string name, DataType::DataType type) : name(name) {
    this->type = type;
    valKnown = false;
}


std::string VarLit::genCode() {
    return name;
}

std::string VarLit::printNode() {
    return "(VarLit " + name + ")";
}

void VarLit::inferType() {
    // alr inferred from init
}

std::unique_ptr<Exp> VarLit::clone() {
    return std::make_unique<VarLit>(this->name, this->type);
}