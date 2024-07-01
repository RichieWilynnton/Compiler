#include "Scope.h"
#include "AstNodes/Exp.h"
#include "AstNodes/DataType.h"
#include <memory>
#include <string>
#include <stdexcept>
#include <iostream>
#include <optional>


std::unique_ptr<Scope> Scope::enterNewScope (std::unique_ptr<Scope>& oldScope) {
    return std::make_unique<Scope>(std::move(oldScope));
}

std::unique_ptr<Scope> Scope::exitScope () {
    return std::move(outerScope);
}


std::optional<DataType::DataType> Scope::getVarInfo(std::string& var) {
    if (symbols.find(var) != symbols.end()) return symbols[var];
    return outerScope ? outerScope->getVarInfo(var) : std::nullopt;
}

void Scope::declareVariable(std::string& var, DataType::DataType varType){
    // already been declared before
    if (getVarInfo(var)){
        DataType::DataType prevType = symbols[var];
        if (prevType != varType)  throw std::runtime_error("Variable " + var + " changed types!");
    }

    
    else symbols[var] = varType;
}


