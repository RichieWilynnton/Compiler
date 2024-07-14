#include "GTEQExp.h"
#include "../DataType.h"
#include "../TypeError.h"
#include "../Lit/BoolLit.h"
#include <string>

std::string GTEQExp::genCode() {
    return "(" + exp1->genCode() + ">=" + exp2->genCode() + ")";
}
std::string GTEQExp::printNode() {
    return "GTEQ (" + exp1->printNode() + ", " + exp2->printNode() + ')';
}
void GTEQExp::inferType() {
    DataType::DataType expt1 = exp1->type;
    DataType::DataType expt2 = exp2->type;

    if (expt1 == DataType::NUMBER && expt2 == DataType::NUMBER) {
        type = DataType::BOOLEAN;
        return;
    }
    TypeError::terminate("Cannot GTEQ " + DataType::dataTypeStrings[exp1->type] + " and " + DataType::dataTypeStrings[exp2->type] + " together!");

}
std::unique_ptr<Exp> GTEQExp::eval() {
    if (!optimizable) return nullptr;
    std::unique_ptr<Exp> ret;
    if (exp1->type == DataType::NUMBER && exp2->type == DataType::NUMBER) {
        int a = std::stoi(exp1->genCode());
        int b = std::stoi(exp2->genCode());
        ret = std::make_unique<BoolLit> (a>=b);
    }
    return ret;
}