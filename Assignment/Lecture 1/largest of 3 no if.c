// Program to find largest of 3 numbers without if else
#include <stdio.h>

int main(){
    int a,b,c,d;
    printf("Enter 3 numbers: ");
    scanf("%d %d %d",&a,&b,&c);
    d = (a>b)? a : b;
    d = (d>c)? d : c;
    printf("%d is largest",d);
}