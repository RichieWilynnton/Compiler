#include "Print.h"

#include <string>

std::string Print::genCode() {
    return "print (" + content + ')';
}

std::string Print::printNode() {
    return "PRINT "  + content;
}
