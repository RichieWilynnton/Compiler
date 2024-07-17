#include <stdio.h>
#include "UtilFunctions.h"
int main(){
int a = 3;
int b = 2;
for (int i=0;i<10;i++){
a = (a + b);
};
while (a) {
printf("%d\n", a);
a = (a-1);
};
printf("%s\n", "done");
a = 4;
{
int a = 2;
};
printf("%d\n", a);

return 0;
}
