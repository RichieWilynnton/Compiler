#pragma once
#include "./BinaryExp.h"
#include "../Exp.h"
#include <string>
#include <memory>

class GTEQExp : public BinaryExp {
    public:
        using BinaryExp::BinaryExp;

        std::string genCode() override; 
        std::string printNode() override;
        std::unique_ptr<Exp> eval() override;
        void inferType() override;
};
