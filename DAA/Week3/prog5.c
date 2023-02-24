//program for calculation of fibonacci series using formula
#include<stdio.h>
#include<math.h>

double fib(int n)
{
    double x = sqrt(5);
    int res = (pow((1 + x), n) - pow((1 - x), n)) / (pow(2, n) * x);
    return res;
}

int main()
{
    int n=0;
    printf("N \t");
    printf("Fib \n");
    printf("--------------------\n");
    while(n!=26)
    {
        printf("%d \t", n);
        printf("%lf \n",fib(n));
        n++;
    }
    return 0;
}