#ifndef UNARYEXP_H
#define UNARYEXP_H

#include "Exp.h"

// UnaryOp := "-" | "!"

enum UnaryOp {
    NOT,
    NEG,
};

class UnaryExp : public Exp {
    public:
        UnaryOp op;
        Exp exp1, exp2;
};

#endif