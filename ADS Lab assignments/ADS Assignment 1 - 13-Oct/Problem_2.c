/**********
*Author :HARISH R SHARMA
*Date :28.10.2021
*Purpose :Assert based problems as part of ADS Assignment 1
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int square_of_number()
{
    FILE *fs,*ft;
    int num,square;
    fs=fopen("file1.txt","r");
    ft=fopen("file2.txt","w");
    if(fs==NULL)
    {
        printf("Source file not found\n");
        exit(0);
    }

    fscanf(fs,"%d",&num);
    square=pow(num,2);
    printf("Number is %d\n",num);
    fprintf(ft,"%d",square);
    printf("Square is %d",square);
    return 0;
}
