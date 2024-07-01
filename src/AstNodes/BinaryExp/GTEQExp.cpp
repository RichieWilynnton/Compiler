#include "GTEQExp.h"
#include "../DataType.h"
#include "../TypeError.h"
#include <string>

std::string GTEQExp::genCode() {
    return "(" + exp1->genCode() + ">=" + exp2->genCode() + ")";
}
std::string GTEQExp::printNode() {
    return "GTEQ (" + exp1->printNode() + ", " + exp2->printNode() + ')';
}
void GTEQExp::inferType() {
    DataType::DataType expt1 = exp1->type;
    DataType::DataType expt2 = exp2->type;

    if (expt1 == DataType::NUMBER && expt2 == DataType::NUMBER) {
        type = DataType::BOOLEAN;
        return;
    }
    TypeError::terminate("Cannot GTEQ " + DataType::dataTypeStrings[exp1->type] + " and " + DataType::dataTypeStrings[exp2->type] + " together!");

}
