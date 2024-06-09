#include "NumLit.h"

#include <string>

NumLit::NumLit(std::string content = "") : content(content) {
    inferType();
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