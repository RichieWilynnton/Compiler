#include "Keywords.h"
#include "Tokentype.h"

#include <string>

TokenType checkIfKeyword(const std::string& identifier) {
    static std::unordered_map<std::string, TokenType> keywords;
    // to avoid initializing multiple times
    if (keywords.empty()){
        keywords["label"] = TokenType::LABEL;
        keywords["goto"] = TokenType::GOTO;
        keywords["print"] = TokenType::PRINT;
        keywords["input"] = TokenType::INPUT;
        keywords["let"] = TokenType::LET;
        keywords["if"] = TokenType::IF;
        keywords["then"] = TokenType::THEN;
        keywords["endif"] = TokenType::ENDIF;
        keywords["while"] = TokenType::WHILE;
        keywords["repeat"] = TokenType::REPEAT;
        keywords["endwhile"] = TokenType::ENDWHILE;
    }
    return keywords.find(identifier) != keywords.end() ? keywords[identifier] : TokenType::INVALID;
}

