#ifndef NUMLIT_H
#define NUMLIT_H

#include "Lit.h"

#include <string>

class NumLit : public Lit {
    public:
        std::string content;

        NumLit(std::string content);
        std::string genCode() override;
        std::string printNode() override;
        void inferType() override;


};

#endif