#include "OrExp.h"
#include "../Lit/BoolLit.h"
#include "../DataType.h"
#include "../TypeError.h"
#include <string>

std::string OrExp::genCode() {
    return "(" + exp1->genCode() + "&&" + exp2->genCode() + ")";
}
std::string OrExp::printNode() {
    return "AND (" + exp1->printNode() + ", " + exp2->printNode() + ')';
}
void OrExp::inferType() {
    DataType::DataType expt1 = exp1->type;
    DataType::DataType expt2 = exp2->type;

    if (expt1 == DataType::BOOLEAN && expt2 == DataType::BOOLEAN) {
        type = DataType::BOOLEAN;
        return;
    }
    TypeError::terminate("Cannot OR " + DataType::dataTypeStrings[exp1->type] + " and " + DataType::dataTypeStrings[exp2->type] + " together!");

}
std::unique_ptr<Exp> OrExp::eval() {
    if (!valKnown) return nullptr;
    std::unique_ptr<Exp> ret;
    if (type == DataType::BOOLEAN) {
        bool a = exp1->genCode() == "true" ? true : false;
        bool b = exp2->genCode() == "true" ? true : false;
        ret = std::make_unique<BoolLit> (a&&b);
    }
    return ret;
}

std::unique_ptr<Exp> OrExp::clone() {
    std::unique_ptr<Exp> clone1 = this->exp1->clone();
    std::unique_ptr<Exp> clone2 = this->exp2->clone();
    return std::make_unique<OrExp>(clone1, clone2);
}