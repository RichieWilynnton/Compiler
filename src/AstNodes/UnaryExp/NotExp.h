#pragma once

#include "../Exp.h"

#include <string>
#include <memory>

class NotExp : public Exp {
    public:
        std::unique_ptr<Exp> exp1;
        NotExp(std::unique_ptr<Exp>& exp1)
            : exp1(std::move(exp1)) {
            inferType();
        }
        std::string genCode() override;
        std::string printNode() override;
        void inferType() override;

};