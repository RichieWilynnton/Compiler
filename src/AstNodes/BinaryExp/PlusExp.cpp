#include "PlusExp.h"
#include "../DataType.h"
#include "../TypeError.h"
#include <string>

std::string PlusExp::genCode() {
    return "(" + exp1->genCode() + "+" + exp2->genCode() + ")";
}

std::string PlusExp::printNode() {
    return "PLUS (" + exp1->printNode() + ", " + exp2->printNode() + ')';
}

void PlusExp::inferType() {
    DataType::DataType expt1 = exp1->type;
    DataType::DataType expt2 = exp2->type;

    if (expt1 == DataType::NUMBER && expt2 == DataType::NUMBER) {
        type = DataType::NUMBER;
        return;
    }
    if (expt1 == DataType::STRING && expt2 == DataType::STRING) {
        type = DataType::STRING;
        return;
    }
    TypeError::terminate("Cannot PLUS " + DataType::dataTypeStrings[exp1->type] + " and " + DataType::dataTypeStrings[exp2->type] + " together!");
}
