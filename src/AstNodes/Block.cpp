#include "Block.h"
#include <memory>
#include <string>
#include <iostream>

void Block::addStatement(std::unique_ptr<ASTNode>& node) {
    statements.push_back(std::move(node));
}

void Block::addBlock(std::unique_ptr<Block>& block) {
    statements.push_back(std::move(block));
}

std::string Block::genCode() {
    std::string ret = "{\n";
    for (std::unique_ptr<ASTNode>& node : statements) {
        ret += node->genCode() + ";\n";
    }
    return ret + '}';
}

std::string Block::printNode() {
    std::string ret = "BLOCK (\n";
    for (std::unique_ptr<ASTNode>& node : statements) {
        ret += node->printNode() + "\n";
    }
    return ret + ')';
}