#pragma once
#include "../Exp.h"
#include <string>
#include <memory>

class PrintExp : public Exp {
    public:
        std::unique_ptr<Exp> exp;
        PrintExp(std::unique_ptr<Exp>& exp) : exp(std::move(exp)) {inferType();}
        std::string genCode() override;
        std::string printNode() override; 
        void inferType() override;
};