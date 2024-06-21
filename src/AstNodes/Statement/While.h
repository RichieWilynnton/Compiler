#pragma once

#include <memory>
#include "../ASTNode.h"
#include "../Block.h"
#include "../Exp.h"

class While : public ASTNode {
    public:
        While(std::unique_ptr<Exp>& condition, std::unique_ptr<Block>& block) : block(std::move(block)), condition(std::move(condition)) {} 
        std::unique_ptr<Block> block;
        std::unique_ptr<Exp> condition;

        std::string genCode() override; 
        std::string printNode() override;
};