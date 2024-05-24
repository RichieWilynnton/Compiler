#ifndef PARSER_H
#define PARSER_H

#include "Token.h"
#include "./AstNodes/Program.h"
#include "./AstNodes/ASTNode.h"
#include "Tokentype.h"

#include <vector>
#include <string>

class Parser {
public:
    Token curToken;
    int curPos;
    std::vector<Token> tokens;

    Parser(std::vector<Token> tokenList);
    Program getParseTree();
    ASTNode getStatement();
    void validateToken(Token token, TokenType type);
    void nextToken();
    Token peek();
    void terminate(std::string msg);

    
};
#endif