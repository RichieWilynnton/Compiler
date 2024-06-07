#ifndef VARLIT_H
#define VARLIT_H

#include "Lit.h"

#include <string>

class VarLit : public Lit {
    public:
        std::string name;
        
        VarLit(std::string name);
        std::string genCode() override;
        std::string printNode() override;
        void inferType() override;

};

#endif