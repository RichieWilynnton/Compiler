#include "Assignment.h"
#include "../TypeError.h"
#include "../DataType.h"
#include <string>

std::string Assignment::genCode()
{
    DataType::DataType type = exp->type;
    std::string prefix;

    switch (type)
    {
    case DataType::NUMBER:
        prefix = "int";
        break;
    case DataType::STRING:
        prefix = "string";
        break;
    case DataType::BOOLEAN:
        prefix = "bool";
        break;
    default:
        TypeError::terminate(DataType::dataTypeStrings[type] + " type is not assignable");
        
    }

    return prefix + ' ' + variable + " = " + exp->genCode();
}

std::string Assignment::printNode() {
    return "Assign " + variable + " " + exp->printNode();
}