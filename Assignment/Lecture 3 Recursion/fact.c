#include <stdio.h>

int factorial(int n)
{
    if (n < 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    printf("Enter a number: ");
    int num;
    scanf("%d", &num);
    int result = factorial(num);
    printf("Factorial of %d is %d\n", num, result);
    return 0;
}
