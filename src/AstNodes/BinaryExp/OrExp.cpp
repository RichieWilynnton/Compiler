#include "OrExp.h"
#include "../DataType.h"
#include "../TypeError.h"
#include <string>

std::string OrExp::genCode() {
    return "(" + exp1->genCode() + "&&" + exp2->genCode() + ")";
}
std::string OrExp::printNode() {
    return "AND (" + exp1->printNode() + ", " + exp2->printNode() + ')';
}
void OrExp::inferType() {
    DataType::DataType expt1 = exp1->type;
    DataType::DataType expt2 = exp2->type;

    if (expt1 == DataType::BOOLEAN && expt2 == DataType::BOOLEAN) {
        type = DataType::BOOLEAN;
        return;
    }
    TypeError::terminate("Cannot OR " + DataType::dataTypeStrings[exp1->type] + " and " + DataType::dataTypeStrings[exp2->type] + " together!");

}
