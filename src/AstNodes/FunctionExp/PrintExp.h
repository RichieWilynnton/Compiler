#pragma once
#include "../Exp.h"
#include <string>
#include <unordered_map>
#include <memory>

class PrintExp : public Exp {
    public:
        std::unordered_map<DataType::DataType, std::string> printFunctions = {
            {DataType::NUMBER, "print_int"},
            {DataType::BOOLEAN, "print_bool"},
            {DataType::ARRAY, "print_vector"},
        };
        std::unique_ptr<Exp> exp;
        PrintExp(std::unique_ptr<Exp>& exp) : exp(std::move(exp)) {inferType();}
        std::string genCode() override;
        std::string printNode() override; 
        void inferType() override;
};