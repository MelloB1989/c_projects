#include <stdio.h>

int main(){
    int ch;
    system("clear");
    printf("\t\t\t\tWelcome to MelloB's Hospital!\n\n\n\n");
    printf("Choose what you want to do :-)\n\n");
    printf("1.) Open Doctor's Portal\n");
    printf("2.) Open Patient's Portal\n");
    printf("3.) exit\n");
    printf("Your choice here:-> ");
    scanf("%d", &ch);

    if(ch == 1){
        system("clear");
        printf("\t\t\t\tWelcome to MelloB's Hospital!\n\n\n\n");
        printf("Choose what you want to do :-)\n\n");
        printf("1.) Add a doctor\n");
        printf("2.) Search for a doctor\n");
        printf("3.) Remove a doctor\n");
        printf("Your choice here:-> ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            system("python3 api.py add_doctor");
            break;

        case 2:
            system("python3 api.py search_doctor");
            break;

        case 3:
            system("python3 api.py delete_doctor");
            break;
        
        default:
            break;
        }
    }
    
    else if(ch == 2){
        system("clear");
        printf("\t\t\t\tWelcome to MelloB's Hospital!\n\n\n\n");
        printf("Choose what you want to do :-)\n\n");
        printf("1.) Add a patient\n");
        printf("2.) Search for a patient\n");
        printf("3.) Remove a patient\n");
        printf("Your choice here:-> ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            system("python3 api.py add_patient");
            break;

        case 2:
            system("python3 api.py search_patient");
            break;

        case 3:
            system("python3 api.py delete_patient");
            break;
        
        default:
            break;
        }
    }
}
