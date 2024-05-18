#ifndef TOKEN_H
#define TOKEN_H

#include <string>

struct Token {
    std::string content;
    int tokenType;

    Token(std::string content = "", int tokenType = INT_MAX) : content(content), tokenType(tokenType) {}

    bool operator== (const Token& t2) {
        return (content == t2.content) && (tokenType == t2.tokenType);
    }
};

#endif
