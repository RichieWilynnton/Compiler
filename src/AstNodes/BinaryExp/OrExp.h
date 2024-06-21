#pragma once
#include "../Exp.h"
#include <string>
#include <memory>

class OrExp : public Exp {
    public:
        std::unique_ptr<Exp> exp1, exp2;
        std::string genCode() override; 
        std::string printNode() override;
        void inferType() override;
        OrExp(std::unique_ptr<Exp>& exp1, std::unique_ptr<Exp>& exp2)
            : exp1(std::move(exp1)), exp2(std::move(exp2)) {
            inferType();
        }
};
