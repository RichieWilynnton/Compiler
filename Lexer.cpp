#include "Lexer.h"
#include "Tokentype.h"
#include <string>
#include <stdexcept>
using namespace std;
#include <iostream>

Lexer:: Lexer(std::string code) {
    codeString = code + '\n';
    curChar = '\n';
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
        case '=':
            if (peek() == '=') {
                nextChar();
                token = TokenType::EQEQ;
            }
            else token = TokenType::EQ;
            break;
        case '!':
            if (peek() == '=') {
                nextChar();
                token = TokenType::NOTEQ;
            }
            else terminate("! is not a valid expression");
            break;
        case '>':
            if (peek() == '=') {
                nextChar();
                token = TokenType::GTEQ;
            }
            else token = TokenType::GT;
            break;
        case '<':
            if (peek() == '=') {
                nextChar();
                token = TokenType::LTEQ;
            }
            else token = TokenType::LT;
            break;

        case '\n':
            token = TokenType::NEWLINE;
            break;
        case '\0':
            token = TokenType::_EOF;
            break;
        default:
            terminate("Invalid character encountered");
    }

    nextChar();

    return token;
}

void Lexer::terminate(std::string msg) {
    std::cerr << "Error during lexical analysis: " + msg << std::endl;
    exit(EXIT_FAILURE);
}

