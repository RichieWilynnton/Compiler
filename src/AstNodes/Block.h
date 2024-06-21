#pragma once

#include "ASTNode.h"

#include <vector>
#include <memory>
#include <string>

class Block : public ASTNode {
    public:
        std::vector<std::unique_ptr<ASTNode>> statements;
        void addStatement(std::unique_ptr<ASTNode>& statement);
        std::string genCode() override;
        std::string printNode() override;
};