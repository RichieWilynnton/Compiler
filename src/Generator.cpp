#include "Generator.h"
#include "./AstNodes/Program.h"

#include <string>
#include <memory>
#include <vector>

Generator::Generator(std::unique_ptr<Program> &prog, std::vector<std::string>& funcs) {
    header = "";
    code = "";
    program = std::move(prog);
    topLevelFunctions = funcs;
}

void Generator::addHeaderLine(std::string line) {
    header += line + '\n';
}
void Generator::addLine(std::string line) {
    code += line + '\n';
}

std::string Generator::generateFile() {
    addHeaderLine("#include <stdio.h>");
    addHeaderLine("#include \"functions.h\"");
    addHeaderLine("#include \"vector.h\"");
    addHeaderLine("#include \"print.h\"");
    
    for (std::string& s : topLevelFunctions) {
        addLine(s);
    }
    addLine("int main(){");
    addLine(program->genCode());
    addLine("return 0;");
    addLine("}");
    
    return header + code;
}