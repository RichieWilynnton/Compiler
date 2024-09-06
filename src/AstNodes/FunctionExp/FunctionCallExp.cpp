#include "FunctionCallExp.h"
#include "../Lit/VarLit.h"
#include "../TypeError.h"

#include <memory>
#include <unordered_set>
#include <string>
#include <iostream>

std::string FunctionCallExp::genCode() {
    std::string argString = "";
    for (std::unique_ptr<Exp>& arg : args) {
        argString += ", " + arg->genCode(); 
    }
    return lambdaExp->funcName + "(" + lambdaEnvName + argString + " )"; 
}

void FunctionCallExp::inferType() {
    type = lambdaExp->returnType;

}

std::string FunctionCallExp::printNode() {
    return "LAMBDA";
}

void FunctionCallExp::addArg(std::unique_ptr<Exp>& arg) {
    args.push_back(std::move(arg));
    // if (args.size() > lambdaExp->params.size()) {
    //     TypeError::terminate(lambdaEnvName + " function accepts " + std::string(lambdaExp->params.size()) + "")
    // }
    // if (arg->type != args[args.size() - 1]->type) {

    // }
}

std::unique_ptr<Exp> FunctionCallExp::clone() {
    return nullptr;
}
