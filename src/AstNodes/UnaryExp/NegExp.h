#pragma once

#include "../Exp.h"

#include <string>
#include <memory>

class NegExp : public Exp {
    public:
        std::unique_ptr<Exp> exp1;
        NegExp(std::unique_ptr<Exp>& exp1)
            : exp1(std::move(exp1)) {
            inferType();
        }
        std::string genCode() override;
        std::string printNode() override;
        void inferType() override;

};