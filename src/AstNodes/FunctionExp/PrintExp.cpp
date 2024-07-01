#include "PrintExp.h"
#include "../DataType.h"

#include <string>

std::string PrintExp::genCode() {
    std::string format;
    switch (exp->type)
    {
    case DataType::STRING:
        format = "%s";
        break;
    case DataType::NUMBER:
        format = "%d";
    }
    
    // surround in parentheses
    format = '"' + format + '"';
    return "printf(" + format + ", " + exp->genCode() + ")";
}

std::string PrintExp::printNode() {
    return "PRINT ("  + exp->genCode() + ")";
}

void PrintExp::inferType() {
    type = DataType::VOID;
}
