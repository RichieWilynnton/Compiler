#include "Lexer.h"
#include "Tokentype.h"
#include <string>
#include <stdexcept>
using namespace std;
#include <iostream>

Lexer:: Lexer(std::string code) {
    codeString = code + '\n';
    curChar = ' ';
    curPos = -1;
    nextChar();
};

void Lexer:: nextChar() {
    curPos += 1;
    if (curPos >= codeString.size()) {
        curChar = '\0';
    }
    else {
        curChar = codeString[curPos];
    }
}

char Lexer:: peek() {
    if (curPos + 1 >= codeString.size()) return '\0';
    return codeString[curPos+1];
}

int Lexer::getToken() {
    int token = INT_MAX;
    switch (curChar) {
        case '+':
            token = TokenType::PLUS;
            break;
        case '-':
            token = TokenType::MINUS;
            break;
        case '*':
            token = TokenType::ASTERISK;
            break;
        case '/':
            token = TokenType::SLASH;
            break;
        case '\n':
            token = TokenType::NEWLINE;
            break;
        case '\0':
            token = TokenType::_EOF;
            break;
        default:
            throw std::invalid_argument("Invalid character encountered");
    }

    nextChar();

    return token;
}




// Lexer:: 

// char nextChar();
//     char peek();
//     void exit();
//     void skipWhitespace();
//     void skipComment();
//     void getToken();