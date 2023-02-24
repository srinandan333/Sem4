//fibonacci series(iterative method)
#include<stdio.h>
#include<time.h>

int count;

double time_elapsed(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec);				   
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001;  
	return t;
}

int fib(int n)
{
    count++;
    int a = 0, b = 1, c, i;
    if(n == 0)
    {
        return a;
    }
    else if(n == 1)
    {
        return 1;
    }
    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int n;
    struct timespec start;
	struct timespec end;
    int i;
    printf("Enter a number:");
    scanf("%d",&n);
    clock_gettime(CLOCK_REALTIME, &start);
    for(i=0; i<n; i++)
    {
        printf("%d ",fib(i));
    }
    printf("\n");
	clock_gettime(CLOCK_REALTIME, &end);
    printf("time taken by iterative method: %lf \n", time_elapsed(start, end));
    printf("count iterative: %d \n",count);
    return 0;
}