#pragma once

#include "UnaryExp.h"

#include <string>
#include <memory>

class NegExp : public UnaryExp {
    public:
        using UnaryExp::UnaryExp;   
        std::string genCode() override;
        std::string printNode() override;
        void inferType() override;

};