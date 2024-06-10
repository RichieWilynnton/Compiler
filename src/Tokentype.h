#ifndef TOKENTYPE_H
#define TOKENTYPE_H

namespace TokenType{
    enum TokenType {
    INVALID = -2, 
    _EOF = -1,
    NEWLINE = 0,
    NUMBER = 1,
    IDENTIFIER = 2,
    STRING = 3,
    TRUE = 4,
    FALSE = 5,
    // Keywords.
    LABEL = 101,    
    GOTO = 102,
    PRINT = 103,
    INPUT = 104,
    LET = 105,
    IF = 106,
    THEN = 107,
    ENDIF = 108,
    WHILE = 109,
    REPEAT = 110,
    ENDWHILE = 111,
    // Operators.
    EQ = 201,
    PLUS = 202,
    MINUS = 203,
    MULT = 204,
    DIV = 205,
    EQEQ = 206,
    NOTEQ = 207,
    LT = 208,
    LTEQ = 209,
    GT = 210,
    GTEQ = 211,
    NOT = 212,
    // Brackets
    OPEN_ROUND_BRACKET = 250,
    CLOSED_ROUND_BRACKET = 251,
    OPEN_SQUARE_BRACKET = 252,
    CLOSED_SQUARE_BRACKET = 253,
    // Other Symbols
    ARROW = 216,
    COMMA = 217,
    
    };
}


#endif
