/**********
*Author :HARISH R SHARMA
*Date :28.10.2021
*Purpose :Assert based problems as part of ADS Assignment 2
*/

#include<stdio.h>
#include<stdlib.h>
#include "ADS_Assignment_2.h"
#include<assert.h>
#include<string.h>

/* New method*/ /* Without fprintf and fscanf*/

void put_data_into_file()
{
    FILE *wptr=fopen("Employee.txt","w");
    assert(wptr!=NULL);

    /* Defining data of all the employees */
    Employee e1={"Harish",1001,"123456725","Manager",15.45};
    Employee e2={"Satish",1002,"123541389","Admin",9.37};
    Employee e3={"Ashish",1003,"123421748","Developer",5.52};
    Employee e4={"Sainath",1004,"147567124","Manager",15.75};
    Employee e5={"Parichit",1005,"924571078","Admin",9.45};

    /* Writing the data of all the employees to the file */

    fwrite(&e1,sizeof(Employee),1,wptr);
    fwrite(&e2,sizeof(Employee),1,wptr);
    fwrite(&e3,sizeof(Employee),1,wptr);
    fwrite(&e4,sizeof(Employee),1,wptr);
    fwrite(&e5,sizeof(Employee),1,wptr);

    fclose(wptr);
}

void display_data()  /* Optional */ /* Please ignore */
{
    FILE *rptr=fopen("Employee.txt","r");
    Employee e;

    while(fread(&e,sizeof(Employee),1,rptr))   // Printing details of all the employees
    {
        printf("%s\n%d\n%s\n%s\n%f\n",e.Name,e.Emp_ID,e.Phone_Number,e.Designation,e.salary);
    }
    fclose(rptr);

}

float compute_data(int *count)  /* Calculating total count and salary */
{
    FILE *rptr=fopen("Employee.txt","r");
    Employee e;
    *count=0;
    float salary=0;
    while(fread(&e,sizeof(Employee),1,rptr))
    {
        (*count)++;  // Counting total number of employees
        salary=salary+e.salary;   //Total salary of all the employees
    }

    //printf("Total number of employees : %d\n",*count);
    //printf("Total salary of all the employees : %f\n",salary);
    assert(salary!=0); // Ensuring that total salary is calculated successfully

    fclose(rptr);
    return salary;
}

void designation(int *count_mgr,int *count_dev, int *count_admin)
{
    FILE *rptr,*tgt1,*tgt2,*tgt3;
    Employee e;
    //int count_mgr=0,count_dev=0,count_admin=0;
    rptr=fopen("Employee.txt","r");
    tgt1=fopen("Manager.txt","w");
    tgt2=fopen("Developer.txt","w");
    tgt3=fopen("Admin.txt","w");

    while(fread(&e,sizeof(Employee),1,rptr))
    {
        /* strcmp returns 0 if both strings match. So to evaluate IF condition, we need to mention !() in order to make it if(TRUE) */

        if(!strcmp(e.Designation,"Manager"))
        {
            (*count_mgr)++;
            //printf("%d",*count_mgr);
            fwrite(&e,sizeof(Employee),1,tgt1);
        }

        if(!strcmp(e.Designation,"Developer"))
        {
            (*count_dev)++;
            fwrite(&e,sizeof(Employee),1,tgt2);
        }
        if(!strcmp(e.Designation,"Admin"))
        {
            (*count_admin)++;
            fwrite(&e,sizeof(Employee),1,tgt3);
        }

    }
    /*
    printf("Total number of employees with respective designations are as follows :\n");
    printf("Managers : %d\n",*count_mgr);
    printf("Developers : %d\n",*count_dev);
    printf("Administrators : %d\n",*count_admin);
    */

    fclose(rptr);
    fclose(tgt1);
    fclose(tgt2);
    fclose(tgt3);
}

