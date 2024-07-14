#include "PlusExp.h"
#include "../Lit/NumLit.h"
#include "../Lit/BoolLit.h"
#include "../DataType.h"
#include "../TypeError.h"
#include "../Exp.h"
#include <string>

std::string PlusExp::genCode() {
    if (type == DataType::STRING) return "( concatString( " + exp1->genCode() + ", " + exp2->genCode() + " ))";
    return "(" + exp1->genCode() + " + " + exp2->genCode() + ")";
}

std::string PlusExp::printNode() {
    return "PLUS (" + exp1->printNode() + ", " + exp2->printNode() + ')';
}

void PlusExp::inferType() {
    DataType::DataType expt1 = exp1->type;
    DataType::DataType expt2 = exp2->type;

    if (expt1 == DataType::NUMBER && expt2 == DataType::NUMBER) {
        type = DataType::NUMBER;
        return;
    }
    if (expt1 == DataType::STRING && expt2 == DataType::STRING) {
        type = DataType::STRING;
        return;
    }
    TypeError::terminate("Cannot PLUS " + DataType::dataTypeStrings[exp1->type] + " and " + DataType::dataTypeStrings[exp2->type] + " together!");
}

std::unique_ptr<Exp> PlusExp::eval() {
    if (!optimizable) return nullptr;
    std::unique_ptr<Exp> ret;
    if (type == DataType::NUMBER) {
        int a = std::stoi(exp1->genCode());
        int b = std::stoi(exp2->genCode());
        ret = std::make_unique<NumLit> (std::to_string(a+b));
    }
    return ret;
}
