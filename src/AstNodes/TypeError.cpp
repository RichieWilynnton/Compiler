
#include "TypeError.h"

#include <iostream>
#include <string>

void TypeError::terminate(std::string msg) {
    std::cerr << "Type Error: " + msg << std::endl;
    exit(EXIT_FAILURE);
}
