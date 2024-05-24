#include "Parser.h"
#include "Lexer.h"
#include "./AstNodes/Program.h"
#include "Tokentype.h"
#include "Token.h"
#include "./Utils/TokenUtils.h"

#include <vector>
#include <iostream>

Parser::Parser(std::vector<Token> tokenList) {
    tokens = tokenList;
    // curToken doesn't need to be inititalized because it already has default value
    curPos = -1;

    nextToken();
}

Program Parser::getParseTree() {
    Program program;
    
    while (curToken.tokenType != EOF) {
        ASTNode statement = getStatement();
        program.addStatement(statement);
    }
}

ASTNode Parser::getStatement() {
    
    switch (curToken.tokenType) {
        case LET:
            nextToken();
            validateToken(curToken, IDENTIFIER);
            nextToken();
            validateToken(curToken, EQ);
            // 
            break;
        default:
            break;
    }
}

void Parser::validateToken(Token token, TokenType type) {
    if (token.tokenType != type) {
        terminate("Expected " + TokenUtils::stringifyTokenType(type) + ", got " + TokenUtils::stringifyTokenType(token.tokenType) + " instead.");
    }
}

void Parser::nextToken() {
    curPos += 1;
    curToken = tokens[curPos];
}


void Parser::terminate(std::string msg) {
    std::cerr << "Error during lexical analysis: " + msg << std::endl;
    exit(EXIT_FAILURE);
}
