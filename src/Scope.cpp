#include "Scope.h"
#include "AstNodes/Exp.h"
#include "AstNodes/DataType.h"
#include "AstNodes/FreePtr.h"
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

bool Scope::inCurrentScope(std::string& var) {
    return symbols.find(var) != symbols.end();
}

void Scope::declareVariable(std::string& var, DataType::DataType varType){
    if (inCurrentScope(var)) throw std::runtime_error("Variable \"" + var + "\" is re-declared!");
    
    symbols[var] = varType;
}

void Scope::modifyVariable(std::string& var, DataType::DataType varType) {
    std::optional<DataType::DataType> o_varInfo = getVarInfo(var);
    if (!o_varInfo) throw std::runtime_error("Variable \"" + var + "\" has not been declared!");
    else {
        DataType::DataType varInfo = o_varInfo.value();
        if (varType != varInfo) throw std::runtime_error("Variable \"" + var + "\" changed types since last declaration!");
    }
}

std::vector<std::unique_ptr<FreePtr>> Scope::getFreePtrs() {
    std::vector<std::unique_ptr<FreePtr>> ret;
    for (auto [variable, type] : symbols) {
        ret.push_back(std::make_unique<FreePtr> (variable, type));
    }
    return ret;
}


