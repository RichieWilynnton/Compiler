#include "LambdaExp.h"
#include "../Lit/VarLit.h"

#include <memory>
#include <unordered_set>
#include <iostream>
#include <string>

int LambdaExp::LAMBDANUM = 0;

LambdaExp::LambdaExp(std::unique_ptr<Block>& funcBody, std::vector<std::pair<std::string, DataType::DataType>> params, DataType::DataType returnType, std::unique_ptr<Scope>& scope) {
    inferType();
    this->funcBody = std::move(funcBody);
    this->params = params;
    this->returnType = returnType;
    extractEnv(scope);
    this->funcName = "_____LAMBDA_____" + std::to_string(LAMBDANUM);
    LAMBDANUM++;
}

void LambdaExp::extractEnv(std::unique_ptr<Scope>& scope) {
    std::unordered_set<std::string> seen;
    while (scope) {
        for (const auto& [name, data] : scope->symbols) {
            if (seen.find(name) == seen.end()) {
                seen.insert(name);
                std::unique_ptr<Exp> exp;
                if (data.second == nullptr) exp = std::make_unique<VarLit> (name, data.first);
                else exp = data.second->clone();
                env.push_back({name, data.first, std::move(exp)});
            }
        }
        scope = scope->exitScope();
    }
}

std::string LambdaExp::genCode() {
    std::string ret;
    // Element env[] = {make_int_element(1)};
    ret += '{';
    if (env.size() > 0) {
        int i = 0;
        for (const auto& [varname, vartype, varval] : env) {
            if (i > 0) ret += ',';
            if (makeElementFuncs.find(vartype) != makeElementFuncs.end()) ret += makeElementFuncs[vartype] + "(" + varval->genCode() + ")";
            i++;
        }
    }
    ret += '}';
    return ret;
}

std::string LambdaExp::genFunctionCode() {
    std::unordered_set<std::string> paramVars;
    std::string ret;
    std::vector<std::unique_ptr<FreePtr>> freeptrs; // for freeing pointers

    ret += typeConvert[returnType] + ' ' + funcName + "(" + "Element env[]";
    for (auto& [paramName, paramType] : params) {
        paramVars.insert(paramName);
        ret += ", " + typeConvert[paramType] + ' ' + paramName;
    }
    ret += ") {\n";
    int i = 0;
    for (const auto& [varname, vartype, varval] : env) {

        freeptrs.push_back(std::make_unique<FreePtr> (varname, vartype));

        if (paramVars.find(varname) == paramVars.end()) {
            if (vartype == DataType::LAMBDA) {
                ret +=  "Element " + varname + "[] ="; 
                ret += varval->genCode() + ";";
                ret += '\n';
            }
            else {
                ret += typeConvert[vartype] + ' ' + varname + '='; 
                ret += "*(" + typeConvert[vartype] + "*)" + "(env" + "[" + std::to_string(i) + "].data);";
                ret += '\n';
            }
        }
        i++;
    }
    ret += funcBody->genCode();
    for (std::unique_ptr<FreePtr>& ptr : freeptrs) {
        ret += ptr->genCode() + ";\n";
    }
    ret += "\n}";
    return ret;
}


void LambdaExp::inferType() {
    type = DataType::LAMBDA;
}

std::string LambdaExp::printNode() {
    return "LAMBDA";
}

std::unique_ptr<Exp> LambdaExp::clone() {
    // This is not the correct implementation of the clone function, but this is the bare minimum info for it to work.
    std::unique_ptr<Scope> nulScope = std::make_unique<Scope> ();
    std::unique_ptr<Block> nulBlock = std::make_unique<Block> ();
    std::unique_ptr<LambdaExp> lambdaclone = std::make_unique<LambdaExp> (nulBlock, params, returnType, nulScope);
    lambdaclone->funcName = funcName;
    lambdaclone->type = type;
    lambdaclone->params = params;
    for (const auto& [varname, vartype, varval] : env) {
        std::unique_ptr<Exp> varvalclone;
        if (varval) {
            varvalclone = varval->clone();
            lambdaclone->env.push_back({varname, vartype, std::move(varvalclone)});
        } 
        else lambdaclone->env.push_back({varname, vartype, nullptr});
        
    }

    return lambdaclone;
}