#include "Assignment.h"
#include <string>

std::string Assignment::genCode()
{

    return variable + " = " + exp->genCode();
}

std::string Assignment::printNode() {
    return "Assign " + variable + " " + exp->printNode();
}