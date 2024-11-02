#include "EQEQExp.h"
#include "../DataType.h"
#include "../Lit/BoolLit.h"
#include "../TypeError.h"
#include <string>
#include <iostream>

std::string EQEQExp::genCode() {
    return "(" + exp1->genCode() + "==" + exp2->genCode() + ")";
}
std::string EQEQExp::printNode() {
    return "EQEQ (" + exp1->printNode() + ", " + exp2->printNode() + ')';
}
void EQEQExp::inferType() {
    DataType::DataType expt1 = exp1->type;
    DataType::DataType expt2 = exp2->type;
    if (expt1 == DataType::NUMBER && expt2 == DataType::NUMBER) {
        type = DataType::BOOLEAN;
        return;
    }
    TypeError::terminate("Cannot EQEQ " + DataType::dataTypeStrings[exp1->type] + " and " + DataType::dataTypeStrings[exp2->type] + " together!");

}

std::unique_ptr<Exp> EQEQExp::eval() {
    if (!valKnown) return nullptr;
    std::unique_ptr<Exp> ret;
    if (exp1->type == DataType::NUMBER && exp2->type == DataType::NUMBER) {
        int a = std::stoi(exp1->genCode());
        int b = std::stoi(exp2->genCode());
        ret = std::make_unique<BoolLit> (a==b);
    }
    return ret;
}

std::unique_ptr<Exp> EQEQExp::clone() {
    std::unique_ptr<Exp> clone1 = this->exp1->clone();
    std::unique_ptr<Exp> clone2 = this->exp2->clone();
    return std::make_unique<EQEQExp>(clone1, clone2);
}