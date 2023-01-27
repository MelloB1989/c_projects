/*Program to sort an array in ascending and decending order*/
#include <stdio.h>
int main(){
    //Initializing the array
    int arr[] = {69,58,97,5,54,66,54,32,44,65,12,42,45,21,32,21,54,45,43,54,21,46,54};

    //Counting the number of elements
    int length = sizeof(arr) / sizeof(arr[0]);

    //Sorting the array
    for(int i = 0; i<=length - 1; i++){
        for(int j = i+1; j<=length - 1; j++){
            //Ascending order logic
            if(arr[i] > arr[j]){
                //Swapping the elements
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
            /*//Decending order logic
            if(arr[i] < arr[j]){
                //Swapping the elements
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
            */
        }
    }

    //Printing the array
    for(int i = 0; i<=length - 1; i++){
        printf("%d\t", arr[i]);
    }

    printf("\nNumber of elements: %d\n", length);
    return 0;
}