#include "MultExp.h"
#include "../DataType.h"
#include "../Lit/NumLit.h"
#include "../TypeError.h"
#include <string>

std::string MultExp::genCode() {
    return "(" + exp1->genCode() + "*" + exp2->genCode() + ")";
}
std::string MultExp::printNode() {
    return "MULT (" + exp1->printNode() + ", " + exp2->printNode() + ')';
}
void MultExp::inferType() {
    DataType::DataType expt1 = exp1->type;
    DataType::DataType expt2 = exp2->type;

    if (expt1 == DataType::NUMBER && expt2 == DataType::NUMBER) {
        type = DataType::NUMBER;
        return;
    }
    TypeError::terminate("Cannot MULT " + DataType::dataTypeStrings[exp1->type] + " and " + DataType::dataTypeStrings[exp2->type] + " together!");


}
std::unique_ptr<Exp> MultExp::eval() {
    if (!optimizable) return nullptr;
    std::unique_ptr<Exp> ret;
    if (exp1->type == DataType::NUMBER && exp2->type == DataType::NUMBER) {
        int a = std::stoi(exp1->genCode());
        int b = std::stoi(exp2->genCode());
        ret = std::make_unique<NumLit> (std::to_string(a*b));
    }
    return ret;
}