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
    bool alrDeclared;

    Assignment(std::string variable, std::unique_ptr<Exp>& exp, bool alrDeclared = false) 
        : variable(variable), exp(std::move(exp)), alrDeclared(alrDeclared) {};

    std::string genCode() override; 
    std::string printNode() override;

};

#endif
