/**********
*Author :HARISH R SHARMA
*Date :28.10.2021
*Purpose :Assert based problems as part of ADS Assignment 1
*/

#include<stdio.h>
#include<stdlib.h>

int length_of_sentence()
{
    FILE *fs,*ft;
    char ch;
    int count=0,max=0,i,no_of_lines=1;
    fs=fopen("file3.txt","r");
    ft=fopen("file4.txt","w");
    if(fs==NULL)
    {
        printf("Error : File not found");
        exit(0);
    }
    while((ch=fgetc(fs))!=EOF)
    {
        //printf("%c",ch);
        if(ch=='\n') no_of_lines++;   // Finding out total no. of lines in the text file
    }
    rewind(fs);  // initialising pointer location to beginning of file
    //printf("%d",no_of_lines);

    for(i=0;i<no_of_lines;i++)
    {

        while(1)
        {
            ch=fgetc(fs);
            if((ch=='\n')||(ch==EOF))
                break;
            else
                count++;      // Finding out length of each sentence
        }

        fprintf(ft,"%d\n",count);  // Writing length of each sentence back to destination file
        if(count>max) max=count;   // Finding out length of longest sentence
        //fseek(fs,1,1);
        count=0;  // Initializing count=0 in order to find the length of next sentence in the text file.
    }
    printf("\n\nLength of Longest sentence : %d\n",max);

    return 0;
}
