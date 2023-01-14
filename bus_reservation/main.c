#include <stdio.h>
#include <stdlib.h>

int main(){
    int ch;
    system("clear");
    printf("\t\t\t\tWelcome to MelloB's Bus Stand!\n\n\n\n");
    printf("Choose what you want to do :-)\n\n");
    printf("1.) List the number of buses available\n");
    printf("2.) Book a seat\n");
    printf("3.) Cancel a seat\n");
    printf("Your choice here:-> ");
    scanf("%d", &ch);
    switch(ch){
        case 1: 
            system("clear");
            printf("\t\t\t\tWelcome to MelloB's Bus Stand!!\n\n\n\n");
            system("python3 api.py get_buses");
        break;

        case 2:
            system("python3 api.py book_bus");
        break;

        case 3:
            system("python3 api.py cancel_bus");
        break;

        default:
            printf("Oops! I don't know what to do for that option!");
    }
}
