#include <stdio.h>
#include "UtilFunctions.h"
#include "vector.h"
#include "print.h"
int main(){
Vector* a = appendInt(3, appendInt(2, appendInt(1, initVector(3))));
print_vector(a);
print_newline();
freeVector(a);

return 0;
}
