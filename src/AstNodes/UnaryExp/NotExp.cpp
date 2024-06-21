#include "NotExp.h"
#include "../DataType.h"
#include "../TypeError.h"

#include <string>

std::string NotExp::genCode() {
    return "(!" + exp1->genCode() + ")";
}

std::string NotExp::printNode() {
    return "NOT (" + exp1->printNode() + ')';
}

void NotExp::inferType() {
    DataType::DataType expt1= exp1->type;
    if (expt1 != DataType::BOOLEAN) TypeError::terminate("Cannot NOT " + DataType::dataTypeStrings[expt1] + "instead!");
    type = DataType::BOOLEAN;
}