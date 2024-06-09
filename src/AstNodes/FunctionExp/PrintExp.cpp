#include "PrintExp.h"
#include "../DataType.h"

#include <string>

std::string PrintExp::genCode() {
    return "printf(" + exp->genCode() + ")";
}

std::string PrintExp::printNode() {
    return "PRINT ("  + exp->genCode() + ")";
}

void PrintExp::inferType() {
    type = DataType::VOID;
}
