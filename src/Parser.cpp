#include "Parser.h"
#include "Tokentype.h"
#include "Lexer.h"
#include "./AstNodes/ASTNode.h"
#include "./AstNodes/Program.h"
#include "Token.h"
#include "./AstNodes/DataType.h"
#include "./Utils/TokenUtils.h"
#include "./AstNodes/Statement/Assignment.h"
#include "./AstNodes/Exp.h"
#include "./AstNodes/Lit/NumLit.h"
#include "./AstNodes/Lit/VarLit.h"
#include "./AstNodes/Lit/StringLit.h"
#include "./AstNodes/Lit/BoolLit.h"
#include "./AstNodes/BinaryExp/PlusExp.h"
#include "./AstNodes/BinaryExp/MinusExp.h"
#include "./AstNodes/BinaryExp/MultExp.h"
#include "./AstNodes/BinaryExp/DivExp.h"
#include "./AstNodes/UnaryExp/NegExp.h"
#include "./AstNodes/FunctionExp/PrintExp.h"
#include "DataType.h"

#include <vector>
#include <iostream>
#include <memory>

Parser::Parser(std::vector<Token>& tokenList) {
    tokens = tokenList;
    curPos = -1;

    nextToken();
}

std::unique_ptr<Program> Parser::getParseTree() {
    std::unique_ptr<Program> program = std::make_unique<Program>();
    
    while (curToken.tokenType != TokenType::_EOF) {
        std::unique_ptr<ASTNode> statement = getStatement();
        if (statement) program->addStatement(statement);
        // newline
        nextToken();
    }

    return program;
}

std::unique_ptr<ASTNode> Parser::getStatement() {
    std::unique_ptr<ASTNode> ret = nullptr;
    switch (curToken.tokenType) {
        case TokenType::LET:
        {
            std::string variable;
            nextToken();
            variable = validateToken(TokenType::IDENTIFIER).content;
            validateToken(TokenType::EQ);
            std::unique_ptr<Exp> exp = parseExpression();
            ret = std::make_unique<Assignment> (variable, exp);
            break;
        }
        // Print is the only exception when it comes to functions, rest gets evaluated in parseExpression
        case TokenType::PRINT:
        {
            nextToken();
            std::unique_ptr<Exp> exp = parseExpression();
            ret = std::make_unique<PrintExp> (exp);
            break;
        }
        default:
            parseExpression();

    }
    return ret;
}

// Expression := Term | Term "+" Term "+" ... | Term "-" Term "-" ...
std::unique_ptr<Exp> Parser::parseExpression(){
    std::unique_ptr<Exp> a = parseTerm();

    while (true) {
        if (curToken.tokenType == TokenType::PLUS) { 
            nextToken();
            std::unique_ptr<Exp> b = parseTerm();
            a = std::make_unique<PlusExp> (a, b);
        }
        else if (curToken.tokenType == TokenType::MINUS) {
            nextToken();
            std::unique_ptr<Exp> b = parseTerm();
            a = std::make_unique<MinusExp> (a, b);
        }
        else return a;
    }
}

// Term := Factor | Factor "*" Factor "*" ... | Factor "/" Factor "/" ...
std::unique_ptr<Exp> Parser::parseTerm() {
    std::unique_ptr<Exp> a = parseFactor();
    while (true) {
        if (curToken.tokenType == TokenType::MULT) { 
            nextToken();
            std::unique_ptr<Exp> b = parseFactor();
            a = std::make_unique<MultExp> (a, b);
        }
        else if (curToken.tokenType == TokenType::DIV) {
            nextToken();
            std::unique_ptr<Exp> b = parseFactor();
            a = std::make_unique<DivExp> (a, b);
        }
        else return a;
    }
}

// Factor := Number | Identifier | "(" Expression ")" | NegExp Factor
std::unique_ptr<Exp> Parser::parseFactor() {
    std::unique_ptr<Exp> ret;
    switch (curToken.tokenType) {
        case TokenType::NUMBER:
            ret = std::make_unique<NumLit> (curToken.content);
            nextToken();
            break;
        case TokenType::IDENTIFIER:
            ret = std::make_unique<VarLit> (curToken.content);
            nextToken();
            break;
        case TokenType::STRING:
            ret = std::make_unique<StringLit> (curToken.content);
            nextToken();
            break;
        case TokenType::OPEN_ROUND_BRACKET:
            nextToken();
            ret = parseExpression();
            if (curToken.tokenType != TokenType::CLOSED_ROUND_BRACKET) {
                terminate("Unclosed bracket detected");
            }
            nextToken();
            break;
        case TokenType::MINUS:
        {
            nextToken();
            std::unique_ptr<Exp> a = parseFactor();
            ret = std::make_unique<NegExp> (a);
            break;
        }
        case TokenType::TRUE:
            nextToken();
            ret = std::make_unique<BoolLit> (true);
            break;

        case TokenType::FALSE:
            nextToken();
            ret = std::make_unique<BoolLit> (false);
            break;

        default:
            terminate("Syntax Error!");
    }

    return ret;
}

Token Parser::validateToken(TokenType::TokenType type) {
    if (curToken.tokenType != type) {
        terminate("Expected " + TokenUtils::stringifyTokenType(type) + ", got " + TokenUtils::stringifyTokenType(curToken.tokenType) + " instead.");
    }
    Token save = curToken;
    nextToken();
    return save;
}

void Parser::nextToken() {
    curPos += 1;
    curToken = tokens[curPos];
}

void Parser::terminate(std::string msg) {
    std::cerr << "Error during parsing: " + msg << std::endl;
    exit(EXIT_FAILURE);
}
