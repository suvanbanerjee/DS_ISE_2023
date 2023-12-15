#include <stdio.h>
#include <string.h>
#define MAX 50

int s[MAX];
int top=-1;

void push(int x){
    s[++top] = x;
}

int pop(){
    return s[top--];
}

void display(){
    int i;
    for(i=0;i<MAX;i++){
        printf("%d ",s[i]);
    }
}

int main(){
    char exp[50];
    printf("Enter the postfix expression: ");
    scanf("%s",exp);

    for (int i = 0; i < strlen(exp); i++)
    {
        if(isdigit(exp[i])){
            push(exp[i]-'0');
        }
        else{
            int val1 = pop();
            int val2 = pop();
            switch(exp[i]){
                case '+': push(val2+val1); break;
                case '-': push(val2-val1); break;
                case '*': push(val2*val1); break;
                case '/': push(val2/val1); break;
            }
        }
    }
    printf("Result: %d\n",pop());
    return 0;
}
