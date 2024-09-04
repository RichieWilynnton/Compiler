#pragma once

#include "../Exp.h"

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

class ArrayLit : public Exp
{
public:
    std::vector<std::unique_ptr<Exp>> items;
    int size;
    std::unordered_map<DataType::DataType, std::string> appendFunctions = {
        {DataType::NUMBER, "appendInt"},
        {DataType::BOOLEAN, "appendBool"},
        {DataType::STRING, "appendString"},
    };

    ArrayLit();

    void addItem(std::unique_ptr<Exp> &exp);
    std::string genCode() override;
    std::string printNode() override;
    void inferType() override;
    std::unique_ptr<Exp> clone() override;
};