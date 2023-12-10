/*
Initialize an empty stack to hold operands.
Iterate through each character in the postfix expression from left to right.
For each character:
If it is an operand (a number), push it onto the stack.
If it is an operator (+, -, *, /, etc.), pop the top two elements from the stack (these will be the operands for the operator).
Apply the operator to the two operands (the order is important for non-commutative operators like subtraction and division), and push the result back onto the stack.
Continue this process until you have processed all characters in the postfix expression.
At the end of the iteration, the stack should contain only one element, which is the final result of the expression.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 100

void postfixEvaluate(char *a){
    char stack[SIZE];
    int top = -1;
    for(int i; a[i]; i++){
        if(isdigit(a[i])){
            stack[++top] = a[i] - '0';
        }
        else{
            int A = stack[top--];
            int B = stack[top--];
            switch (a[i])
            {
            case '+':
                stack[++top] = A+B;
                break;
            case '-':
                stack[++top] = A-B;
                break;
            case '/':
                stack[++top] = A/B;
                break;
            case '*':
                stack[++top] = A*B;
                break;
            case '^':
                stack[++top] = A^B;
                break;
            default:
                break;
            }
        }
    }
    printf("Operation result: %d", stack[top]);
}

int main(){
    char a[] = "34+2*";
    postfixEvaluate(a);
    return 0;
}
