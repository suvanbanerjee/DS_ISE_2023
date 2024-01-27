// Program to add array elements
#include <stdio.h>

int main()
{
    int a[100], n;

    // Taking input of array
    printf("Enter Size of array 1\n");
    scanf("%d", &n);
    printf("Enter %d Elements \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Printing arrays
    printf("\n Array :\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}