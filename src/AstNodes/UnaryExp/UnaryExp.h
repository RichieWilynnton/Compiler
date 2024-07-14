#pragma once
#include "../Exp.h"

class UnaryExp : public Exp {
    public:
    std::unique_ptr<Exp> exp1;
    UnaryExp(std::unique_ptr<Exp>& exp1)
            : exp1(std::move(exp1)) {
    }
    void init() override;

};