/**********
*Author :HARISH R SHARMA
*Date :28.10.2021
*Purpose :Assert based problems as part of ADS Assignment 2
*/

struct _employee_
{
    char Name[10];
    int Emp_ID;
    char Phone_Number[10];
    char Designation[10];
    float salary;
};
typedef struct _employee_ Employee;

int store_employee_details();
int read_employee_details();

void put_data_into_file();
void display_data();
float compute_data(int*);
void designation(int*,int*,int*);
