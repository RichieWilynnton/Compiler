#ifndef EXP_H
#define EXP_H

#include "ASTNode.h"
#include "DataType.h"

#include <string>
#include <memory>

class Exp : public ASTNode {
    public:
        DataType::DataType type = DataType::UNKNOWN;
        bool valKnown = true;

        virtual std::string genCode() = 0;
        virtual std::string printNode() = 0;
        virtual std::unique_ptr<Exp> eval() { return nullptr; };
        virtual void inferType() = 0;
        virtual void init() { inferType(); } // init all additional information
        virtual std::unique_ptr<Exp> clone() = 0;
};

#endif