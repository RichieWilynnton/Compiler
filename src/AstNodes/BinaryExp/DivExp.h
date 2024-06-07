#ifndef DIV_H
#define DIV_H

#include "BinaryExp.h"

class DivExp : public BinaryExp {
    public:
        using BinaryExp::BinaryExp;
        std::string genCode() override; 
        std::string printNode() override;
        void inferType() override;
};

#endif