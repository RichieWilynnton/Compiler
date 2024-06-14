#pragma once
#include "AstNodes/DataType.h"

#include <memory>
#include <unordered_map>
#include <string>

class Scope {
    std::unique_ptr<Scope> outerScope;
    std::unordered_map<std::string, DataType::DataType> symbols;
    public:
        Scope(std::unique_ptr<Scope> outerScope = nullptr) : outerScope(std::move(outerScope)) {};
        std::unique_ptr<Scope> enterNewScope();
        std::unique_ptr<Scope> exitScope();
        DataType::DataType getVariableType(std::string var);
        void declareVariable(std::string var, DataType::DataType val);
};
