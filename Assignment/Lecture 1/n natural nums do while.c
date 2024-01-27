#include <stdio.h>

int main()
{
    int n, i = 1;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("The first %d natural numbers are: ", n);
    do
    {
        printf("%d ", i++);
    } while (i < n + 1);
    return 0;
}
