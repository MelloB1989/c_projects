/*Program to input elements of an array*/
#include <stdio.h>
int main(){
    //Input the number of rows and columns of the array from the user
    int rows, cols;
    printf("\nPlease input the number of rows: ");
    scanf("%d", &rows);
    printf("\nPlease input the number of columns: ");
    scanf("%d", &cols);

    //Now declaring the of required length
    int array[rows][cols];

    //Now taking the input
    for(int i = 0; i<=rows - 1; i++){
        for(int j = 0; j<=cols - 1; j++){
            printf("Input the value for element (%d, %d): ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    //Printing the array
    for(int i = 0; i<=rows - 1; i++){
        for(int j = 0; j<=cols - 1; j++){
            printf("%d\t",array[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}