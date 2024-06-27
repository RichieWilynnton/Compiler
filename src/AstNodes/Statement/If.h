#pragma once

#include <memory>
#include "../ASTNode.h"
#include "../Block.h"
#include "../Exp.h"

class If : public ASTNode {
    public:
        If(std::unique_ptr<Exp>& condition, std::unique_ptr<Block>& thenBlock, std::unique_ptr<Block>& elseBlock) :  condition(std::move(condition)), thenBlock(std::move(thenBlock)), elseBlock(std::move(elseBlock)) {} 
        std::unique_ptr<Block> thenBlock;
        std::unique_ptr<Exp> condition;
        std::unique_ptr<Block> elseBlock;

        std::string genCode() override; 
        std::string printNode() override;
        void setElse(std::unique_ptr<Block>& elseBlock);
};