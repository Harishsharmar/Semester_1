/**********
*Author :HARISH R SHARMA
*Date :28.10.2021
*Purpose :Assert based problems as part of ADS Assignment 1
*/

#include<stdio.h>
#include<stdlib.h>

int store_number_reverse_order()
{
    FILE *fsrc,*fdst;
    int num,count=0;
    fsrc=fopen("source.txt","r");
    fdst=fopen("destination.txt","w");
    if(fsrc==NULL)
    {
        printf("Source file not found\n");
        exit(0);
    }
    while((fscanf(fsrc,"%d",&num))!=EOF)  // counting the number of integers present in order to define the size of array
        count++;
    rewind(fsrc);   // resetting the file pointer location to beginning of file
    int arr[count],i=0;
    while((fscanf(fsrc,"%d",&num))!=EOF)    // storing the integers in the array
    {
        arr[i]=num;
        i++;
    }
    for(i=count-1;i>=0;i--)   // Printing the array elements back to destination file in reverse order
        fprintf(fdst,"%d\n",arr[i]);
    fclose(fsrc);
    fclose(fdst);
    return 0;
}
