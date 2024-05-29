#ifndef VARLIT_H
#define VARLIT_H

#include "Lit.h"

#include <string>

class VarLit : public Lit {
    public:
        std::string name;

        VarLit(std::string name = "") : name(name) {}
};

#endif