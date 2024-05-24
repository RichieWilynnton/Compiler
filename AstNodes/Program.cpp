#include "Program.h"

void Program::addStatement(ASTNode node) {
    statements.push_back(node);
}
