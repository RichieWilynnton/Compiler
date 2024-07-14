#ifndef DIV_H
#define DIV_H

#include "./BinaryExp.h"
#include "../Exp.h"
#include <memory>

class DivExp : public BinaryExp {
    public:
        using BinaryExp::BinaryExp;
        std::string genCode() override; 
        std::string printNode() override;
        void inferType() override;
        std::unique_ptr<Exp> eval() override;
};

#endif