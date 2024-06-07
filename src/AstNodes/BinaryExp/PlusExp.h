#ifndef PLUS_H
#define PLUS_H

#include "BinaryExp.h"

class PlusExp : public BinaryExp {
    public:
        using BinaryExp::BinaryExp;
        std::string genCode() override; 
        std::string printNode() override;
        void inferType() override;

};

#endif