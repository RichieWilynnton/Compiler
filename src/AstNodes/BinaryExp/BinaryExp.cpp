#include "BinaryExp.h"

BinaryExp::BinaryExp(std::unique_ptr<Exp>& exp1, std::unique_ptr<Exp>& exp2) : exp1(std::move(exp1)), exp2(std::move(exp2)) {
    inferType();
}
