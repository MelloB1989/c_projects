/*Program to input elements of an array*/
#include <stdio.h>
int main(){
    //Input the length of the array from the user
    int length;
    printf("\nPlease input the number of elements: ");
    scanf("%d", &length);

    //Now declaring the of required length
    int array[length];

    //Now taking the input
    for(int i = 0; i<=length - 1; i++){
        printf("\nInput value for element %d: ", i);
        scanf("%d", &array[i]);
    }

    //Printing the array
    for(int i = 0; i<=length - 1; i++){
        printf("%d\t",array[i]);
    }
    
    return 0;
}