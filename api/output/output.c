#include <stdio.h>
#include "functions.h"
#include "vector.h"
#include "print.h"
void _____LAMBDA_____0(Element env[], int y) {
int a=*(int*)(env[0].data);
{
print_int(y);
print_newline();
};

}
int _____LAMBDA_____5(Element env[], int x) {
int a=*(int*)(env[0].data);
Element funcA[] ={make_int_element(40)};
{
_____LAMBDA_____0(funcA, x );
return (40 + x);
};
freeEnv(funcA, (sizeof(funcA) ? sizeof(funcA) / sizeof(funcA[0]) : 0));

}
int main(){
int a = 40;
Element funcA[] = {make_int_element(40)};
Element add[] = {make_int_element(40),};
print_int(_____LAMBDA_____5(add, 4 ));
print_newline();
freeEnv(add, (sizeof(add) ? sizeof(add) / sizeof(add[0]) : 0));
freeEnv(funcA, (sizeof(funcA) ? sizeof(funcA) / sizeof(funcA[0]) : 0));
;

return 0;
}
