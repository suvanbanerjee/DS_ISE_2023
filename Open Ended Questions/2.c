#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 10

int s[MAX], top = -1;

int pop(){return s[top--];}
void push(int x){s[++top] = x;}

int opp(int op1, int op2, char symbol){
    switch(symbol){
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
    }
}

int main(){
    char postfix[MAX];
    int i, op1, op2, res;
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    for(i = 0; i < strlen(postfix); i++){
        if(postfix[i] >= '0' && postfix[i] <= '9')
            push(postfix[i] - '0');
        else{
            op2 = pop();
            op1 = pop();
            res = opp(op1, op2, postfix[i]);
            push(res);
        }
    }

    if (top > 0)
        printf("Invalid expression\n");
    else
    printf("Result: %d\n", pop());
    return 0;
}