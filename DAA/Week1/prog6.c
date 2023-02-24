//function to convert an integer to binary 
#include<stdio.h>
#include<stdlib.h>

int fun(int n)
{
    if(n==0)
    {
        return 0;
    }
    fun(n/2);
    printf("%d", n%2);
}

int main()
{
    int n;
    printf("enter a number:");
    scanf("%d", &n);
    printf("binary equivalent:");
    fun(n);
    printf("\n");
    return 0;
}