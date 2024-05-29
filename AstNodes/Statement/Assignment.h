#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "ASTNode.h"
#include "Exp.h"

#include <vector>
#include <string>
#include <memory>

class Assignment : public ASTNode {
    public:
        std::string variable;
        std::unique_ptr<Exp> exp;

        Assignment(std::string variable, std::unique_ptr<Exp> exp) : variable(variable), exp(std::move(exp)) {};
};


#endif