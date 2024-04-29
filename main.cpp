#include <iostream>
#include <fstream>
#include <string>

// #include "Tokentype.h"
#include "Lexer.h"

#define debug cout << "I am here" << endl

using namespace std;

int main() {
    string codeString;
    ifstream infile { "code.txt" };
    string file_contents { istreambuf_iterator<char>(infile), istreambuf_iterator<char>() };

    file_contents = "+";

    Lexer lexer = Lexer(file_contents);
    int token = lexer.getToken();
    while (token != TokenType::_EOF) {
        cout << token << endl;
        token = lexer.getToken();
    }



    return 0;
}