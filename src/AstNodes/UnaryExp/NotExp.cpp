#include "NotExp.h"
#include "../DataType.h"
#include "../Lit/NumLit.h"
#include "../TypeError.h"
#include "../Lit/BoolLit.h"

#include <string>

std::string NotExp::genCode() {
    return "(!" + exp1->genCode() + ")";
}

std::string NotExp::printNode() {
    return "NOT (" + exp1->printNode() + ')';
}

void NotExp::inferType() {
    DataType::DataType expt1= exp1->type;
    if (expt1 != DataType::BOOLEAN) TypeError::terminate("Cannot NOT " + DataType::dataTypeStrings[expt1] + "instead!");
    type = DataType::BOOLEAN;
}

std::unique_ptr<Exp> NotExp::eval() {
    if (!optimizable) return nullptr;
    std::unique_ptr<Exp> ret;
    if (type == DataType::BOOLEAN) {
        bool a = exp1->genCode() == "true" ? true : false;
        ret = std::make_unique<BoolLit> (a);
    }
    return ret;
}