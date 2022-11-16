#include <stdio.h>
int main(){
int i, n, sum;
printf("Input number: ");
scanf("%d", &n);
i = 1;
sum = 0;
while(i <= n){
i = i+2;
sum += i;
printf("%d", i);
}
printf("Sum is %d", sum);
}
