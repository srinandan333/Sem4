//introduction to function pointer
#include<stdio.h>

int add(int x, int y)
{
    return x+y;
}

int mul(int x, int y)
{
    return x*y;
}

int acc(int a[], int n, int init, int (*op)(int, int))
{
    for(int i=0; i<n; i++)
    {
        init = op(a[i], init);
    }
    return init;
}

int main()
{
    int a[]={2, 5, 4, 1, 3};
    int (*op)(int, int);
    printf("sum: %d \n", acc(a, 5, 0, add));
    //op=add;
    //printf("sum: %d \n", op(3,4));
    //op=mul;
    //printf("product: %d \n", op(3,4));
    printf("mul: %d \n", acc(a, 5, 0, mul));
    return 0;
}