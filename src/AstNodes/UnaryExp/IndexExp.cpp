#include "IndexExp.h"
#include "../DataType.h"
#include "../TypeError.h"
#include "../Lit/NumLit.h"

#include <string>

std::string IndexExp::genCode() {
    return exp1->genCode() + "[" + index->genCode() + "]";
}

std::string IndexExp::printNode() {
    return exp1->genCode() + "[" + index->genCode() + "]";
}

void IndexExp::inferType() {
    DataType::DataType expt1= exp1->type;
    if (expt1 != DataType::NUMBER) TypeError::terminate("Cannot Index " + DataType::dataTypeStrings[expt1] + "! Only ");
    type = DataType::NUMBER;
}

std::unique_ptr<Exp> IndexExp::eval() {
    if (!valKnown) return nullptr;
    std::unique_ptr<Exp> ret;
    if (type == DataType::NUMBER) {
        int a = std::stoi(exp1->genCode());
        ret = std::make_unique<NumLit> (std::to_string(-a));
    }
    return ret;
}

std::unique_ptr<Exp> IndexExp::clone() {
    std::unique_ptr<Exp> index = this->index->clone();
    return std::make_unique<IndexExp>();
}