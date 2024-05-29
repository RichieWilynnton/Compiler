#include "Program.h"
#include <memory>

void Program::addStatement(std::unique_ptr<ASTNode>& node) {
    statements.push_back(node);
}
