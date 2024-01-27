
#include <stdio.h>

struct student
{
    char name[50];
    int roll;
    float marks;
};

int main()
{
    struct student s = {"John", 1, 90.5};
    struct student *ptr = &s;

    printf("Name: %s\n", ptr->name);
    printf("Roll: %d\n", ptr->roll);
    printf("Marks: %.2f\n", ptr->marks);

    return 0;
}
