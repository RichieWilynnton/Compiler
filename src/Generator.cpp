#include "Generator.h"
#include "./AstNodes/Program.h"

#include <string>
#include <memory>

Generator::Generator(std::unique_ptr<Program> &prog) {
    header = "";
    code = "";
    program = std::move(prog);
}

void Generator::addHeaderLine(std::string line) {
    header += line + '\n';
}
void Generator::addLine(std::string line) {
    code += line + '\n';
}

std::string Generator::generateFile() {
    addHeaderLine("#include <stdio.h>");
    addHeaderLine("#include \"UtilFunctions.h\"");
    addHeaderLine("#include \"vector.h\"");
    addHeaderLine("#include \"print.h\"");
    
    addLine("int main(){");
    addLine(program->genCode());
    addLine("return 0;");
    addLine("}");
    
    return header + code;
}