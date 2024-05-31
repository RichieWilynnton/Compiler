#ifndef PARSER_H
#define PARSER_H

#include "Token.h"
#include "./AstNodes/Program.h"
#include "./AstNodes/ASTNode.h"
#include "./AstNodes/Exp.h"

#include "Tokentype.h"

#include <vector>
#include <string>
#include <memory>

class Parser {
public:
    Token curToken;
    int curPos;
    std::vector<Token> tokens;

    Parser(std::vector<Token>& tokenList);
    std::unique_ptr<Program> getParseTree();

    std::unique_ptr<ASTNode> getStatement();
    std::unique_ptr<Exp> parseExpression();
    std::unique_ptr<Exp> parseTerm();
    std::unique_ptr<Exp> parseFactor();
    void validateToken(Token token, TokenType type);
    void nextToken();
    void terminate(std::string msg);

};
#endif