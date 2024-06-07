#include "UnaryExp.h"

UnaryExp::UnaryExp(std::unique_ptr<Exp>& exp1) : exp1(std::move(exp1)) {
    inferType();
}