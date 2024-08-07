#include "Assignment.h"
#include "../TypeError.h"
#include "../DataType.h"
#include <string>

std::string Assignment::genCode()
{
    DataType::DataType type = exp->type;
    std::string prefix;
    bool putSquareBrackets = false;
    // Skip prefix 
    if (alrDeclared) return variable + " = " + exp->genCode();

    switch (type)
    {
    case DataType::NUMBER:
        prefix = "int";
        break;
    case DataType::STRING:
        prefix = "char";
        break;
    case DataType::BOOLEAN:
        prefix = "bool";
        break;
    default:
        TypeError::terminate(DataType::dataTypeStrings[type] + " type is not assignable");
    }

    // if (DataType::STRING) putSquareBrackets = true;

    return prefix + ' ' + variable + (putSquareBrackets ? "[]" : "") + " = " + exp->genCode();
}

std::string Assignment::printNode() {
    return "Assign " + variable + " " + exp->printNode();
}