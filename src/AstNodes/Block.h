#pragma once

#include "ASTNode.h"
#include "Block.h"

#include <vector>
#include <memory>
#include <string>

class Block : public ASTNode {
    public:
        std::vector<std::unique_ptr<ASTNode>> statements;
        void addStatement(std::unique_ptr<ASTNode>& statement);
        void addBlock(std::unique_ptr<Block>& block);
        std::string genCode() override;
        std::string printNode() override;
};