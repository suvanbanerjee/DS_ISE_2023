#include<stdio.h>

struct emp {
    int emp_id;
    char name[20];
    struct sal{
        float pa_sal;
        float base_sal;
        float overtime;
    }s;
    
};
void main(){
    struct emp e[100];
    int n;
    printf("How manny employee to add ");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("Enter ID Name and Salary");
        scanf("%d %s %f %f %f",&e[i].emp_id,&e[i].name,&e[i].s.pa_sal,&e[i].s.base_sal,&e[i].s.overtime);
    }
    for (int i=0;i<n;i++){
        printf("ID :%d\n Name: %s \n Salary: %f\t %f\t %f",e[i].emp_id,e[i].name,e[i].s.pa_sal,e[i].s.base_sal,e[i].s.overtime);
    }
}


1 write larest of 3 usinf if logical and without any logical
2 wap to chek vote using while do while and if
3 wap to print n natural numbers wsing wjile and do while
4 wap to print sum od even and odd using while and do while

