// Program to find you are elligble to vote using while and do while

#include <stdio.h>

int main(){
    int age;
    printf("Enter your age: ");
    scanf("%d",&age);
    while (age >= 18){
        printf("You are elligible to vote\n");
        return 0;
    }
    printf("You are not elligible to vote\n");
    }