#include "For.h"
#include <string>

std::string For::printNode() {
    return "FOR (" + iteratorVar->printNode() + " ) ( " + iteratorStart->printNode() + " ) ( " + iteratorEnd->printNode() + " ( " + iteratorJump->printNode() + ") (" + block->printNode() + ')'; 
}

std::string For::genCode() {
    return "for (int " + iteratorVar->genCode() + "=" + iteratorStart->genCode() + ";" + iteratorVar->genCode() + "<"  + iteratorEnd->genCode() + ";" + iteratorVar->genCode() + "+=" + iteratorJump->genCode() + ")" + block->genCode(); 
}

