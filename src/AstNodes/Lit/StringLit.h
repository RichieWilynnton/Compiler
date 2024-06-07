#pragma once

#include "Lit.h"

#include <string>

class StringLit : public Lit {
    public:
        std::string content;

        StringLit(std::string content = "");
        std::string genCode() override;
        std::string printNode() override;
        void inferType() override;

};
