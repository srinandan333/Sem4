//program to count number of function calls during calculation of fibonacci series
#include<stdio.h>
#include<stdlib.h>

int fib(int n, int *ptr_count)
{
    (*ptr_count)++;
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return fib(n-1, ptr_count) + fib(n-2, ptr_count);
    }
}

int main()
{
    int n;
    int *ptr_count;
    int count=0;
    int i;
    printf("Enter a number:");
    scanf("%d",&n);
    int array[n];
    for(i=0; i<n; i++)
    {
        array[i]=fib(i, &count);
    }
    for(int i=0; i<n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("count : %d \n",count);
    return 0;
}