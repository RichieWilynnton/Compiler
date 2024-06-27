#include "Tokentype.h"
#include "Lexer.h"
#include "Token.h"
#include "Testing.h"
#include "Parser.h"
#include "./AstNodes/Program.h"
#include "Generator.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>


int main() {
    std::string codeString;
    std::ifstream infile { "../code.txt" };
    std::string file_contents { std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>() };

    Lexer lexer = Lexer(file_contents); 

    Token token = lexer.getToken();
    std::vector<Token> tokens;
    tokens.push_back(token);

    while (token.tokenType != TokenType::_EOF) {
        token = lexer.getToken();
        tokens.push_back(token);
    }

    for (Token t : tokens) printToken(t);
    
    Parser parser = Parser(tokens);
    std::unique_ptr<Program> ast = parser.getParseTree();
    // std::cout << ast->printNode() << '\n'; 
    
    Generator generator = Generator(ast);
    std::string file = generator.generateFile();
    std::cout << file << '\n';  

    return 0;
}