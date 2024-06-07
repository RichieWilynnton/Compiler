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
    DataType expt1 = exp1->type;
    DataType expt2 = exp1->type;

    if (expt1 == NUMBER && expt2 == NUMBER) {
        type = NUMBER;
        return;
    }
    DataType wrong = expt1 != NUMBER ? expt1 : expt2;
    TypeError::terminate("Expected a number, got " + dataTypeStrings[wrong] + " instead!");
}
