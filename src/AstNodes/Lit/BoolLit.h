#pragma once

#include "../Exp.h"

#include <string>

class BoolLit : public Exp {
    public:
        bool state = false;

        BoolLit(bool state);
        std::string genCode() override;
        std::string printNode() override;
        void inferType() override;


};