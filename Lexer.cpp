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
            token = Token("+", PLUS);
            break;
        case '-':
            if (peek() == '>') {
                nextChar();
                token = Token("->", ARROW);
            }
            else token = Token("-", MINUS);
            break;
        case '*':
            token = Token("*", MULT);
            break;
        case '/':
            token = Token("/" ,DIV);
            break;
        case '=':
            if (peek() == '=') {
                nextChar();
                token = Token("==" ,EQEQ);
            }
            else token = Token("=" ,EQ);
            break;
        case '!':
            if (peek() == '=') {
                nextChar();
                token = Token("!=" ,NOTEQ);
            }
            else token = Token("!", NOT);
            break;
        case '>':
            if (peek() == '=') {
                nextChar();
                token = Token(">=" ,GTEQ);
            }
            else token = Token(">" ,GT);
            break;
        case '<':
            if (peek() == '=') {
                nextChar();
                token = Token("<=" ,LTEQ);
            }
            else token = Token("<" ,LT);
            break;
        case '(':
            token = Token("(", OPEN_ROUND_BRACKET);
            break;
        case ')':
            token = Token(")", CLOSED_ROUND_BRACKET);
            break;
        case '[':
            token = Token("[", OPEN_SQUARE_BRACKET);
            break;
        case ']':
            token = Token("]", CLOSED_SQUARE_BRACKET);
            break;
        case ';':
            token = Token(";", SEMICOLON);
            break;
        case ',':
            token = Token(",", COMMA);
            break;
        case '\n':
            token = Token("\n" ,NEWLINE);
            break;
        case '\0':
            token = Token("\0" ,_EOF);
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
                char next = peek();
                // illegal characters
                if (next == '\0' || next == '\n') {
                    terminate("Illegal Characters in string.");
                }
                charCount++;
                nextChar();
            }

            token = Token(codeString.substr(startPos, charCount), STRING);
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
            token = Token(codeString.substr(startPos, charCount+1), NUMBER);
        }

        // Identifiers
        else if (isalnum(curChar)) {
            int charCount = 0, startPos = curPos;
            while (isalnum(peek())) {
                charCount++;
                nextChar();
            }

            string tokenText = codeString.substr(startPos, charCount+1);

            TokenType keyword = checkIfKeyword(tokenText);
            if (keyword == INVALID) token = Token(tokenText, IDENTIFIER);
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

