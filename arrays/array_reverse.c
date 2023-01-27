/*Program to print the array in reverse order*/
#include <stdio.h>
int main(){
    //Initializing the array
    int arr[] = {69,58,97,5,54,66,54,32,44,65,12,42,45,21,32,21,54,45,43,54,21,46,54};

    //Counting the number of elements
    int length = sizeof(arr) / sizeof(arr[0]);

    //Printing the array
    for(int i = 0; i<=length - 1; i++){
        printf("%d\t",arr[i]);
    }

    //Now printing the array in reverse
    printf("\nReverse order: \n");
    for(int i = 0; i<=length; i++){
        printf("%d\t",arr[(length - 1) - i]);
    }

    printf("\nNumber of elements: %d\n", length);
    return 0;
}