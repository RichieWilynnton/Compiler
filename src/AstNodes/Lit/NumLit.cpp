#include "NumLit.h"
#include "../Exp.h"

#include <string>
#include <memory>

NumLit::NumLit(std::string content = "") : content(content) {
    inferType();
    valKnown = true;
}

std::string NumLit::genCode() {
    return content;
}

std::string NumLit::printNode() {
    return "(NumLit " + content + ')';
}

void NumLit::inferType() { 
    type = DataType::NUMBER;    
}

std::unique_ptr<Exp> NumLit::clone() {
    return std::make_unique<NumLit>(this->content);
}