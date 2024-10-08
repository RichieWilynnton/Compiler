#include "StringLit.h"

#include <string>

StringLit::StringLit(std::string content = "") : content(content) {
    inferType();
}


std::string StringLit::genCode() {
    return "\"" + content + "\"";
}

std::string StringLit::printNode() {
    return "(StringLit \"" + content + "\")";
}

void StringLit::inferType() {
    type = DataType::STRING;
}

std::unique_ptr<Exp> StringLit::clone() {
    return std::make_unique<StringLit>(this->content);
}