#include "MultExp.h"
#include "../DataType.h"
#include "../TypeError.h"
#include <string>

std::string MultExp::genCode() {
    return exp1->genCode() + "*" + exp2->genCode();
}
std::string MultExp::printNode() {
    return "MULT (" + exp1->printNode() + ", " + exp2->printNode() + ')';
}
void MultExp::inferType() {
    DataType::DataType expt1 = exp1->type;
    DataType::DataType expt2 = exp2->type;

    if (expt1 == DataType::NUMBER && expt2 == DataType::NUMBER) {
        type = DataType::NUMBER;
        return;
    }
    DataType::DataType wrong = expt1 != DataType::NUMBER ? expt1 : expt2;
    TypeError::terminate("Expected a number, got " + DataType::dataTypeStrings[wrong] + " instead!");
}
