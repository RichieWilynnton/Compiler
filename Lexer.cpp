#include "Lexer.h"
#include "Tokentype.h"
#include <string>
#include <stdexcept>
using namespace std;
#include <iostream>
#define db cout << "debug" << endl;

Lexer:: Lexer(std::string code) {
    codeString = code + '\n'; // \n to deal with whitespaces & comments at end of program
    curChar = ' '; // Placeholder
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
    skipWhitespace();
    skipComment();

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
            string msg = "Invalid character encountered " + curChar;
            terminate(msg);
    }

    nextChar();

    return token;
}

void Lexer::skipWhitespace() {
    while (curChar == ' ' && curChar == '\t' && curChar == '\r') nextChar();
}

void Lexer::skipComment() {
    if (curChar == '#') {
        while (curChar != '\n') nextChar(); 
    }
}

void Lexer::terminate(std::string msg) {
    std::cerr << "Error during lexical analysis: " + msg << std::endl;
    exit(EXIT_FAILURE);
}

