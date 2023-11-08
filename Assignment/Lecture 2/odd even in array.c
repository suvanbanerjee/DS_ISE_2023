// Program to add odd and even in an array
#include <stdio.h>

int main(){
    int a[100],n,odd=0,even=0;

    //Taking input of array
    printf("Enter Size of array 1\n");
    scanf("%d",&n);
    printf("Enter %d Elements \n",n);
    for(int i=0 ; i<n ; i++){
        scanf("%d",&a[i]);
    }

    //Calculating sum
    for(int i=0 ; i<n ; i++){
        if (a[i]%2==0) even+=a[i];
        else odd+=a[i];
    }

    printf("Sum of Even = %d\nSum of Odd = %d",even,odd);

    return 0;
}