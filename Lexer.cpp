#include "Lexer.h"
#include "Tokentype.h"
#include "Token.h"
#include "Keywords.h"
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

Token Lexer::getToken() {
    skipWhitespace();
    skipComment();

    Token token, defaultToken;

    switch (curChar) {
        case '+':
            token = Token("+", TokenType::PLUS);
            break;
        case '-':
            token = Token("-", TokenType::MINUS);
            break;
        case '*':
            token = Token("*", TokenType::ASTERISK);
            break;
        case '/':
            token = Token("/" ,TokenType::SLASH);
            break;
        case '=':
            if (peek() == '=') {
                nextChar();
                token = Token("==" ,TokenType::EQEQ);
            }
            else token = Token("=" ,TokenType::EQ);
            break;
        case '!':
            if (peek() == '=') {
                nextChar();
                token = Token("!=" ,TokenType::NOTEQ);
            }
            else terminate("! is not a valid expression");
            break;
        case '>':
            if (peek() == '=') {
                nextChar();
                token = Token(">=" ,TokenType::GTEQ);
            }
            else token = Token(">" ,TokenType::GT);
            break;
        case '<':
            if (peek() == '=') {
                nextChar();
                token = Token("<=" ,TokenType::LTEQ);
            }
            else token = Token("<" ,TokenType::LT);
            break;

        case '\n':
            token = Token("\n" ,TokenType::NEWLINE);
            break;
        case '\0':
            token = Token("\0" ,TokenType::_EOF);
            break;
        default:
            break;
    }

    if (token == defaultToken) {
        // strings
        if (curChar == '"') {
            nextChar();
            int charCount = 0, startPos = curPos;

            while (curChar != '"') {
                // illegal characters
                if (curChar == '\0' || curChar == '\n') {
                    terminate("Illegal Characters in string.");
                }
                charCount++;
                nextChar();
            }

            token = Token(codeString.substr(startPos, charCount), TokenType::STRING);
        }

        // numbers
        else if (isdigit(curChar)) {
            int charCount = 0, startPos = curPos;
            while (isdigit(peek())) {
                charCount++;
                nextChar();
            };
            if (peek() == '.') {
                charCount++;
                nextChar();

                if (!isdigit(peek())) terminate("Invalid Number");
                while (isdigit(peek())) {
                    charCount++;
                    nextChar();
                }
            }
            token = Token(codeString.substr(startPos, charCount), TokenType::NUMBER);
        }

        // Identifiers
        else if (isalnum(curChar)) {
            int charCount = 0, startPos = curPos;
            while (isalnum(peek())) {
                charCount++;
                nextChar();
            }

            string tokenText = codeString.substr(startPos, charCount);
            TokenType keyword = checkIfKeyword(tokenText);
            if (keyword == TokenType::INVALID) token = Token(tokenText, TokenType::IDENTIFIER);
            else token = Token(tokenText, keyword); 
        }

        // error
        else {
            terminate("Invalid character encountered " + curChar);
        }
    }

    nextChar();

    return token;
}



void Lexer::skipWhitespace() {
    while (curChar == ' ' || curChar == '\t' || curChar == '\r') nextChar();
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

