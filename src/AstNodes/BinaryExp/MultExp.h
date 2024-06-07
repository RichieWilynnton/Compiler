#ifndef MULT_H
#define MULT_H

#include "BinaryExp.h"

class MultExp : public BinaryExp {
    public:
        using BinaryExp::BinaryExp;
        std::string genCode() override; 
        std::string printNode() override;
        void inferType() override;

};

#endif