#ifndef LEXER_H
#define LEXER_H

#include <string>
#include "Tokentype.h"
#include "Token.h"

class Lexer {
    public:

    std::string codeString;
    char curChar;
    int curPos;

        Lexer(std::string code);

        void nextChar();
        char peek();
        Token getToken();
        void skipWhitespace();
        void skipComment();
        void terminate(std::string msg);
};

#endif