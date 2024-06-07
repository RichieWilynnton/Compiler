#pragma once
#include "../Exp.h"

class Function : Exp {
    virtual std::string genCode() = 0;
    virtual std::string printNode() = 0; 
};