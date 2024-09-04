#pragma once

#include "../Exp.h"

#include <string>

class StringLit : public Exp {
    public:
        std::string content;

        StringLit(std::string content);
        std::string genCode() override;
        std::string printNode() override;
        void inferType() override;
        std::unique_ptr<Exp> clone() override;

};
