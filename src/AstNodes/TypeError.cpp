
#include "TypeError.h"

#include <iostream>
#include <string>
#include <stdexcept> 


void TypeError::terminate(std::string msg) {
    throw std::runtime_error("Type Error: " + msg);
}

