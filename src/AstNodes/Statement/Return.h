#pragma once

#include <memory>
#include "../ASTNode.h"
#include "../Block.h"
#include "../Exp.h"

class Return : public ASTNode {
    public:
        Return(std::unique_ptr<Exp>& exp) : exp(std::move(exp)) {} 
        std::unique_ptr<Exp> exp;

        std::string genCode() override; 
        std::string printNode() override;
};