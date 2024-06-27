#include "./If.h"

#include <memory>
#include <string>

std::string If::printNode() {
    std::string elseString = elseBlock ? ("ELSE (" + elseBlock->printNode()) : ")";
    return "IF (" + condition->printNode() + ") (" + thenBlock->printNode() + ')'; 
}


std::string If::genCode() {
    std::string elseString = elseBlock ? ("\nelse " + elseBlock->genCode()) : "";
    return "if (" + condition->genCode() + ") " + thenBlock->genCode() + elseString;
}

void If::setElse(std::unique_ptr<Block>& block) {
    elseBlock = std::move(block);
}