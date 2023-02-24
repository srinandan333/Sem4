//recursive code for multiplication ala russe
#include<stdio.h>
#include<stdlib.h>

int multiply(int n, int m)
{
    if(n==1)
    {
        return m;
    }
    else if(n%2==0)
    {
        return multiply(n/2, 2*m);
    }
    else
    {
        return multiply((n-1)/2, 2*m);
    }
}

int main()
{
    int n, m;
    printf("Enter 2 numbers:");
    scanf("%d %d", &n, &m);
    int res=multiply(n, m);
    printf("Answer: %d", res);
    return 0;
}