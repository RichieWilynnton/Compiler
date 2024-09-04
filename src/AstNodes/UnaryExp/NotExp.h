#pragma once

#include "../Exp.h"
#include "./UnaryExp.h"

#include <string>
#include <memory>

class NotExp : public UnaryExp {
    public:
        using UnaryExp::UnaryExp;
        std::string genCode() override;
        std::string printNode() override;
        void inferType() override;
        std::unique_ptr<Exp> eval() override;
        std::unique_ptr<Exp> clone() override;

};