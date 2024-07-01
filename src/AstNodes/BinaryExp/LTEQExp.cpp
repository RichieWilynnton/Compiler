#include "LTEQExp.h"
#include "../DataType.h"
#include "../TypeError.h"
#include <string>

std::string LTEQExp::genCode() {
    return "(" + exp1->genCode() + "<=" + exp2->genCode() + ")";
}
std::string LTEQExp::printNode() {
    return "LTEQ (" + exp1->printNode() + ", " + exp2->printNode() + ')';
}
void LTEQExp::inferType() {
    DataType::DataType expt1 = exp1->type;
    DataType::DataType expt2 = exp2->type;

    if (expt1 == DataType::NUMBER && expt2 == DataType::NUMBER) {
        type = DataType::BOOLEAN;
        return;
    }
    TypeError::terminate("Cannot LTEQ " + DataType::dataTypeStrings[exp1->type] + " and " + DataType::dataTypeStrings[exp2->type] + " together!");

}
