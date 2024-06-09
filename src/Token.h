#ifndef TOKEN_H
#define TOKEN_H

#include "Tokentype.h"

#include <string>

struct Token {
    std::string content;
    TokenType::TokenType tokenType;

    Token(std::string content = "", TokenType::TokenType tokenType = TokenType::INVALID) : content(content), tokenType(tokenType) {}

    bool operator== (const Token& t2) {
        return (content == t2.content) && (tokenType == t2.tokenType);
    }
};

#endif
