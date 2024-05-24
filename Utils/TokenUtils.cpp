#include "TokenUtils.h"

#include <string>

std::string TokenUtils::stringifyTokenType(TokenType type) {
    switch(type) {
        case INVALID: return "INVALID";
        case _EOF: return "EOF";
        case NEWLINE: return "NEWLINE";
        case NUMBER: return "NUMBER";
        case IDENTIFIER: return "IDENTIFIER";
        case STRING: return "STRING";
        case SEMICOLON: return "SEMICOLON";
        // Keywords
        case LABEL: return "LABEL";
        case GOTO: return "GOTO";
        case PRINT: return "PRINT";
        case INPUT: return "INPUT";
        case LET: return "LET";
        case IF: return "IF";
        case THEN: return "THEN";
        case ENDIF: return "ENDIF";
        case WHILE: return "WHILE";
        case REPEAT: return "REPEAT";
        case ENDWHILE: return "ENDWHILE";
        // Operators
        case EQ: return "EQ";
        case PLUS: return "PLUS";
        case MINUS: return "MINUS";
        case ASTERISK: return "ASTERISK";
        case SLASH: return "SLASH";
        case EQEQ: return "EQEQ";
        case NOTEQ: return "NOTEQ";
        case LT: return "LT";
        case LTEQ: return "LTEQ";
        case GT: return "GT";
        case GTEQ: return "GTEQ";
        case OPEN_ROUND_BRACKET: return "OPEN ROUND BRACKET";
        case CLOSED_ROUND_BRACKET: return "CLOSED ROUND BRACKET";
        case OPEN_SQUARE_BRACKET: return "OPEN SQUARE BRACKET";
        case CLOSED_SQUARE_BRACKET: return "CLOSED SQUARE BRACKET";
        case ARROW: return "ARROW";
        case COMMA: return "COMMA";
        default: return "UNKNOWN";
    }
}
