#include "GTExp.h"
#include "../DataType.h"
#include "../TypeError.h"
#include <string>

std::string GTExp::genCode() {
    return "(" + exp1->genCode() + ">" + exp2->genCode() + ")";
}
std::string GTExp::printNode() {
    return "GT (" + exp1->printNode() + ", " + exp2->printNode() + ')';
}
void GTExp::inferType() {
    DataType::DataType expt1 = exp1->type;
    DataType::DataType expt2 = exp2->type;

    if (expt1 == DataType::NUMBER && expt2 == DataType::NUMBER) {
        type = DataType::BOOLEAN;
        return;
    }
    TypeError::terminate("Cannot GT " + DataType::dataTypeStrings[exp1->type] + " and " + DataType::dataTypeStrings[exp2->type] + " together!");

}
