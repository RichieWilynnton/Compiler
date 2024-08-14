#include "PrintExp.h"
#include "../DataType.h"

#include <unordered_map>
#include <string>

std::string PrintExp::genCode() {
    return printFunctions[exp->type] + "(" + exp->genCode() + ");\nprint_newline()"; 
}

std::string PrintExp::printNode() {
    return "PRINT ("  + exp->genCode() + ")";
}

void PrintExp::inferType() {
    type = DataType::VOID;
}
