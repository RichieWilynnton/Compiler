#include "Keywords.h"
#include "Tokentype.h"
#include <iostream>

#include <string>

TokenType checkIfKeyword(const std::string& identifier) {
    static std::unordered_map<std::string, TokenType> keywords;
    // to avoid initializing multiple times
    if (keywords.empty()){
        keywords["label"] = LABEL;
        keywords["goto"] = GOTO;
        keywords["print"] = PRINT;
        keywords["input"] = INPUT;
        keywords["let"] = LET;
        keywords["if"] = IF;
        keywords["then"] = THEN;
        keywords["endif"] = ENDIF;
        keywords["while"] = WHILE;
        keywords["repeat"] = REPEAT;
        keywords["endwhile"] = ENDWHILE;
    }
    return keywords.find(identifier) != keywords.end() ? keywords[identifier] : INVALID;
}

