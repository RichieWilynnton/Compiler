#include "Testing.h"
#include "Tokentype.h"
#include "Token.h"
#include "./Utils/TokenUtils.h"

#include <vector>
#include <string>
#include <iostream>

void printToken(Token token) {
    std::string s = TokenUtils::stringifyTokenType(token.tokenType);
    std::string content = token.content;

    std::cout << s << " " << content << std::endl;
}
