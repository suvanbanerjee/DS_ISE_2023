#include <stdio.h>

void main(){
    int n;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    int odd=0,even=0;
    do {
        if(n%2==0){
            even+=n;
        }
        else{
            odd+=n;
        }
        n--;
    } while (n>0);
    
    printf("Sum of odd numbers: %d\n",odd);
    printf("Sum of even numbers: %d\n",even);
}