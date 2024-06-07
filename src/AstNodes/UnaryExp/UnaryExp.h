#pragma once

#include "../Exp.h"
#include <memory>

class UnaryExp : public Exp {
public:
    UnaryExp(std::unique_ptr<Exp>& exp1);
    std::unique_ptr<Exp> exp1;
};
