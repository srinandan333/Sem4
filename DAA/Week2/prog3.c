//fibonacci series(recursive method)
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
    if(n==0)
    {
        return 0;
    }
    else if(n==1 || n==2)
    {
        return 1;
    }
    else
    {
        return fib1(n-1)+fib1(n-2);
    }
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
        printf("%d ",fib1(i));
    }
    printf("\n");
	clock_gettime(CLOCK_REALTIME, &end);
    printf("time taken by recursive method: %lf \n", time_elapsed(start, end));
    printf("count recursive: %d \n",count_rec);
    return 0;
}