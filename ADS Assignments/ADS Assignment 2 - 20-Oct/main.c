/**********
*Author :HARISH R SHARMA
*Date :28.10.2021
*Purpose :Assert based problems as part of ADS Assignment 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ADS_Assignment_2.h"

int store_employee_details();
int read_employee_details();

void put_data_into_file();
void display_data();
float compute_data(int*);
void designation(int*,int*,int*);

int main()
{
    int count,mgr,dev,admin;
    count=mgr=dev=admin=0;
    float salary=0;

    //store_employee_details();
    //read_employee_details();

    put_data_into_file();
    //display_data();

    salary=compute_data(&count);
    assert(count==5);
    assert(salary!=0);
    //printf("\n%f",salary);

    designation(&mgr,&dev,&admin);
    assert(mgr==2);
    assert(dev==1);
    assert(admin==2);

    return 0;
}
