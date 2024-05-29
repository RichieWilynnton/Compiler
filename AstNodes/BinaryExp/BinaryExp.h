#ifndef BINARYEXP_H
#define BINARYEXP_H

#include "Exp.h"

class BinaryExp : public Exp {
    public:
        Exp* exp1, *exp2;

        BinaryExp(Exp* exp1, Exp* exp2) : exp1(exp1), exp2(exp2) {}
};

#endif