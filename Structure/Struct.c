#include<stdio.h>

struct emp {
    int emp_id;
    char name[20];
    float sal;
    
};
void main(){
    struct emp e[100];
    int n;
    printf("How manny employee to add ");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("Enter ID Name and Salary");
        scanf("%d %s %f",&e[i].emp_id,&e[i].name,&e[i].sal);
    }
    for (int i=0;i<n;i++){
        printf("ID :%d\n Name: %s \n Salary: %f\t %f\t %f",e[i].emp_id,e[i].name,e[i].s.pa_sal,e[i].s.base_sal,e[i].s.overtime);
    }
}