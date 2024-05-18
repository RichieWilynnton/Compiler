#include <iostream>
#include <fstream>
#include <string>

#include "Tokentype.h"
#include "Lexer.h"
#include "Token.h"

#define debug cout << "I am here" << endl

using namespace std;

int main() {
    string codeString;
    ifstream infile { "code.txt" };
    string file_contents { istreambuf_iterator<char>(infile), istreambuf_iterator<char>() };

    file_contents = ">=>>#########";

    Lexer lexer = Lexer(file_contents);
    Token token = lexer.getToken();
    while (token.tokenType != TokenType::_EOF) {
        cout << token.tokenType << endl;
        token = lexer.getToken();
    }



    return 0;
}