#include "Program.h"
#include <memory>
#include <string>
#include <iostream>

void Program::addStatement(std::unique_ptr<ASTNode>& node) {
    statements.push_back(std::move(node));
}

std::string Program::genCode() {
    std::string ret = "";
    for (std::unique_ptr<ASTNode>& node : statements) {
        ret += node->genCode() + ";\n";
    }
    return ret;
}

std::string Program::printNode() {
    std::string ret = "SEQ (\n";
    for (std::unique_ptr<ASTNode>& node : statements) {
        ret += node->printNode() + "\n";
    }
    return ret + ')';
}