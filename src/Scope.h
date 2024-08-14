#pragma once
#include "AstNodes/DataType.h"
#include "AstNodes/Exp.h" 
#include "AstNodes/FreePtr.h" 

#include <memory>
#include <unordered_map>
#include <string>
#include <optional>

class Scope {
    std::unordered_map<std::string, DataType::DataType> symbols;
    
    public:
    std::unique_ptr<Scope> outerScope;

        Scope(std::unique_ptr<Scope> outerScope = nullptr) : outerScope(std::move(outerScope)) {};
        std::unique_ptr<Scope> enterNewScope(std::unique_ptr<Scope>& oldScope);
        std::unique_ptr<Scope> exitScope();
        bool inCurrentScope(std::string& var);

        std::optional<DataType::DataType> getVarInfo(std::string& var);
        void declareVariable(std::string& var, DataType::DataType varType);
        void modifyVariable(std::string& var, DataType::DataType varType);
        std::vector<std::unique_ptr<FreePtr>> getFreePtrs();

};
