#pragma once

#include <string>

class TypeError {
public:
    static void terminate(std::string msg);
};