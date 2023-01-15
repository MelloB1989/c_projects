#include <stdio.h>
#include <stdlib.h>

int main(){
    //Declaring the variables------------------
    int no_exam_centers, no_tabs, i, ctr;
    system("clear");//clear the screen
    printf("\t\t\t\tMelloB\n\n\n\n");
    //Input the number of exam of centers------
    printf("Enter the number of centers: ");
    scanf("%d", &no_exam_centers);
    //Declaring a array with size equal to no of exam centers
    int center_strength[no_exam_centers];
    //Input the strength of each exam center---
    while(i<=no_exam_centers-1){
        printf("\nEnter student strength in center %d :- ", i);
        scanf("%d", &center_strength[i]);
        i = i+1;
    }
    //Now input the number of tabs available---
    printf("\nEnter the number of tabs available: ");
    scanf("%d", &no_tabs);
    
    //INPUT COMPLETE---------------------------

    i = ctr = 0;
    //Running a loop to from start to end of the array
    while(i<=no_exam_centers-1){
        //Check if the number of students in one center is equal or less than the number tabs available, as per the question
        if(center_strength[i]<=no_tabs){
            //If condition satisfies increment the counter
            ctr = ctr+1;
            //Deduct the number of tabs
            no_tabs = no_tabs - center_strength[i];
        }
        //Increment the loop counter
        i = i+1;
    }
    
    //COUNTING COMPLETE------------------------

    printf("\nThe number of centers tabs can be provided:- %d\n\n", ctr);
}