#ifndef TOKENUTILS_H
#define TOKENUTILS_H

#include "../Tokentype.h"

#include "string"

class TokenUtils {
    public:
        static std::string stringifyTokenType(TokenType::TokenType type);
};
#endif