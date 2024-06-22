#include "./If.h"

std::string If::printNode() {
    return "IF (" + condition->printNode() + ") (" + block->printNode() + ')'; 
}


std::string If::genCode() {
    return "if (" + condition->genCode() + ") " + block->genCode(); 
}