#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

int func1(char str[])
{
    int count=0;
    for(int i=0; i<MAX; i++)
    {
        if(str[i]=='a')
        {
            for(int i=0; i<MAX; i++)
            {
                if(str[i]=='b')
                {
                    count++;
                }
            }
        }
    }
    return count;
}

int func(char str[])
{
    int count=0;
    int count_a=0;
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i]=='a')
        {
            count_a++;
        }
        else if(str[i]=='b')
        {
            count+=count_a;
        }
    }
    return count;
}

int main()
{
    int n;
    char str[10];
    printf("enter a string:");
    scanf("%s", str);
    int res=func(str);
    printf("Number of substrings: %d \n", res);
    return 0;
}