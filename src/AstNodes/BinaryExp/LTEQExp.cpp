#include "LTEQExp.h"
#include "../DataType.h"
#include "../TypeError.h"
#include "../Lit/BoolLit.h"
#include <string>

std::string LTEQExp::genCode() {
    return "(" + exp1->genCode() + "<=" + exp2->genCode() + ")";
}
std::string LTEQExp::printNode() {
    return "LTEQ (" + exp1->printNode() + ", " + exp2->printNode() + ')';
}
void LTEQExp::inferType() {
    DataType::DataType expt1 = exp1->type;
    DataType::DataType expt2 = exp2->type;

    if (expt1 == DataType::NUMBER && expt2 == DataType::NUMBER) {
        type = DataType::BOOLEAN;
        return;
    }
    TypeError::terminate("Cannot LTEQ " + DataType::dataTypeStrings[exp1->type] + " and " + DataType::dataTypeStrings[exp2->type] + " together!");

}
std::unique_ptr<Exp> LTEQExp::eval() {
    if (!optimizable) return nullptr;
    std::unique_ptr<Exp> ret;
    if (exp1->type == DataType::NUMBER && exp2->type == DataType::NUMBER) {
        int a = std::stoi(exp1->genCode());
        int b = std::stoi(exp2->genCode());
        ret = std::make_unique<BoolLit> (a<=b);
    }
    return ret;
}