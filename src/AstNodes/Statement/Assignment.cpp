#include "Assignment.h"
#include "../TypeError.h"
#include "../DataType.h"
#include <string>
#include <iostream>

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
    case DataType::ARRAY:
        prefix = "Vector*";
        break;
    case DataType::LAMBDA:
        // The variable is actually storing an array that represents an env, compiler handles how the function is called
        prefix = "Element";
        putSquareBrackets = true;
        break;

    default:
        TypeError::terminate(DataType::dataTypeStrings[type] + " type is not assignable");
    }

    return prefix + ' ' + variable + (putSquareBrackets ? "[]" : "") + " = " + exp->genCode();
}

std::string Assignment::printNode() {
    return "Assign " + variable + " " + exp->printNode();
}