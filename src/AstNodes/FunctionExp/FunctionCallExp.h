#pragma once
#include "../Exp.h"
#include "../Block.h"
#include "../Scope.h"
#include "../FunctionExp/LambdaExp.h"
#include <string>
#include <unordered_map>
#include <memory>
#include <tuple>

class FunctionCallExp : public Exp {
    public:
        std::unique_ptr<LambdaExp> lambdaExp;
        std::vector<std::unique_ptr<Exp>> args; 
        std::string lambdaEnvName;
        
        FunctionCallExp(std::unique_ptr<LambdaExp>& lambdaExp, std::string lambdaEnvName) : lambdaExp(std::move(lambdaExp)), lambdaEnvName(lambdaEnvName) {inferType();}; // input args directly by appending to args attribute.
        std::string genCode() override;
        std::string printNode() override; 
        void inferType() override;
        std::unique_ptr<Exp> clone() override;
        void addArg(std::unique_ptr<Exp>& arg);
};