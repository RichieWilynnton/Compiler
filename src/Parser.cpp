    #include "Parser.h"
    #include "Tokentype.h"
    #include "Lexer.h"
    #include "./AstNodes/ASTNode.h"
    #include "./AstNodes/Program.h"
    #include "Tokentype.h"
    #include "Token.h"
    #include "./Utils/TokenUtils.h"
    #include "./AstNodes/Statement/Assignment.h"
    #include "./AstNodes/Exp.h"
    #include "./AstNodes/Lit/NumLit.h"
    #include "./AstNodes/Lit/VarLit.h"
    #include "./AstNodes/BinaryExp/PlusExp.h"
    #include "./AstNodes/BinaryExp/MinusExp.h"
    #include "./AstNodes/BinaryExp/MultExp.h"
    #include "./AstNodes/BinaryExp/DivExp.h"

    #include <vector>
    #include <iostream>
    #include <memory>

    #define UNARY_OPS unordered_set<TokenType> {MINUS, NOT}
    #define BINARY_OPS unordered_set<TokenType> {ADD, MINUS, MULT, DIV, GT, GTEQ, LT, LTEQ, EQEQ, NOTEQ}

    Parser::Parser(std::vector<Token>& tokenList) {
        tokens = tokenList;
        // curToken has default value
        curPos = -1;

        nextToken();
    }

    std::unique_ptr<Program> Parser::getParseTree() {
        std::unique_ptr<Program> program = std::make_unique<Program>();
        
        while (curToken.tokenType != EOF) {
            std::unique_ptr<ASTNode> statement = getStatement();
            program->addStatement(statement);
        }

        return program;
    }

    std::unique_ptr<ASTNode> Parser::getStatement() {
        std::unique_ptr<ASTNode> ret;
        switch (curToken.tokenType) {
            case LET:
            {
                std::string variable;
                nextToken();
                validateToken(curToken, IDENTIFIER);
                variable = curToken.content;
                nextToken();
                validateToken(curToken, EQ);
                std::unique_ptr<Exp> exp = parseExpression();
                ret = std::make_unique<Assignment> (variable, exp);
                break;
            }
            default:
                ret = parseExpression();
                break;
        }
        return ret;
    }

    // When do we know when to stop parsing expression?
    // 1. Newline found
    // 2. Comma found (eg. exp1, exp2, ...)
    std::unique_ptr<Exp> Parser::parseExpression(){
        std::unique_ptr<Exp> a = parseTerm();
        while (true) {
            if (curToken.tokenType == PLUS) { 
                std::unique_ptr<Exp> b = parseTerm();
                a = std::make_unique<PlusExp> (a,b);
            }
            else if (curToken.tokenType == MINUS) {
                std::unique_ptr<Exp> b = parseFactor();
                a = std::make_unique<MinusExp> (a,b);
            }
            else return a;
        }
        
    }
    // Term := Factor | Factor "*" Factor "*" ... | Factor "/" Factor "/" ...
    std::unique_ptr<Exp> Parser::parseTerm(){
        std::unique_ptr<Exp> a = parseFactor();
        while (true) {
            if (curToken.tokenType == MULT) { 
                std::unique_ptr<Exp> b = parseFactor();
                a = std::make_unique<MultExp> (a,b);
            }
            else if (curToken.tokenType == DIV) {
                std::unique_ptr<Exp> b = parseFactor();
                a = std::make_unique<DivExp> (a,b);
            }
            else return a;
        }
        
    }
        
    // Factor := Number | Identifier | "(" Expression ")"
    std::unique_ptr<Exp> Parser::parseFactor() {
        std::unique_ptr<Exp> ret;
        switch (curToken.tokenType) {
            case NUMBER:
                ret = std::make_unique<NumLit> (curToken.content);
                break;
            case IDENTIFIER:
                ret = std::make_unique<VarLit> (curToken.content);
                break;
            case OPEN_ROUND_BRACKET:
                nextToken();
                std::unique_ptr<Exp> ret = parseExpression();
                if (curToken.tokenType != CLOSED_ROUND_BRACKET) {
                    terminate("Unclosed bracket detected");
                }
                break;
        }
        nextToken();
        return ret;
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
        std::cerr << "Error during parsing: " + msg << std::endl;
        exit(EXIT_FAILURE);
    }
