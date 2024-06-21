#include "Scope.h"
#include "AstNodes/Exp.h"
#include "AstNodes/DataType.h"
#include <memory>
#include <string>
#include <stdexcept>
#include <iostream>


std::unique_ptr<Scope> Scope::enterNewScope (std::unique_ptr<Scope>& oldScope) {
    return std::make_unique<Scope>(std::move(oldScope));
}

std::unique_ptr<Scope> Scope::exitScope () {
    if (outerScope == nullptr) std::cout << "helo \n"; 
    return std::move(outerScope);
}

bool Scope::isDeclared(std::string& var) {
    return (symbols.find(var) != symbols.end());
}

DataType::DataType Scope::getVarInfo(std::string& var) {
    if (!isDeclared(var)) throw std::runtime_error("Undeclared variable: " + var);
    return symbols[var];
}

void Scope::declareVariable(std::string& var, DataType::DataType varType){
    // already been declared before
    if (isDeclared(var)){
        DataType::DataType prevType = symbols[var];
        if (prevType != varType)  throw std::runtime_error("Variable " + var + " changed types!");
    }
    else symbols[var] = varType;
}


