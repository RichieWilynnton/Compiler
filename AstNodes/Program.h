#ifndef PROGRAM_H
#define PROGRAM_H

#include "ASTNode.h"

#include <vector>

class Program : public ASTNode {
    std::vector<ASTNode> statements;

    public:
        void addStatement(ASTNode node);
};


#endif