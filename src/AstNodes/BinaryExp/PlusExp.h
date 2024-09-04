#ifndef PLUS_H
#define PLUS_H

#include "../Exp.h"
#include "./BinaryExp.h"
#include <memory>
#include <iostream>

class PlusExp : public BinaryExp {
    public:
        using BinaryExp::BinaryExp;
        std::unique_ptr<Exp> eval();
        std::string genCode() override; 
        std::string printNode() override;
        void inferType() override;
        std::unique_ptr<Exp> clone() override;

};

#endif