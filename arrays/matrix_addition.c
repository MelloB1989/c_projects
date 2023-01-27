/*Program to calculate and print addition of two matrices*/
#include <stdio.h>
int main(){
    //Input the number of rows and columns of the array from the user
    int rows, cols;
    printf("\nPlease input the number of rows and columns: ");
    scanf("%d%d", &rows, &cols);

    //Now declaring the of required length
    int m1[rows][cols];
    int m2[rows][cols];

    //Now taking the input Array 1
    printf("\nPlease input array 1 elements now\n");
    for(int i = 0; i<=rows - 1; i++){
        for(int j = 0; j<=cols - 1; j++){
            printf("Input the value for element (%d, %d): ", i, j);
            scanf("%d", &m1[i][j]);
        }
    }

    //Now taking the input Array 1
    printf("\nPlease input array 2 elements now\n");
    for(int i = 0; i<=rows - 1; i++){
        for(int j = 0; j<=cols - 1; j++){
            printf("Input the value for element (%d, %d): ", i, j);
            scanf("%d", &m2[i][j]);
        }
    }

    //Printing the sum of both arrays
    for(int i = 0; i<=rows - 1; i++){
        for(int j = 0; j<=cols - 1; j++){
            printf("%d\t",m1[i][j] + m2[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}