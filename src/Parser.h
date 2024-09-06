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

    std::vector<std::string> topLevelFunctions;

    Parser(std::vector<Token>& tokenList);
    std::unique_ptr<Program> getParseTree();
    std::vector<std::string> getTopLevelFunctions();

    std::unique_ptr<ASTNode> getStatement();
    std::unique_ptr<Exp> parseTop();
    std::unique_ptr<Exp> parseLevel0();
    std::unique_ptr<Exp> parseLevel1();
    std::unique_ptr<Exp> parseLevel2();
    std::unique_ptr<Exp> parseLevel3();
    std::unique_ptr<Exp> parseLevel4();
    std::unique_ptr<Block> parseBlock();
    DataType::DataType parseType();

    void validateToken(TokenType::TokenType type);
    void nextToken();
    void repositionToken(int index);
    void skipNewlines();
    void newScope();
    void leaveScope();
    void terminate(std::string msg);

};
#endif