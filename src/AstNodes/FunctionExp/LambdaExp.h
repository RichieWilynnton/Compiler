#pragma once
#include "../Exp.h"
#include "../Block.h"
#include "../Scope.h"
#include <string>
#include <unordered_map>
#include <memory>
#include <tuple>

class LambdaExp : public Exp {
    public:
        std::unique_ptr<Block> funcBody;
        std::vector<std::pair<std::string, DataType::DataType>> params;
        std::vector<std::tuple<std::string, DataType::DataType, std::unique_ptr<Exp>>> env;
        std::string funcName;
        static int LAMBDANUM;
        std::unordered_map<DataType::DataType, std::string> types;
        DataType::DataType returnType;

        std::unordered_map<DataType::DataType, std::string> makeElementFuncs = {
            {DataType::NUMBER, "make_int_element"},
            {DataType::BOOLEAN, "make_bool_element"},
        };

        std::unordered_map<DataType::DataType, std::string> typeConvert = {
            {DataType::VOID, "void"},
            {DataType::NUMBER, "int"},
            {DataType::BOOLEAN, "bool"},
        };
        
        LambdaExp(std::unique_ptr<Block>& funcBody, std::vector<std::pair<std::string, DataType::DataType>> params, DataType::DataType returnType, std::unique_ptr<Scope>& scope);
        std::string genCode() override;
        std::string printNode() override; 
        void inferType() override;
        std::unique_ptr<Exp> clone() override;
        std::string genFunctionCode();
        void extractEnv(std::unique_ptr<Scope>& scope);
};