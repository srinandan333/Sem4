//iterative code for multiplication ala russe
#include<stdio.h>
#include<stdlib.h>

int multiply(int n, int m)
{
    int p=0;
    while(n!=1)
    {
        if(n%2==0)
        {
            p=p+m;
        }
        n==n/2;
        m=2*m;
    }
    p=p+m;
    return p;
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