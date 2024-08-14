#pragma once

#include "ASTNode.h"
#include "DataType.h"

#include <string>
#include <unordered_map>

class FreePtr : public ASTNode {
    public:
        std::string variable;
        DataType::DataType type;
        std::unordered_map<DataType::DataType, std::string> freeFunctions = {
            {DataType::ARRAY, "freeVector"}
        };
        
        FreePtr(std::string variable, DataType::DataType type) : variable(variable), type(type) {};
        std::string genCode() override;       
        std::string printNode() override; 
    
};