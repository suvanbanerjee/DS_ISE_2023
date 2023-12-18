#include <stdio.h>
#include <stdlib.h>

struct employee
{
    char name[30];
    int id;
    float salary;
};

int main()
{
    int i, n, s, d;
    struct employee emp[5];
    while (1)
    {
        printf("Enter 1 to add data of employee\n Enter 2 to print data of employee\n Enter 3 to  search data of employee\n Enter 4 to exit\n");
        scanf("%d", &d);
        switch (d)
        {
        case 1:
            printf("Enter the number of employees\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("Enter name, id and salary of employee %d\n", i + 1);
                scanf("%s %d %f", emp[i].name, &emp[i].id, &emp[i].salary);
            }
            break;

        case 2:
            for (i = 0; i < n; i++)
            {
                printf("Name of employee %d is %s\n", i + 1, emp[i].name);
                printf("id of employee %d is %d\n", i + 1, emp[i].id);
                printf("Salary of employee %d is %f\n", i + 1, emp[i].salary);
            } printf("\n");
            break;
        case 3:

            printf("Enter id to search\n");
            scanf("%d", &s);

            for (i = 0; i < n; i++)
            {
                if (emp[i].id == s)
                {
                    printf("Name of employee %d is %s\n", i + 1, emp[i].name);
                    printf("id of employee %d is %d\n", i + 1, emp[i].id);
                    printf("Salary of employee %d is %f\n", i + 1, emp[i].salary);
                }
                else if (i == n - 1)
                {
                    printf("Employee not found\n");
                }
            }
            break;
        case 4:
            exit(0);

        default:
            printf("Invalid input\n");
        }
    }
    return 0;
}
