#include "Testing.h"
#include "Tokentype.h"
#include "Token.h"

#include <vector>
#include <string>
#include <iostream>

void printToken(Token token) {
    std::string s;
    std::string content = token.content;
    switch(token.tokenType) {
        case INVALID: s = "INVALID"; break;
        case _EOF: s = "EOF"; break;
        case NEWLINE: s = "NEWLINE"; break;
        case NUMBER: s = "NUMBER"; break;
        case IDENTIFIER: s = "IDENTIFIER"; break;
        case STRING: s = "STRING"; break;
        // Keywords
        case LABEL: s = "LABEL"; break;
        case GOTO: s = "GOTO"; break;
        case PRINT: s = "PRINT"; break;
        case INPUT: s = "INPUT"; break;
        case LET: s = "LET"; break;
        case IF: s = "IF"; break;
        case THEN: s = "THEN"; break;
        case ENDIF: s = "ENDIF"; break;
        case WHILE: s = "WHILE"; break;
        case REPEAT: s = "REPEAT"; break;
        case ENDWHILE: s = "ENDWHILE"; break;
        // Operators
        case EQ: s = "EQ"; break;
        case PLUS: s = "PLUS"; break;
        case MINUS: s = "MINUS"; break;
        case ASTERISK: s = "ASTERISK"; break;
        case SLASH: s = "SLASH"; break;
        case EQEQ: s = "EQEQ"; break;
        case NOTEQ: s = "NOTEQ"; break;
        case LT: s = "LT"; break;
        case LTEQ: s = "LTEQ"; break;
        case GT: s = "GT"; break;
        case GTEQ: s = "GTEQ"; break;
        default: s = "UNKNOWN"; break;
    }

    std::cout << s << " " << content << std::endl;
}
