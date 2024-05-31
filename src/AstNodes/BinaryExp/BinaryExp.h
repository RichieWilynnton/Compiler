#ifndef BINARYEXP_H
#define BINARYEXP_H

#include "Exp.h"
#include <memory>

class BinaryExp : public Exp {
    public:
        std::unique_ptr<Exp> exp1, exp2;

        BinaryExp(std::unique_ptr<Exp>& exp1, std::unique_ptr<Exp>& exp2) : exp1(std::move(exp1)), exp2(std::move(exp2)) {}
};

#endif