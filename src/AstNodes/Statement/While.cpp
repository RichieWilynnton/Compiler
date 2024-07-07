#include "./While.h"
#include <string>

std::string While::printNode() {
    return "WHILE (" + condition->printNode() + ") (" + block->printNode() + ')'; 
}


std::string While::genCode() {
    return "while (" + condition->genCode() + ") " + block->genCode(); 
}