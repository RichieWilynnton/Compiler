#include "NegExp.h"
#include "../DataType.h"
#include "../TypeError.h"

#include <string>

std::string NegExp::genCode() {
    return "-" + exp1->genCode();
}

std::string NegExp::printNode() {
    return "NEG (" + exp1->printNode() + ')';
}

void NegExp::inferType() {
    DataType::DataType expt1= exp1->type;
    if (expt1 != DataType::NUMBER) TypeError::terminate("Expected a number, got " + DataType::dataTypeStrings[expt1] + "instead!");
    type = DataType::NUMBER;
}