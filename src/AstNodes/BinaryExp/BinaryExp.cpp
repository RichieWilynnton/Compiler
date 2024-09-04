#include "./BinaryExp.h"
#include <iostream>

void BinaryExp::init() {
    inferType();
    valKnown = this->exp1->valKnown && this->exp2->valKnown;
}

