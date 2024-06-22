#include "TokenUtils.h"

#include <string>

std::string TokenUtils::stringifyTokenType(TokenType::TokenType type) {
    switch(type) {
        case TokenType::INVALID: return "INVALID";
        case TokenType::_EOF: return "EOF";
        case TokenType::NEWLINE: return "NEWLINE";
        case TokenType::NUMBER: return "NUMBER";
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::STRING: return "STRING";
        case TokenType::TRUE: return "TRUE";
        case TokenType::FALSE: return "FALSE";
        // Keywords
        case TokenType::LABEL: return "LABEL";
        case TokenType::GOTO: return "GOTO";
        case TokenType::PRINT: return "PRINT";
        case TokenType::INPUT: return "INPUT";
        case TokenType::LET: return "LET";
        case TokenType::IF: return "IF";
        case TokenType::THEN: return "THEN";
        case TokenType::ENDIF: return "ENDIF";
        case TokenType::WHILE: return "WHILE";
        case TokenType::IN: return "IN";
        case TokenType::RANGE: return "RANGE";
        case TokenType::FOR: return "FOR";
        
        // Operators
        case TokenType::EQ: return "EQ";
        case TokenType::PLUS: return "PLUS";
        case TokenType::MINUS: return "MINUS";
        case TokenType::MULT: return "ASTERISK";
        case TokenType::DIV: return "SLASH";
        case TokenType::EQEQ: return "EQEQ";
        case TokenType::NOTEQ: return "NOTEQ";
        case TokenType::LT: return "LT";
        case TokenType::LTEQ: return "LTEQ";
        case TokenType::GT: return "GT";
        case TokenType::GTEQ: return "GTEQ";
        case TokenType::NOT: return "NOT";
        case TokenType::AND: return "AND";
        case TokenType::OR: return "OR";
        case TokenType::OPEN_ROUND_BRACKET: return "OPEN ROUND BRACKET";
        case TokenType::CLOSED_ROUND_BRACKET: return "CLOSED ROUND BRACKET";
        case TokenType::OPEN_SQUARE_BRACKET: return "OPEN SQUARE BRACKET";
        case TokenType::CLOSED_SQUARE_BRACKET: return "CLOSED SQUARE BRACKET";
        case TokenType::OPEN_CURLY_BRACKET: return "OPEN CURLY BRACKET";
        case TokenType::CLOSED_CURLY_BRACKET: return "CLOSED CURLY BRACKET";
        
        case TokenType::ARROW: return "ARROW";
        case TokenType::COMMA: return "COMMA";
        case TokenType::DOUBLE_DASH: return "DOUBLE DASH";
        case TokenType::COLON: return "COLON";
        default: return "UNKNOWN";
    }
}
