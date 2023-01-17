#include <stdio.h>
#include "md5.c"

char username[][100] = {""};//Create a array database which can store maximum 100 users
char password[][100] = {""};//Create a array database which can store maximum 100 passwords
char encrypted_password[][100] = {""};
int reg_count = 0;//The count of number of registrations

void show_menu();
void register_user();

int main(){
    int q = 0, choice, id;
    while(q == 0){
        show_menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            register_user();
            break;

        case 2:
            printf("\nInput account ID: ");
            scanf("%d", &id);
            printf("\n\nFetching account details");
            printf("\nAccount username: %s", username[id]);
            printf("\nAccount password: %s", password[id]);
            printf("\nEncrypted password: %s", encrypted_password[id]);
            break;

        case 3:
            printf("\nInput account ID: ");
            scanf("%d", &id);
            strcpy(username[id], "");
            strcpy(password[id], "");
            strcpy(encrypted_password[id], "");
            printf("\n\nAccounted Deleted!");
            break;
        
        case 4:
            printf("\nThankyou!\n");
            q = 1;

        default:
            break;
        }
    }
}

void show_menu(){
    printf("\n\n\t\t\t\tWelcome to MelloB's Password Manager!\n\n\n\n");
    printf("Choose what you want to do :-)\n\n");
    printf("1.) Save a new account\n");
    printf("2.) Get credentials of existing account\n");
    printf("3.) Delete an existing account\n");
    printf("4.) Exit");
    printf("\nYour choice here:-> ");
}

void register_user(){
    char temp[50];
    printf("\n\nEnter the username: ");
    //fgets(temp, 50, stdin);
    scanf("%50s", temp);
    strcpy(username[reg_count], temp);
    printf("\n\nEnter the password: ");
    scanf("%50s", temp);
    //fgets(temp, 50, stdin);
    //ENCRYPTING THE PASSWORD-------------------------------
    uint8_t *encrypted_pass = md5String(temp);
    strcpy(encrypted_password[reg_count], encrypted_pass);
    strcpy(password[reg_count], temp);
    printf("\n\nAccount ID %d has been registered!", reg_count);
    reg_count = reg_count + 1;
}