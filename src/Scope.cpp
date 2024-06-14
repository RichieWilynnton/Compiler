#include "Scope.h"
#include "AstNodes/DataType.h"
#include <memory>
#include <string>


std::unique_ptr<Scope> Scope::enterNewScope () {
    return std::make_unique<Scope>(std::move(this));
}

std::unique_ptr<Scope> Scope::exitScope () {
    return std::move(outerScope);
}

DataType::DataType Scope::getVariableType(std::string var) {
    if (symbols.find(var) == symbols.end());
    return symbols[var];
}

void Scope::declareVariable(std::string var, DataType::DataType val) {
    if (symbols.find(var) != symbols.end()) {
        if (symbols[var] != val);
    }
    symbols[var] = val;
}

