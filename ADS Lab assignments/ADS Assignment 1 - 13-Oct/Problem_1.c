/**********
*Author :HARISH R SHARMA
*Date :28.10.2021
*Purpose :Assert based problems as part of ADS Assignment 1
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int sum_of_numbers()
{
    FILE *fs;
    int num,sum=0;
    char* filename="trial.txt";
    fs=fopen(filename,"r");
    if(fs==NULL){
        printf("Error : file not found\n");
        return -1;  //Returns -1 if file not found
        exit(0);
    }

    while((fscanf(fs,"%d",&num))!=EOF)
    {
        printf("%d\n",num);
        sum=sum+num;
    }
    printf("\nSum of numbers present in '%s' is %d",filename,sum);
    fclose(fs);
    return 0;
}



