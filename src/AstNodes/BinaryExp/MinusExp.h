#ifndef MINUS_H
#define MINUS_H

#include "BinaryExp.h"

class MinusExp : public BinaryExp {
    public:
        using BinaryExp::BinaryExp;
        std::string genCode() override; 
        std::string printNode() override;
        void inferType() override;

};

#endif