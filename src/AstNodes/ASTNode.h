#ifndef ASTNODE_H
#define ASTNODE_H

#include <string>

class ASTNode {
    public:
        virtual std::string genCode() = 0;       
        virtual std::string printNode() = 0; 
};

#endif