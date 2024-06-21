#include "AndExp.h"
#include "../DataType.h"
#include "../TypeError.h"
#include <string>

std::string AndExp::genCode() {
    return "(" + exp1->genCode() + "&&" + exp2->genCode() + ")";
}
std::string AndExp::printNode() {
    return "AND (" + exp1->printNode() + ", " + exp2->printNode() + ')';
}
void AndExp::inferType() {
    DataType::DataType expt1 = exp1->type;
    DataType::DataType expt2 = exp2->type;

    if (expt1 == DataType::BOOLEAN && expt2 == DataType::BOOLEAN) {
        type = DataType::BOOLEAN;
        return;
    }
    DataType::DataType wrong = expt1 != DataType::BOOLEAN ? expt1 : expt2;
        TypeError::terminate("Cannot AND boolean and " + DataType::dataTypeStrings[wrong] + " together!");

}
