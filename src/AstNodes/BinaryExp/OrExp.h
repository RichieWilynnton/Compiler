#pragma once
#include "./BinaryExp.h"
#include "../Exp.h"
#include <string>
#include <memory>

class OrExp : public BinaryExp {
    public:
        using BinaryExp::BinaryExp;
        std::string genCode() override; 
        std::unique_ptr<Exp> eval() override;
        std::string printNode() override;
        void inferType() override;
        std::unique_ptr<Exp> clone() override;

};
