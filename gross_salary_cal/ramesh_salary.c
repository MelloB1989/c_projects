# include <stdio.h>
int main(){
float salary, gross_income, allowance;
printf("Input salary: ");
scanf("%f", &salary);
allowance = 0.6 * salary;
gross_income = salary - allowance;
printf("Gross income: %f", gross_income);
}
