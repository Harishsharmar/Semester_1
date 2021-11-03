/* Old Method*/ /* Ignore this file */

#include<stdio.h>
#include<stdlib.h>
#include "ADS_Assignment_2.h"


int store_employee_details()
{
    FILE *femp;
    int i;
    //char buffer[10];
    femp=fopen("Employee.txt","wb");
    Employee emp[2];
    for(i=0;i<2;i++)
    {
        printf("Enter employee details\n");
        //scanf("%s%s%s%s%f",emp.Name,emp.Emp_ID,emp.Phone_Number,emp.Designation,&emp.salary);
        scanf("%s%s%s%s%f",emp[i].Name,emp[i].Emp_ID,emp[i].Phone_Number,emp[i].Designation,&emp[i].salary);
        fwrite(&emp,sizeof(emp),1,femp);
    }
    //fwrite(&emp,sizeof(emp),2,femp);
    fclose(femp);
    return 0;
}

int read_employee_details()
{
    FILE *femp;
    int i;
    //char buffer[10];
    femp=fopen("Employee.txt","rb");
    Employee emp;
    if(femp==NULL)
        printf("Error : File not found");

    while(fread(&emp,sizeof(emp),1,femp))  //No need of For loop. It reads until EOF. At EOF, it reads 0 and comes out of loop
        {
            printf("%s\n%s\n%s\n%s\n%f\n",emp.Name,emp.Emp_ID,emp.Phone_Number,emp.Designation,emp.salary);
        }

    fclose(femp);
    return 0;
}

