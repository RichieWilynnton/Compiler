#include <stdio.h>
int main(){
int a = 10;
{
a = 8;
printf("%d\n", a);
};
printf("%d\n", a);

return 0;
}
