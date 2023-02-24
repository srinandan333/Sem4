//program to enumerate all the substrings of a given string
#include <stdio.h>  
#include <string.h>  
   
void substring(char s[], char sub[], int p, int len, int *ptr_count)
{  
    (*ptr_count)++;
    int c = 0;  
    while (c < len) 
    {  
        sub[c] = s[p+c];  
        c++;  
    }  
    sub[c] = '\0';  
}  
   
int main()  
{  
    char str[10];
    char c[10];
    int count=0;
    printf("Enter a string : ");
    scanf("%s", str);
    int i, j;
    int len = strlen(str);  
    printf("All subsets for the given string are: \n");    
    for(i = 0; i < len; i++)
    {    
        for(j = 1; j <= len-i; j++)
        {  
            substring(str,c,i,j,&count);  
            printf("%s\n",c);  
        }  
    }  
    printf("Count : %d \n", count);
    return 0;  
}  