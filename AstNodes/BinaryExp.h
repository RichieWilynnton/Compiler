#ifndef BINARYEXP_H
#define BINARYEXP_H

#include "Exp.h"

// BinaryOp := "+" | "-" | "*" | "/" | "==" | "!=" | "<" | "<=" | ">" | ">=" | "&&" | "||"
enum BinaryOp {
    ADD,
    MINUS,
    MULTIPLY,
    DIVIDE,
    EQEQ,
    NEQ,
    LT,
    LTEQ,
    MT,
    MTEQ,
    AND,
    OR
};

class BinaryExp : public Exp {
    public:
        BinaryOp op;
        Exp exp1, exp2;
};

#endif