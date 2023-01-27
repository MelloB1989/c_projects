/*Program to print all the elements in the 2D array and also count the number of elements*/
#include <stdio.h>
int main(){
    //Initializing the array
    int arr[][5] = {{12,34,32,44,35},{34,35,34,54,36},{98,75,76,23,48}, {46,77,69,80,79}};

    //Counting the number of elements
    int rows, cols;
    rows = sizeof(arr)/sizeof(arr[0]);
    cols = sizeof(arr[0])/sizeof(arr[0][0]);

    //Printing the array
    for(int i = 0; i<=rows - 1; i++){
        for(int j = 0; j<=cols - 1; j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    printf("\nNumber of elements: %d\n", (rows*cols));
    return 0;
}