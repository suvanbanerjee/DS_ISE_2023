// Program to add two array
#include <stdio.h>

int main()
{
    int a[50], b[50], c[100], n, m, l = 0;

    // Taking input of 1st array
    printf("Enter Size of array 1\n");
    scanf("%d", &n);
    printf("Enter %d Elements \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Taking input of 2nd array
    printf("Enter Size of array 2\n");
    scanf("%d", &m);
    printf("Enter %d Elements \n", m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    // Copying to array 3

    for (int k = 0; k < n; k++)
    {
        c[l++] = a[k];
    }
    for (int k = 0; k < m; k++)
    {
        c[l++] = b[k];
    }

    // Printing all 3 arrays
    printf("\n Array 1:\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n Array 2:\t");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n Array 3:\t");
    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}
