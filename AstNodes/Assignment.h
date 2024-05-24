#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "ASTNode.h"
#include "Exp.h"

#include <vector>
#include <string>

class Assignment : public ASTNode {
    public:
        std::string variable;
        Exp exp;

        Assignment(std::string variable, Exp exp);
};


#endif