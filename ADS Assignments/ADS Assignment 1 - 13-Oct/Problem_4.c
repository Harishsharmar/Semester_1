/**********
*Author :HARISH R SHARMA
*Date :28.10.2021
*Purpose :Assert based problems as part of ADS Assignment 1
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pattern_detection(const char *str)
{
    FILE *fp;
    char ch;
    int i,count=0;
    int len=strlen(str);
    fp=fopen("pattern.txt","r");
    if(fp==NULL)
        return -1;
    while(!feof(fp))
    {
        for(i=0;i<len;i++)
        {
            ch=fgetc(fp);
            if(ch!=str[i])  // compares each character of the string with he file character
                break;
        }
        if(i==len) // This assures that whole string pattern is traversed once completely. So increase count by 1.
                   // if(str[i]=='\0') also can be written. Since string is traversed completely it now points to null character (end of string)
            count++;

    }
    fclose(fp);
    return count;
}
