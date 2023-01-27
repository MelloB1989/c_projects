/*Program to calculate and print the product of two matrices*/
#include <stdio.h>
int main(){
    //Input the number of rows and columns of the array from the user
    int rows, cols;
    printf("\nPlease input the number of rows and columns: ");
    scanf("%d%d", &rows, &cols);

    //Now declaring the of required length
    int m1[rows][cols];
    int m2[rows][cols];
    int pr[rows][cols];

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

    //Calculating the product of matrices
    int pro;
    for(int i = 0; i<=rows - 1; i++){
        for(int j = 0; j<=cols - 1; j++){
            for(int k = 0; k<=cols - 1; k++){
                pro = m1[i][k] * m2[k][j] + pro;
            }
            pr[i][j] = pro;
            pro = 0;
        }
    }
    
    //Printing the array
    for(int i = 0; i<=rows - 1; i++){
        for(int j = 0; j<=cols - 1; j++){
            printf("%d\t",pr[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}