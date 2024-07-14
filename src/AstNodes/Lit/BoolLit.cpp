#include "BoolLit.h"

#include <string>

BoolLit::BoolLit(bool state = false) : state(state) {
    inferType();
}

std::string BoolLit::genCode() {
    return state ? "true" : "false";
}

std::string BoolLit::printNode() {
    return "(BoolLit " + (state ? std::string("true") : std::string("false")) + ')';
}

void BoolLit::inferType() { 
    type = DataType::BOOLEAN;
}
