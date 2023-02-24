//program to find the sum of n cubes of natural numbers
#include<stdio.h>
#include<stdlib.h>

int sumofcube(int n)
{
    int sum=0;
    for(int i=0; i<=n; ++i)
    {
        sum=sum+i*i*i;
    }
    return sum;
}

int main()
{
    int n, sum;
    printf("enter a number : ");
    scanf("%d", &n);
    printf("answer: %d", sumofcube(n));
    return 0;
}
