#ifndef MULT_H
#define MULT_H

#include "../Exp.h"

#include <memory>

class MultExp : public Exp {
    public:
        std::unique_ptr<Exp> exp1, exp2;
        MultExp(std::unique_ptr<Exp>& exp1, std::unique_ptr<Exp>& exp2)
            : exp1(std::move(exp1)), exp2(std::move(exp2)) {
            inferType();
        }
        std::string genCode() override; 
        std::string printNode() override;
        void inferType() override;

};

#endif