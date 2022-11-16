#include <stdio.h>
int main (){
int a,b,c;
printf("Enter: ");
scanf("%d %d %d", &a, &b, &c);
a>b&&a>c ? printf("A is grt.");
b>a&&b>c ? printf("B is grt");
printf("C is grt");
return a;
}
