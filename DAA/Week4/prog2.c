//function that determines if any element in an array < 10
//or all elements in an array is lesser than 10
#include<stdio.h>
#include<stdlib.h>

int is_any(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(a[i]<10)
        {
            return 1;
        }
    }
    return 0;
}

int is_all(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(a[i]>=10)
        {
            return 0;
        }
    }
    return 1;
}

int min(int a[], int n)
{
    int min=a[0];
    for(int i=0; i<n; i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
    }
    return min;
}

int is(int a[], int n, int (*op)(int, int))
{
    op(a, n);
}

int main()
{
    int n;
    printf("enter number of elements:");
    scanf("%d",&n);
    int a[n];
    int b=is(a, n, is_any);
    int c=is(a, n, is_all);
    printf("is any: %d", b);
    printf("is all: %d", c);
    return 0;
}