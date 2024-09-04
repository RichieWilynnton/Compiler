#ifndef NUMLIT_H
#define NUMLIT_H

#include "../Exp.h"

#include <string>
#include <memory>

class NumLit : public Exp {
    public:
        std::string content;

        NumLit(std::string content);
        std::string genCode() override;
        std::string printNode() override;
        void inferType() override;
        std::unique_ptr<Exp> clone() override;

};

#endif