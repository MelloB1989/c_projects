/*Program to print largest and smallest of all elements*/
#include <stdio.h>
int main(){
    //Initializing the array
    int arr[] = {69,58,97,5,54,66,54,32,44,65,12,42,45,21,32,21,54,45,43,54,21,46,54};

    //Counting the number of elements
    int length = sizeof(arr) / sizeof(arr[0]);

    //Finding the largest element
    int max = 0;
    for(int i = 0; i<=length - 1; i++){
        if(arr[i]>max)
            max = arr[i];
    }

    //Finding the smallest element
    int min = max;
    for(int i = 0; i<=length - 1; i++){
        if(arr[i]<min)
            min = arr[i];
    }

    //Printing the array
    for(int i = 0; i<=length; i++){
        printf("%d\t",arr[i]);
    }

    printf("\nNumber of elements: %d\n", length);
    printf("\nThe largest number is: %d\n", max);
    printf("\nThe smallest number is: %d\n", min);

    return 0;
}