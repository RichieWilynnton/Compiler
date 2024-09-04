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
#include "./AstNodes/Lit/ArrayLit.h"
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
// #include "./AstNodes/UnaryExp/IndexExp.h"
#include "./AstNodes/FunctionExp/PrintExp.h"
#include "./AstNodes/Block.h"
#include "./AstNodes/FreePtr.h"
#include "DataType.h"

#include <vector>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>
#include <algorithm>

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
    // clean up remaining pointers
    std::vector<std::unique_ptr<FreePtr>> freePtrs = curScope->getFreePtrs();
    for (int i=0; i<freePtrs.size(); i++) {
        std::unique_ptr<ASTNode> a = std::move(freePtrs[i]);
        program->addStatement(a);
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
                exp = parseTop();
                curScope->declareVariable(variable, exp->type, exp);
                alrDeclared = false;
            }
            else if (operation == TokenType::ARROW) {
                exp = parseTop();
                curScope->modifyVariable(variable, exp->type, exp);
                alrDeclared = true;
            }
            else terminate("Invalid syntax for LET statement!");

            ret = std::make_unique<Assignment> (variable, exp, alrDeclared);

            break;
        }
        // Print is the only exception when it comes to functions, rest gets evaluated in parseLevel2
        case TokenType::PRINT:
        {
            nextToken();
            std::unique_ptr<Exp> exp = parseTop();
            ret = std::make_unique<PrintExp> (exp);
            break;
        }
        case TokenType::WHILE:
        {
            nextToken();
            std::unique_ptr<Exp> cond = parseTop();

            skipNewlines();
            std::unique_ptr<Block> block = parseBlock();
            ret = std::make_unique<While> (cond, block);
            break;
        }
        case TokenType::IF:
        {
            nextToken();
            std::unique_ptr<Exp> cond = parseTop();

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
            std::unique_ptr<Exp> nullval = nullptr;
            curScope->declareVariable(varName, DataType::NUMBER, nullval);

            std::unique_ptr<Exp> iteratorVar = parseLevel4();

            validateToken(TokenType::EQ);
            nextToken();

            std::unique_ptr<Exp> iteratorStart = parseLevel2();

            validateToken(TokenType::TO);
            nextToken();
    
            std::unique_ptr<Exp> iteratorEnd = parseLevel2();
            skipNewlines();

            if (iteratorStart->type != DataType::NUMBER) terminate("Expected a number for For Loop starting iterator, got " + DataType::dataTypeStrings[iteratorStart->type]);
            if (iteratorStart->type != DataType::NUMBER) terminate("Expected a number for For Loop ending iterator, got " + DataType::dataTypeStrings[iteratorEnd->type]);
            
            // If loop is predictable, unroll the loop
            if (iteratorStart->valKnown && iteratorEnd->valKnown) {
                std::unique_ptr<Block> blocks = std::make_unique<Block> ();

                int forPos = curPos;
                int x1 = std::stoi(iteratorStart->genCode());
                int x2 = std::stoi(iteratorEnd->genCode());

                if (x1 < x2) {
                    for (int i=x1; i<x2; i++) {
                        newScope();
                        
                        std::unique_ptr<Exp> it = std::make_unique<NumLit> (std::to_string(i));
                        curScope->declareVariable(varName, DataType::NUMBER, it);
                        repositionToken(forPos);
                        std::unique_ptr<Block> block = parseBlock();
                        blocks->addBlock(block);

                        leaveScope();
                    }
                }
                else {
                    for (int i=x2; i>x1; i--) {
                        newScope();
                        
                        std::unique_ptr<Exp> it = std::make_unique<NumLit> (std::to_string(i));
                        curScope->declareVariable(varName, DataType::NUMBER, it);
                        repositionToken(forPos);
                        std::unique_ptr<Block> block = parseBlock();
                        blocks->addBlock(block);

                        leaveScope();
                    }
                }
                ret = std::move(blocks);
            }

            else {
                std::unique_ptr<Block> block = parseBlock();
                ret = std::make_unique<For> (iteratorVar, iteratorStart, iteratorEnd, block);
            }
           
            break;
        }
        case TokenType::OPEN_CURLY_BRACKET:
        {
            ret = parseBlock();
            break;
        }
        case TokenType::NEWLINE:
            break;
            
        // default:
            // parseLevel1();

    }
    return ret;
}

std::unique_ptr<Exp> Parser::parseTop() {
    std::vector<std::pair<TokenType::TokenType, std::unique_ptr<Exp>>> exps;

    exps.push_back({TokenType::OR, parseLevel0()});

    while (true) {
        TokenType::TokenType op = curToken.tokenType;
        if (op == TokenType::OR) {
            nextToken();
            exps.push_back({op, parseLevel0()});
        }
        else break;
    }

    std::sort(exps.begin(), exps.end(), [](const std::pair<TokenType::TokenType, std::unique_ptr<Exp>>& a, const std::pair<TokenType::TokenType, std::unique_ptr<Exp>>& b){
        return a.second->valKnown > b.second->valKnown; 
    });

    std::unique_ptr<Exp> a = std::move(exps[0].second);

    for (int i=1; i<exps.size(); i++) {
        if (exps[i].first == TokenType::OR) {
            a = std::make_unique<OrExp> (a, exps[i].second);
        }
        a->init();
        if (a->valKnown) a = a->eval();
    }
    
    return a;
}

std::unique_ptr<Exp> Parser::parseLevel0() {
    std::vector<std::pair<TokenType::TokenType, std::unique_ptr<Exp>>> exps;

    exps.push_back({TokenType::AND, parseLevel1()});

    while (true) {
        TokenType::TokenType op = curToken.tokenType;
        if (op == TokenType::AND) {
            nextToken();
            exps.push_back({op, parseLevel1()});
        }
        else break;
    }

    std::sort(exps.begin(), exps.end(), [](const std::pair<TokenType::TokenType, std::unique_ptr<Exp>>& a, const std::pair<TokenType::TokenType, std::unique_ptr<Exp>>& b){
        return a.second->valKnown > b.second->valKnown; 
    });

    std::unique_ptr<Exp> a = std::move(exps[0].second);

    for (int i=1; i<exps.size(); i++) {
        if (exps[i].first == TokenType::AND) {
            a = std::make_unique<AndExp> (a, exps[i].second);
        }
        a->init();
        if (a->valKnown) a = a->eval();
    }
    
    return a;
}


std::unique_ptr<Exp> Parser::parseLevel1() {
    std::unique_ptr<Exp> a = parseLevel2();

    while (true) {
        if (curToken.tokenType == TokenType::EQEQ) {
            nextToken();
            std::unique_ptr<Exp> b = parseLevel2();
            a = std::make_unique<EQEQExp> (a, b);
        }
        else if (curToken.tokenType == TokenType::LT) {
            nextToken();
            std::unique_ptr<Exp> b = parseLevel2();
            a = std::make_unique<LTExp> (a, b);
        }
        else if (curToken.tokenType == TokenType::LTEQ) {
            nextToken();
            std::unique_ptr<Exp> b = parseLevel2();
            a = std::make_unique<LTEQExp> (a, b);
        }
        else if (curToken.tokenType == TokenType::GT) {
            nextToken();
            std::unique_ptr<Exp> b = parseLevel2();
            a = std::make_unique<GTExp> (a, b);
        }
        else if (curToken.tokenType == TokenType::GTEQ) {
            nextToken();
            std::unique_ptr<Exp> b = parseLevel2();
            a = std::make_unique<GTEQExp> (a, b);
        }
        else return a;
    }
    a->init();
    if (a->valKnown) a = a->eval();
}

std::unique_ptr<Exp> Parser::parseLevel2() {
    std::vector<std::pair<TokenType::TokenType, std::unique_ptr<Exp>>> exps;

    exps.push_back({TokenType::PLUS, parseLevel3()});

    while (true) {
        TokenType::TokenType op = curToken.tokenType;
        if (op == TokenType::PLUS) {
            nextToken();
            exps.push_back({op, parseLevel3()});
        }
        else if (op == TokenType::MINUS) {
            nextToken();
            exps.push_back({op, parseLevel3()});
        }
        else break;
    }

    std::sort(exps.begin(), exps.end(), [](const std::pair<TokenType::TokenType, std::unique_ptr<Exp>>& a, const std::pair<TokenType::TokenType, std::unique_ptr<Exp>>& b){
        return a.second->valKnown > b.second->valKnown; 
    });

    std::unique_ptr<Exp> a = std::move(exps[0].second);
    if (exps[0].first == TokenType::MINUS) a = std::make_unique<NegExp> (a);

    for (int i=1; i<exps.size(); i++) {
        if (exps[i].first == TokenType::PLUS) {
            a = std::make_unique<PlusExp> (a, exps[i].second);
        }
        else if (exps[i].first == TokenType::MINUS) {
            a = std::make_unique<MinusExp> (a, exps[i].second);
        }
        a->init();
        if (a->valKnown) a = a->eval();
    }
    
    return a;
}

std::unique_ptr<Exp> Parser::parseLevel3() {
    std::unique_ptr<Exp> a = parseLevel4();
    while (true) {
        if (curToken.tokenType == TokenType::MULT) { 
            nextToken();
            std::unique_ptr<Exp> b = parseLevel4();
            a = std::make_unique<MultExp> (a, b);
        }
        else if (curToken.tokenType == TokenType::DIV) {
            nextToken();
            std::unique_ptr<Exp> b = parseLevel4();
            a = std::make_unique<DivExp> (a, b);
        }

        else return a;

        a->init();
        if (a->valKnown) a = a->eval();
    }
}

std::unique_ptr<Exp> Parser::parseLevel4() {
    std::unique_ptr<Exp> ret;
    switch (curToken.tokenType) {
        case TokenType::NUMBER:
            ret = std::make_unique<NumLit> (curToken.content);
            nextToken();
            break;
        case TokenType::IDENTIFIER:
        {
            std::optional<DataType::DataType> o_varType = curScope->lookupType(curToken.content);
            // Check whether previously declared
            if (o_varType) {
                std::unique_ptr<Exp> exp = curScope->lookupVal(curToken.content);
                // if value for variable is known, replace it with the known value
                if (exp) ret = std::move(exp);
                else ret = std::make_unique<VarLit> (curToken.content, o_varType.value());
                // ret = std::make_unique<VarLit> (curToken.content, o_varType.value());
            }
            else terminate("Undeclared variable");
            nextToken();

            // if (curToken.tokenType == TokenType::OPEN_SQUARE_BRACKET) {
            //     std::unique_ptr<Exp> index = parseLevel1();
            //     std::unique_ptr<IndexExp> indexedExp = std::make_unique<IndexExp> (ret);
            //     indexedExp->index = std::move(index);
            //     ret = std::move(indexedExp);

            //     validateToken(TokenType::CLOSED_SQUARE_BRACKET);
            //     nextToken();
            // }

            // Call function
            if (curToken.tokenType == TokenType::OPEN_ROUND_BRACKET) {

            }

            break;
        }

        case TokenType::LAMBDA:
            nextToken();
            validateToken(TokenType::OPEN_ROUND_BRACKET);
            nextToken();

            // if (curToken.tokenType != TokenType::CLOSED_ROUND_BRACKET) {
            //     std::unique_ptr<Exp> exp = parseLevel1();
            //     array->addItem(exp);
            //     while (curToken.tokenType != TokenType::CLOSED_SQUARE_BRACKET) {
            //         validateToken(TokenType::COMMA);
            //         nextToken();
            //         exp = parseLevel1();
            //         array->addItem(exp);          
            //     }
            //     nextToken();
            // }
            
        case TokenType::STRING:
            ret = std::make_unique<StringLit> (curToken.content);
            nextToken();
            break;
        case TokenType::OPEN_ROUND_BRACKET:
            nextToken();
            ret = parseTop();
            if (curToken.tokenType != TokenType::CLOSED_ROUND_BRACKET) {
                terminate("Unclosed bracket detected");
            }
            nextToken();
            break;

        case TokenType::OPEN_SQUARE_BRACKET:
        {
            nextToken();

            std::unique_ptr<ArrayLit> array = std::make_unique<ArrayLit> ();
            if (curToken.tokenType != TokenType::CLOSED_SQUARE_BRACKET) {
                std::unique_ptr<Exp> exp = parseTop();
                array->addItem(exp);
                while (curToken.tokenType != TokenType::CLOSED_SQUARE_BRACKET) {
                    validateToken(TokenType::COMMA);
                    nextToken();
                    exp = parseTop();
                    array->addItem(exp);          
                }
                nextToken();
            }

            ret = std::move(array);
            break;
        }

        case TokenType::MINUS:
        {
            nextToken();
            std::unique_ptr<Exp> a = parseLevel4();
            ret = std::make_unique<NegExp> (a);
            break;
        }
        case TokenType::NOT:
        {
            nextToken();
            std::unique_ptr<Exp> a = parseLevel4();
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
    skipNewlines();
    validateToken(TokenType::OPEN_CURLY_BRACKET);
    nextToken();
    newScope();

    std::unique_ptr<Block> block = std::make_unique<Block> ();
    skipNewlines();
    while (curToken.tokenType != TokenType::CLOSED_CURLY_BRACKET) {
        if (curToken.tokenType == TokenType::_EOF) {
            terminate("Unclosed bracket!");
        }
        std::unique_ptr<ASTNode> statement = getStatement();
        block->addStatement(statement);
        skipNewlines();
    }

    nextToken();
    std::vector<std::unique_ptr<FreePtr>> freePtrs = curScope->getFreePtrs();
    for (int i=0; i<freePtrs.size(); i++) {
        std::unique_ptr<ASTNode> a = std::move(freePtrs[i]);
        block->addStatement(a);
    }
 
    leaveScope();
    return block;
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

void Parser::repositionToken(int index) {
    curPos = index;
    curToken = tokens[index];
}

void Parser::terminate(std::string msg) {
    std::cerr << "Error at Position: " << curPos  << " content: " << curToken.content << '\n';
    throw std::runtime_error("Error during parsing: " + msg);
}


