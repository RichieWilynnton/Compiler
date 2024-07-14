#include "./BinaryExp.h"
#include <iostream>

void BinaryExp::init() {
    inferType();
    optimizable = this->exp1->optimizable && this->exp2->optimizable;
}

