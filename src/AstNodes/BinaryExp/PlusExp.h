#ifndef PLUS_H
#define PLUS_H

#include "../Exp.h"
#include <memory>

class PlusExp : public Exp {
    public:
        std::unique_ptr<Exp> exp1, exp2;
        PlusExp(std::unique_ptr<Exp>& exp1, std::unique_ptr<Exp>& exp2)
            : exp1(std::move(exp1)), exp2(std::move(exp2)) {
            inferType();
        }
        std::string genCode() override; 
        std::string printNode() override;
        void inferType() override;

};

#endif