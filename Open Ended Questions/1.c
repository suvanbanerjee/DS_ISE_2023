#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("out of memory");
        exit(0);
    }
    return x;
}

NODE freenode(NODE x)
{
    free(x);
}

NODE push(NODE top, int item)
{
    NODE temp;
    temp = getnode();
    temp->info = item;
    temp->link = top;
    return temp;
}

NODE pop(NODE top)
{
    NODE temp;
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return top;
    }
    temp = top;
    top = top->link;
    printf("The popped item is %d\n", temp->info);
    freenode(temp);
    return top;
}

void display(NODE top)
{
    NODE temp = top;
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

void main()
{
    NODE top = NULL;
    int choice, item;
    for (;;)
    {
        printf("1. PUSH\t2. POP\t3. DISPLAY\t4. EXIT\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item:\t");
            scanf("%d", &item);
            top = push(top, item);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            display(top);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
