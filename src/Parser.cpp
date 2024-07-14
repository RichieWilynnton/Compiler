#include "Parser.h"
#include "Tokentype.h"
#include "Lexer.h"
#include "./AstNodes/ASTNode.h"
#include "./AstNodes/Program.h"
#include "Token.h"
#include "./AstNodes/DataType.h"
#include "./Utils/TokenUtils.h"
#include "./AstNodes/Statement/Assignment.h"
#include "./AstNodes/Statement/While.h"
#include "./AstNodes/Statement/For.h"
#include "./AstNodes/Statement/If.h"
#include "./AstNodes/Exp.h"
#include "./AstNodes/Lit/NumLit.h"
#include "./AstNodes/Lit/VarLit.h"
#include "./AstNodes/Lit/StringLit.h"
#include "./AstNodes/Lit/BoolLit.h"
#include "./AstNodes/BinaryExp/PlusExp.h"
#include "./AstNodes/BinaryExp/MinusExp.h"
#include "./AstNodes/BinaryExp/MultExp.h"
#include "./AstNodes/BinaryExp/DivExp.h"
#include "./AstNodes/BinaryExp/AndExp.h"
#include "./AstNodes/BinaryExp/OrExp.h"
#include "./AstNodes/BinaryExp/EQEQExp.h"
#include "./AstNodes/BinaryExp/LTExp.h"
#include "./AstNodes/BinaryExp/LTEQExp.h"
#include "./AstNodes/BinaryExp/GTExp.h"
#include "./AstNodes/BinaryExp/GTEQExp.h"
#include "./AstNodes/UnaryExp/NegExp.h"
#include "./AstNodes/UnaryExp/NotExp.h"
#include "./AstNodes/FunctionExp/PrintExp.h"
#include "./AstNodes/Block.h"
#include "DataType.h"

#include <vector>
#include <iostream>
#include <memory>
#include <stdexcept>

Parser::Parser(std::vector<Token>& tokenList) {
    tokens = tokenList;
    curPos = -1;
    curScope = std::make_unique<Scope> ();

    nextToken();
}

std::unique_ptr<Program> Parser::getParseTree() {
    std::unique_ptr<Program> program = std::make_unique<Program>();
    
    while (curToken.tokenType != TokenType::_EOF) {
        std::unique_ptr<ASTNode> statement = getStatement();
        if (statement) program->addStatement(statement);
        skipNewlines();

    }
    return program;
}

std::unique_ptr<ASTNode> Parser::getStatement() {
    std::unique_ptr<ASTNode> ret = nullptr;
    switch (curToken.tokenType) {
        case TokenType::LET:
        {
            std::string variable;
            TokenType::TokenType operation;
            nextToken();
            validateToken(TokenType::IDENTIFIER);
            variable = curToken.content;
            nextToken();
            operation = curToken.tokenType;
            std::unique_ptr<Exp> exp;

            nextToken();

            bool alrDeclared;
            if (operation == TokenType::EQ) {
                exp = parseExpression();
                curScope->declareVariable(variable, exp->type);
                alrDeclared = false;
            }
            else if (operation == TokenType::ARROW) {
                exp = parseExpression();
                curScope->modifyVariable(variable, exp->type);
                alrDeclared = true;
            }
            else terminate("Invalid syntax for LET statement!");

            ret = std::make_unique<Assignment> (variable, exp, alrDeclared);

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
        case TokenType::WHILE:
        {
            nextToken();
            std::unique_ptr<Exp> cond = parseExpression();

            validateToken(TokenType::COLON);
            nextToken();
            
            skipNewlines();
            std::unique_ptr<Block> block = parseBlock();
            ret = std::make_unique<While> (cond, block);
            break;
        }
        case TokenType::IF:
        {
            nextToken();
            std::unique_ptr<Exp> cond = parseExpression();

            validateToken(TokenType::COLON);
            nextToken();

            skipNewlines();
            std::unique_ptr<Block> block = parseBlock();
            std::unique_ptr<Block> elseBlock = nullptr;
            skipNewlines();

            if (curToken.tokenType == TokenType::ELIF) {
                std::unique_ptr<Block> newBlock = std::make_unique<Block> ();
                // Evaluate ELIF like an IF, but now we add it to the elseBlock of this current IF
                curToken.tokenType = TokenType::IF;
                std::unique_ptr<ASTNode> statement = getStatement();
                newBlock->addStatement(statement);

                elseBlock = std::move(newBlock);
            }
            else if (curToken.tokenType == TokenType::ELSE) {
                nextToken();
                
                validateToken(TokenType::COLON);
                nextToken();

                skipNewlines();

                elseBlock = parseBlock();
            }

            ret = std::make_unique<If> (cond, block, elseBlock);
            break;
        }
        // hardcoded the syntax coz i can't be bothered
        case TokenType::FOR:
        {
            newScope();
            nextToken();

            validateToken(TokenType::LET);
            nextToken();

            validateToken(TokenType::IDENTIFIER);
            std::string varName = curToken.content;
            curScope->declareVariable(varName, DataType::NUMBER);
            std::unique_ptr<Exp> iteratorVar = parseFactor();

            validateToken(TokenType::ARROW);
            nextToken();

            std::unique_ptr<Exp> iteratorStart = parseExpression();

            validateToken(TokenType::TO);
            nextToken();
    
            std::unique_ptr<Exp> iteratorEnd = parseExpression();

            validateToken(TokenType::COLON);
            nextToken();
            skipNewlines();

            std::unique_ptr<Block> block = parseBlock();

            leaveScope();

            ret = std::make_unique<For> (iteratorVar, iteratorStart, iteratorEnd, block);
            break;
        }
        case TokenType::OPEN_CURLY_BRACKET:
        {
            ret = parseBlock();
            break;
        }
        case TokenType::NEWLINE:
            break;
            
        default:
            parseExpression();

    }
    return ret;
}

// Expression := Term | Term "+" Term "+" ... | Term "-" Term "-" ...
std::unique_ptr<Exp> Parser::parseExpression(){
    std::unique_ptr<Exp> a = parseTerm();

    
    // Can't make code neater coz I can't call nextToken() if there are no more operations
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
        else if (curToken.tokenType == TokenType::AND) {
            nextToken();
            std::unique_ptr<Exp> b = parseTerm();
            a = std::make_unique<AndExp> (a, b);
        }
        else if (curToken.tokenType == TokenType::OR) {
            nextToken();
            std::unique_ptr<Exp> b = parseTerm();
            a = std::make_unique<OrExp> (a, b);
        }
        else return a;

        a->init();
        if (a->optimizable) a = a->eval();
    }
}

// Term := Factor | Factor "*" Factor "*" ... | Factor "/" Factor "/" ... | Factor "<" Factor  
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


        // Wrong Precedence (will fix latr)
        // else if (curToken.tokenType == TokenType::EQEQ) {
        //     nextToken();
        //     std::unique_ptr<Exp> b = parseFactor();
        //     a = std::make_unique<EQEQExp> (a, b);
        // }
        // else if (curToken.tokenType == TokenType::LT) {
        //     nextToken();
        //     std::unique_ptr<Exp> b = parseFactor();
        //     a = std::make_unique<LTExp> (a, b);
        // }
        // else if (curToken.tokenType == TokenType::LTEQ) {
        //     nextToken();
        //     std::unique_ptr<Exp> b = parseFactor();
        //     a = std::make_unique<LTEQExp> (a, b);
        // }
        // else if (curToken.tokenType == TokenType::GT) {
        //     nextToken();
        //     std::unique_ptr<Exp> b = parseFactor();
        //     a = std::make_unique<GTExp> (a, b);
        // }
        // else if (curToken.tokenType == TokenType::GTEQ) {
        //     nextToken();
        //     std::unique_ptr<Exp> b = parseFactor();
        //     a = std::make_unique<GTEQExp> (a, b);
        // }
        else return a;

        a->init();
        if (a->optimizable) a = a->eval();
    }
}

// Factor := Number | Identifier | "(" Expression ")" | NegExp Factor | NotExp Factor | True | False
std::unique_ptr<Exp> Parser::parseFactor() {
    std::unique_ptr<Exp> ret;
    switch (curToken.tokenType) {
        case TokenType::NUMBER:
            ret = std::make_unique<NumLit> (curToken.content);
            nextToken();
            break;
        case TokenType::IDENTIFIER:
        {
            std::optional<DataType::DataType> o_varType = curScope->getVarInfo(curToken.content);
            if (o_varType) ret = std::make_unique<VarLit> (curToken.content, o_varType.value());
            else terminate("Undeclared variable");
            nextToken();
            break;
        }
            
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
        case TokenType::NOT:
        {
            nextToken();
            std::unique_ptr<Exp> a = parseFactor();
            ret = std::make_unique<NotExp> (a);
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
            terminate("Syntax Error! " + curToken.content);
    }

    return ret;
}

std::unique_ptr<Block> Parser::parseBlock() {
    validateToken(TokenType::OPEN_CURLY_BRACKET);
    nextToken();
    newScope();

    std::unique_ptr<Block> newBlock = std::make_unique<Block> ();
    skipNewlines();
    while (curToken.tokenType != TokenType::CLOSED_CURLY_BRACKET) {
        if (curToken.tokenType == TokenType::_EOF) {
            terminate("Unclosed bracket!");
        }
        std::unique_ptr<ASTNode> statement = getStatement();
        newBlock->addStatement(statement);
        skipNewlines();
    }

    nextToken();
    leaveScope();
    return newBlock;
}

void Parser::validateToken(TokenType::TokenType type) {
    if (curToken.tokenType != type) {
        terminate("Expected " + TokenUtils::stringifyTokenType(type) + ", got " + TokenUtils::stringifyTokenType(curToken.tokenType) + " instead.");
    }
}

void Parser::skipNewlines() {
    if (curToken.tokenType == TokenType::_EOF) return;
    while (curToken.tokenType == TokenType::NEWLINE) {
        nextToken();
    }
}
void Parser::newScope() {
    curScope = curScope->enterNewScope(curScope);
}

void Parser::leaveScope() {
    curScope = curScope->exitScope();
}

void Parser::nextToken() {
    curPos += 1;
    curToken = tokens[curPos];
}

void Parser::terminate(std::string msg) {
    std::cerr << curPos << '\n';
    throw std::runtime_error("Error during parsing: " + msg);
}


