#pragma once

#include "./AstNodes/Program.h"

#include <memory>
#include <string>

class Generator {
    public:
    
    std::string header;
    std::string code;
    std::unique_ptr<Program> program;
    
    
    Generator(std::unique_ptr<Program> &prog);
    void addHeaderLine(std::string line);
    void addLine(std::string line);
    std::string generateFile();

};