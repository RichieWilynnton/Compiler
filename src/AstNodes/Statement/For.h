#pragma once

#include <memory>
#include "../ASTNode.h"
#include "../Block.h"
#include "../Exp.h"

#include "../Lit/VarLit.h"

class For : public ASTNode
{
public:
    For(std::unique_ptr<VarLit> &iteratorVar, std::unique_ptr<Exp> &iteratorStart, std::unique_ptr<Exp> &iteratorEnd, std::unique_ptr<Block>& block, std::unique_ptr<Exp> &iteratorJump) : iteratorVar(std::move(iteratorVar)), iteratorStart(std::move(iteratorStart)), iteratorEnd(std::move(iteratorEnd)), block(std::move(block)), iteratorJump(std::move(iteratorJump)) {}
    For(std::unique_ptr<VarLit> &iteratorVar, std::unique_ptr<Exp> &iteratorStart, std::unique_ptr<Exp> &iteratorEnd, std::unique_ptr<Block>& block) : iteratorVar(std::move(iteratorVar)), iteratorStart(std::move(iteratorStart)), iteratorEnd(std::move(iteratorEnd)), block(std::move(block)) {}
    std::unique_ptr<VarLit> iteratorVar;
    std::unique_ptr<Exp> iteratorStart;
    std::unique_ptr<Exp> iteratorEnd;
    std::unique_ptr<Exp> iteratorJump;
    std::unique_ptr<Block> block;

    std::string genCode() override;
    std::string printNode() override;
};