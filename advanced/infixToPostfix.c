/*
Initialize an empty stack to hold operators and an empty list (or string) to store the postfix expression.

Scan the infix expression from left to right, one character at a time.

For each character:

If it's an operand (a digit or a variable), add it to the postfix expression output.

If it's an open parenthesis '(', push it onto the stack.

If it's a close parenthesis ')', pop operators from the stack and add them to the postfix expression output until an open parenthesis '(' is encountered. Pop and discard the open parenthesis as well.

If it's an operator (+, -, *, /, etc.), then:

While the stack is not empty and the operator at the top of the stack has a higher or equal precedence compared to the current operator (considering parentheses as having the highest precedence), pop the operator from the stack and add it to the postfix expression output.
Push the current operator onto the stack.
After scanning the entire infix expression, pop any remaining operators from the stack and append them to the postfix expression output.

The postfix expression output is your final result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 5

int precedence(char operator){
    switch (operator)
    {
    case '+':
    case '-':
        return 0;
        break;
    case '/':
    case '*':
        return 1;
        break;
    case '^':
        return 2;
        break;
    default:
        break;
    }
    return -1;
}

void infixToPostfix(char *a){
    char postfix[SIZE], stack[SIZE];
    int top = -1, k = -1;
    for(int i=0; a[i]; i++){
        if(isdigit(a[i])){
            postfix[++k] = a[i];
        }
        else if(a[i] == '('){
            stack[++top] = a[i];
        }
        else if(a[i] == ')'){
            while(stack[top] != '(' && stack[top]){
                postfix[++k] = stack[top--];
            }
            top--;
        }
        else{
            if(top >= 0 && precedence(stack[top])>=precedence(a[i])){
                postfix[++k] = stack[top--];
            }
            stack[++top] = a[i];
        }
    }
    while(stack[top]){
        postfix[++k] = stack[top--];
    }
    postfix[++k] = '\0';
    printf("Postfix expression: %s", postfix);
}

int main(){
    char a[] = "2+3*4";
    infixToPostfix(a);
    return 0;
}
