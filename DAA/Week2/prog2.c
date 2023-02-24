//factorial of a number(iterative method)
#include<stdio.h>
#include<time.h>

double time_elapsed(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec);				   
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001;  
	return t;
}

int fact(int n)
{
    int fact=1;
    for(int i=1; i<=n; ++i)
    {
        fact=fact*i;
    }
    printf("%d", fact);
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
    printf("%d", fact(n));
	clock_gettime(CLOCK_REALTIME, &end);
    printf("time taken by iterative method: %lf \n", time_elapsed(start, end));
    return 0;
}