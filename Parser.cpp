    #include "Parser.h"
    #include "Tokentype.h"
    #include "Lexer.h"
    #include "./AstNodes/Program.h"
    #include "Tokentype.h"
    #include "Token.h"
    #include "./Utils/TokenUtils.h"
    #include "./Statement/Assignment.h"
    #include "../AstNodes/Exp.h"
    #include "../AstNodes/NumLit.h"
    #include "../AstNodes/VarLit.h"
    #include "../AstNodes/BinaryExp/PlusExp.h"
    #include "../AstNodes/BinaryExp/MinusExp.h"
    #include "../AstNodes/BinaryExp/MultExp.h"
    #include "../AstNodes/BinaryExp/DivExp.h"

    #include <vector>
    #include <iostream>

    #define UNARY_OPS unordered_set<TokenType> {MINUS, NOT}
    #define BINARY_OPS unordered_set<TokenType> {ADD, MINUS, MULT, DIV, GT, GTEQ, LT, LTEQ, EQEQ, NOTEQ}

    Parser::Parser(std::vector<Token> tokenList) {
        tokens = tokenList;
        // curToken has default value
        curPos = -1;

        nextToken();
    }

    Program* Parser::getParseTree() {
        Program* program = new Program();
        
        while (curToken.tokenType != EOF) {
            ASTNode* statement = getStatement();
            program->addStatement(statement);
        }
    }

    ASTNode* Parser::getStatement() {
        ASTNode* ret;
        switch (curToken.tokenType) {
            case LET:
            {
                std::string variable;
                nextToken();
                validateToken(curToken, IDENTIFIER);
                variable = curToken.content;
                nextToken();
                validateToken(curToken, EQ);
                Exp* exp = parseExpression();
                ret = new Assignment(variable, exp);
                break;
            }
            default:
                break;
        }
    }

    // When do we know when to stop parsing expression?
    // 1. Newline found
    // 2. Comma found (eg. exp1, exp2, ...)
    Exp* Parser::parseExpression(){
        Exp* a = parseTerm();
        while (true) {
            if (curToken.tokenType == PLUS) { 
                Exp* b = parseTerm();
                a = new PlusExp(a, b);
            }
            else if (curToken.tokenType == MINUS) {
                Exp* b = parseFactor();
                a = new MinusExp(a, b);
            }
            else return a;
        }
        
    }
    // Term := Factor | Factor "*" Factor "*" ... | Factor "/" Factor "/" ...
    Exp* Parser::parseTerm(){
        Exp* a = parseFactor();
        while (true) {
            if (curToken.tokenType == MULT) { 
                Exp* b = parseFactor();
                a = new MultExp(a, b);
            }
            else if (curToken.tokenType == DIV) {
                Exp* b = parseFactor();
                a = new DivExp(a, b);
            }
            else return a;
        }
        
    }
        
    // Factor := Number | Identifier | "(" Expression ")"
    Exp* Parser::parseFactor() {
        Exp* ret;
        switch (curToken.tokenType) {
            case NUMBER:
                ret = new NumLit(curToken.content);
            case IDENTIFIER:
                ret = new VarLit(curToken.content);
            case OPEN_ROUND_BRACKET:
                nextToken();
                Exp* a = parseExpression();
                if (a == nullptr) return nullptr;  
                if (curToken.tokenType == CLOSED_ROUND_BRACKET) {
                    ret = a;
                }
                else terminate("Unclosed bracket detected");
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
