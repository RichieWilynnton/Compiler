#ifndef PARSER_H
#define PARSER_H

#include "Token.h"
#include "./AstNodes/Program.h"
#include "./AstNodes/ASTNode.h"
#include "./AstNodes/Exp.h"
#include "./AstNodes/Block.h"
#include "Tokentype.h"
#include "Scope.h"

#include <vector>
#include <string>
#include <memory>

class Parser {
public:
    Token curToken;
    int curPos;
    std::unique_ptr<Scope> curScope;

    std::vector<Token> tokens;

    Parser(std::vector<Token>& tokenList);
    std::unique_ptr<Program> getParseTree();

    std::unique_ptr<ASTNode> getStatement();
    std::unique_ptr<Exp> parseExpression();
    std::unique_ptr<Exp> parseTerm();
    std::unique_ptr<Exp> parseFactor();
    std::unique_ptr<Block> parseBlock();

    void validateToken(TokenType::TokenType type);
    void nextToken();
    void skipNewlines();
    void newScope();
    void leaveScope();
    void terminate(std::string msg);

};
#endif