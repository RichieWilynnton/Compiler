#include "Return.h"

std::string Return::genCode() {
    return "return " + exp->genCode();
} 
std::string Return::printNode() {
    return "RETURN (" + exp->printNode() + ")";
}