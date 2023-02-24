//program to find the power of a number
#include<stdio.h>
#include<stdlib.h>

int count;

int power(int a, int n)
{
    count++;
    if(n==0)
    {
        return 1;
    }
    else
    {
        return a*power(a,n-1);
    }
}

int power(int a, int n)
{
    count++;
    int ans=1;
    for(int i=0; i<n; i++)
    {
        ans=ans*a;
    }
    return ans;
}

int power(int a, int n)
{
    count++;
    if(n==0)
    {
        return 1;
    }
    else if(n%2==0)
    {
        return power(a*a, n/2);
    }
    else
    {
        return a*power(a,n-1);
    }
}

int main()
{
    int a,n;
    printf("enter two numbers:");
    scanf("%d %d", &a, &n);
    printf("power: %d \n", power(a,n));
    printf("count: %d \n", count);
    return 0;
}