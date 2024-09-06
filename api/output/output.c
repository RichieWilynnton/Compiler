#include <stdio.h>
#include "functions.h"
#include "vector.h"
#include "print.h"
void _____LAMBDA_____0(Element env[], int y) {
int a=*(int*)(env[0].data);
{
print_int((40 + y));
print_newline();
};

}
int _____LAMBDA_____5(Element env[], int x, int y) {
int a=*(int*)(env[0].data);
Element printMultA[] ={make_int_element(40)};
{
a = 10;
_____LAMBDA_____0(printMultA, x );
return ((10 + x) + y);
};
freeEnv(printMultA, (sizeof(printMultA) ? sizeof(printMultA) / sizeof(printMultA[0]) : 0));

}
int main(){
int a = 40;
Element printMultA[] = {make_int_element(40)};
Element add[] = {make_int_element(10),};
print_int(_____LAMBDA_____5(add, 4, 5 ));
print_newline();
freeEnv(add, (sizeof(add) ? sizeof(add) / sizeof(add[0]) : 0));
freeEnv(printMultA, (sizeof(printMultA) ? sizeof(printMultA) / sizeof(printMultA[0]) : 0));
;

return 0;
}
