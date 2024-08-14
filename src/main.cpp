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

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    // Get the input file path from the command-line argument
    std::string inputFilePath = argv[1];
    
    std::ifstream infile { inputFilePath };
    if (!infile) {
        std::cerr << "Unable to open file: " << inputFilePath << '\n';
        return 1;
    }

    std::ofstream outFile("../api/output/output.c");
    if (!outFile) {
        std::cerr << "Unable to open output file for writing.\n";
        return 1;
    }

    std::string file_contents { std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>() };

    Lexer lexer = Lexer(file_contents);


    Token token = lexer.getToken();
    std::vector<Token> tokens;
    
    tokens.push_back(token);

    while (token.tokenType != TokenType::_EOF) {
        token = lexer.getToken();
        tokens.push_back(token);
    }


    // for (Token t : tokens) printToken(t);
    
    Parser parser = Parser(tokens);
    std::unique_ptr<Program> ast = parser.getParseTree();

    std::cout << ast->printNode() << '\n'; 
    
    Generator generator = Generator(ast);
    std::string file = generator.generateFile();

    std::cout << file << '\n';

    outFile << file;
    outFile.close();

    return 0;
}
