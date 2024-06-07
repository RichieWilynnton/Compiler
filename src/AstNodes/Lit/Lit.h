#ifndef LIT_H
#define LIT_H

#include "../Exp.h"

#include <string>

class Lit : public Exp {
    std::string genCode() = 0;
};

#endif