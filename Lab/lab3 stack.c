#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int s[MAX_SIZE], top = -1;

void push()
{
    int x;
    if (top == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &x);
    s[++top] = x;
}

void pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("Popped element is %d\n", s[top--]);
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    else
    {
        printf("Contents of the stack: \n");
        for (i = 0; i <= top; i++)
        {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("1. Push 2. Pop 3. Display 4. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return (0);
        default:
            printf("Invalid choice\n");
        }
    }
}