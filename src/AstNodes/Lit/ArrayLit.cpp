#include "ArrayLit.h"
#include "../Exp.h"

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

ArrayLit::ArrayLit() {
    inferType();
    size = 0;
}

std::string ArrayLit::genCode() {
    std::string ret = "initVector(" + std::to_string(size) + ')';
    std::cout << ret << '\n';


    for (std::unique_ptr<Exp>& exp : items) {
        ret = appendFunctions[exp->type] + "(" + exp->genCode() + ", " + ret + ")"; 
    }
    return ret;
}

std::string ArrayLit::printNode() {
    std::string ret = "";
    if (size) ret += items[0]->printNode();
    for (int i=1; i<size; i++) {
        ret += ", " + items[1]->printNode();
    }
    return "[ " + ret + " ]";
}

void ArrayLit::inferType() { 
    type = DataType::ARRAY;
}

void ArrayLit::addItem(std::unique_ptr<Exp>& exp) {
    size++;
    items.push_back(std::move(exp));
}

std::unique_ptr<Exp> ArrayLit::clone() {
    std::unique_ptr<ArrayLit> array = std::make_unique<ArrayLit> ();
    for (int i=0; i<size; i++) {
        array->items[i] = this->items[i]->clone();
    }
    array->size = this->size;
    return array;
}