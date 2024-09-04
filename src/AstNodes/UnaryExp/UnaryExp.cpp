#include "./UnaryExp.h"

void UnaryExp::init() {
    inferType();
    valKnown = this->exp1->valKnown;
}