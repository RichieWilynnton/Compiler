#pragma once
#include "AstNodes/DataType.h"
#include "AstNodes/Exp.h" 

#include <memory>
#include <unordered_map>
#include <string>

class Scope {
    std::unordered_map<std::string, DataType::DataType> symbols;
    public:
    std::unique_ptr<Scope> outerScope;

        Scope(std::unique_ptr<Scope> outerScope = nullptr) : outerScope(std::move(outerScope)) {};
        std::unique_ptr<Scope> enterNewScope(std::unique_ptr<Scope>& oldScope);
        std::unique_ptr<Scope> exitScope();
        bool isDeclared(std::string& var);
        DataType::DataType getVarInfo(std::string& var);
        void declareVariable(std::string& var, DataType::DataType varType);
};
