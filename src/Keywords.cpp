#include "Keywords.h"
#include "Tokentype.h"
#include <iostream>

#include <string>

TokenType::TokenType checkIfKeyword(const std::string& identifier) {
    static std::unordered_map<std::string, TokenType::TokenType> keywords;
    // to avoid initializing multiple times
    if (keywords.empty()){
        keywords["label"] = TokenType::LABEL;
        keywords["goto"] = TokenType::GOTO;
        keywords["output"] = TokenType::PRINT;
        keywords["input"] = TokenType::INPUT;
        keywords["let"] = TokenType::LET;
        keywords["if"] = TokenType::IF;
        keywords["then"] = TokenType::THEN;
        keywords["else"] = TokenType::ELSE;
        keywords["endif"] = TokenType::ENDIF;
        keywords["while"] = TokenType::WHILE;
        keywords["in"] = TokenType::IN;
        keywords["range"] = TokenType::RANGE;
        keywords["for"] = TokenType::FOR;
        keywords["and"] = TokenType::AND;
        keywords["or"] = TokenType::OR;
        keywords["not"] = TokenType::NOT;
        keywords["True"] = TokenType::TRUE;
        keywords["False"] = TokenType::FALSE;
    }
    return keywords.find(identifier) != keywords.end() ? keywords[identifier] : TokenType::INVALID;
}

