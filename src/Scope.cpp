#include "Scope.h"
#include "AstNodes/Exp.h"
#include "AstNodes/DataType.h"
#include "AstNodes/FreePtr.h"
#include <memory>
#include <string>
#include <stdexcept>
#include <iostream>
#include <optional>
#include <unordered_set>

std::unique_ptr<Scope> Scope::enterNewScope (std::unique_ptr<Scope>& oldScope) {
    return std::make_unique<Scope>(std::move(oldScope));
}

std::unique_ptr<Scope> Scope::exitScope () {
    return std::move(outerScope);
}


std::optional<DataType::DataType> Scope::lookupType(std::string& var) {
    if (symbols.find(var) != symbols.end()) return symbols[var].first;
    return outerScope ? outerScope->lookupType(var) : std::nullopt;
}

std::unique_ptr<Exp> Scope::lookupVal(std::string& var) {
    if (symbols.find(var) != symbols.end()) {
        return symbols[var].second ? symbols[var].second->clone() : nullptr;
    }
    return outerScope ? outerScope->lookupVal(var) : nullptr;
}

// Find the nearest scope of when this variable was last declared and modify the value. Variable is guaranteed to have been declared on call of this function
void Scope::modifyVal(std::string &var, std::unique_ptr<Exp>& val) {
    if (symbols.find(var) != symbols.end()) {
        symbols[var].second = val->clone();
    }
    else if (outerScope) outerScope->modifyVal(var, val);
}

bool Scope::inCurrentScope(std::string& var) {
    return symbols.find(var) != symbols.end();
}

void Scope::declareVariable(std::string& var, DataType::DataType varType, std::unique_ptr<Exp>& val){

    if (inCurrentScope(var)) throw std::runtime_error("Variable \"" + var + "\" is re-declared!");


    symbols[var].first = varType;

    if (val) symbols[var].second = val->clone();
    

}

void Scope::modifyVariable(std::string& var, DataType::DataType varType, std::unique_ptr<Exp>& val) {
    std::optional<DataType::DataType> o_varInfo = lookupType(var);
    if (!o_varInfo) throw std::runtime_error("Variable \"" + var + "\" has not been declared!");
    else {
        DataType::DataType varInfo = o_varInfo.value();
        if (varType != varInfo) throw std::runtime_error("Variable \"" + var + "\" changed types since last declaration!");

        modifyVal(var, val);
    }
}

std::vector<std::unique_ptr<FreePtr>> Scope::getFreePtrs() {
    std::vector<std::unique_ptr<FreePtr>> ret;
    for (const auto& [variable, d] : symbols) {
        ret.push_back(std::make_unique<FreePtr> (variable, d.first));
    }
    return ret;
}

std::unique_ptr<Scope> Scope::clone() {
    std::unique_ptr<Scope> clone = std::make_unique<Scope> ();
    for (const auto& [name, data] : symbols) {
        clone->symbols[name].first = this->symbols[name].first;
        if (this->symbols[name].second) clone->symbols[name].second = this->symbols[name].second->clone();
    }
    
    if (outerScope) clone->outerScope = outerScope->clone();
    return clone;
}

