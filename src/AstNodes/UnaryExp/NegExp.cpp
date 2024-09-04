#include "NegExp.h"
#include "../DataType.h"
#include "../TypeError.h"
#include "../Lit/NumLit.h"

#include <string>

std::string NegExp::genCode() {
    return "(-" + exp1->genCode() + ")";
}

std::string NegExp::printNode() {
    return "NEG (" + exp1->printNode() + ')';
}

void NegExp::inferType() {
    DataType::DataType expt1= exp1->type;
    if (expt1 != DataType::NUMBER) TypeError::terminate("Cannot NEG " + DataType::dataTypeStrings[expt1] + "!");
    type = DataType::NUMBER;
}

std::unique_ptr<Exp> NegExp::eval() {
    if (!valKnown) return nullptr;
    std::unique_ptr<Exp> ret;
    if (type == DataType::NUMBER) {
        int a = std::stoi(exp1->genCode());
        ret = std::make_unique<NumLit> (std::to_string(-a));
    }
    return ret;
}

std::unique_ptr<Exp> NegExp::clone() {
    std::unique_ptr<Exp> clone1 = this->exp1->clone();
    return std::make_unique<NegExp>(clone1);
}