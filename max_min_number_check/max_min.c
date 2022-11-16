#include <stdio.h>
int main() {
int max, min, n, i, a;
printf("Input limit: ");
scanf("%d", &n);
i = max = 0;
min = 9999;
while (i<=n-1){
    printf("Input number: ");
    scanf("%d", &a);
    if(a>max){
        max = a;
}
    else if(a<min){
        min = a;
}

    i = i+1;
}
printf("Maximum: %d", max);
printf("Minimum: %d", min);
printf("Crafted by MelloB");
}
