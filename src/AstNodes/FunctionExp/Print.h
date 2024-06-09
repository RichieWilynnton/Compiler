#pragma once
#include "../Exp.h"
#include <string>

class Print : Exp {
    std::string content;
    std::string genCode() override;
    std::string printNode() override; 
};