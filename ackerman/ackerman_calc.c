#include <stdio.h>

int ackerman_calc();

int main(){
    int m, n;
    printf("\nPlease input values for m and n: ");
    scanf("%d%d", &m, &n);
    int result = ackerman_calc(m, n);
    printf("\nResult: %d\n", result);

}

int ackerman_calc(int m, int n){
    if(m == 0){
        return (n+1);
    }

    else if(m > 0 && n == 0){
        ackerman_calc(m-1, 1);
    }

    else if(m > 0 && n > 0){
        ackerman_calc(m-1, ackerman_calc(m, n-1));
    }
}