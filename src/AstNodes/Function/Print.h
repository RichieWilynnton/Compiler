#pragma once
#include "Function.h"
#include <string>

class Print : Function {
    std::string content;
    std::string genCode() override;
    std::string printNode() override; 
};