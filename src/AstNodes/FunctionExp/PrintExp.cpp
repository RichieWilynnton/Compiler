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

std::unique_ptr<Exp> PrintExp::clone() {
    std::unique_ptr<Exp> clone1 = exp->clone();
    return std::make_unique<PrintExp>(clone1);
}