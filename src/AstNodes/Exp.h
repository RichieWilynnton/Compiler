#ifndef EXP_H
#define EXP_H

#include "ASTNode.h"
#include "DataType.h"

#include <string>

class Exp : public ASTNode {
    public:
        DataType::DataType type = DataType::UNKNOWN;
        virtual std::string genCode() = 0;
        virtual std::string printNode() = 0; 
        virtual void inferType() = 0;

};

#endif