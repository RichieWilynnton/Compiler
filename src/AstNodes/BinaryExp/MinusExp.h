#ifndef MINUS_H
#define MINUS_H

#include "./BinaryExp.h"
#include "../Exp.h"
#include <memory>

class MinusExp : public BinaryExp {
    public:
        using BinaryExp::BinaryExp;
        std::string genCode() override; 
        std::string printNode() override;
        void inferType() override;
        std::unique_ptr<Exp> eval() override;
        std::unique_ptr<Exp> clone() override;


};

#endif