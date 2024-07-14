#include "./UnaryExp.h"

void UnaryExp::init() {
    inferType();
    optimizable = this->exp1->optimizable;
}