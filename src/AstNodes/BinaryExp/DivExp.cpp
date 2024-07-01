#include "DivExp.h"
#include "../DataType.h"
#include "../TypeError.h"
#include <string>

std::string DivExp::genCode() {
    return "(" + exp1->genCode() + "/" + exp2->genCode() + ")";
}

std::string DivExp::printNode() {
    return "DIV (" + exp1->printNode() + ", " + exp2->printNode() + ')';
}

void DivExp::inferType() {
    DataType::DataType expt1 = exp1->type;
    DataType::DataType expt2 = exp2->type;

    if (expt1 == DataType::NUMBER && expt2 == DataType::NUMBER) {
        type = DataType::NUMBER;
        return;
    }
    TypeError::terminate("Cannot DIV " + DataType::dataTypeStrings[exp1->type] + " and " + DataType::dataTypeStrings[exp2->type] + " together!");

}
