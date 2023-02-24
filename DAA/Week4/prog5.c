#include<stdio.h>
#include<stdlib.h>

int power(int a, int b)
{
    int power=1;
    for(int i=0; i<b; i++)
    {
        power=power*a;
    }
    return power;
}

int eval(int a[], int x, int n)
{
    int sum=0;
    int pow=1;
    for(int i=1; i<=n; i++)
    {
        sum=sum+a[n-i]*pow;
        pow=pow*x;
    }
    return sum;
}

int eval1(int a[], int x, int n)
{
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum=sum+a[i]*power(x, n-i-1);
    }
    return sum;
}

int main()
{
    int n;
    int x;
    printf("Enter number of terms:");
    scanf("%d", &n);
    int a[n];
    printf("Enter coefficients:");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter x:");
    scanf("%d", &x);
    int res=eval(a, x, n);
    printf("Answer:%d \n", res);
    return 0;
}