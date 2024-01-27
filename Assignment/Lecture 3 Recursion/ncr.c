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
    int n, r;
    printf("Enter the value of n and r: ");
    scanf("%d %d", &n, &r);
    float result = factorial(n) / (factorial(r) * factorial(n - r));
    printf("The value of ncr is %f\n", result);
    return 0;
}