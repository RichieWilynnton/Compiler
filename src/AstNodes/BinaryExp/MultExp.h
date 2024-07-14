#ifndef MULT_H
#define MULT_H

#include "./BinaryExp.h"
#include "../Exp.h"

#include <memory>

class MultExp : public BinaryExp {
    public:
        using BinaryExp::BinaryExp;
        std::string genCode() override; 
        std::string printNode() override;
        void inferType() override;
        std::unique_ptr<Exp> eval() override;

};

#endif