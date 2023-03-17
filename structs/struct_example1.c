#include <stdio.h>
#include <string.h>
struct Student
{
    int roll_no, batch;
    char name[30], branch[40];
};

int main(){
    struct Student s1, *ptr = &s1;
    s1.roll_no = 101;
    s1.batch = 90;
    strcpy(s1.name, "Harsh");
    strcpy(s1.branch, "Computer Science and Engineering");
    printf("Roll no:- %d\n", (*ptr).roll_no);
    puts(s1.name);
    return 0;
}