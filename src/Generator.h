#pragma once

#include "./AstNodes/Program.h"

#include <memory>
#include <string>
#include <vector>

class Generator {
    public:
    
    std::string header;
    std::string code;
    std::unique_ptr<Program> program;
    std::vector<std::string> topLevelFunctions;
    
    
    Generator(std::unique_ptr<Program> &prog, std::vector<std::string>& funcs);
    void addHeaderLine(std::string line);
    void addLine(std::string line);
    std::string generateFile();

};