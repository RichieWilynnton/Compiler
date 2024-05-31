#ifndef PROGRAM_H
#define PROGRAM_H

#include "ASTNode.h"

#include <vector>
#include <memory>

class Program : public ASTNode {
    std::vector<std::unique_ptr<ASTNode>> statements;

    public:
        void addStatement(std::unique_ptr<ASTNode>& statement);
};


#endif