//tower of hanoi(recursive method)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int count;

double time_elapsed(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec);				   
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001;  
	return t;
}

void hanoi(int n, char S, char A, char D)
{
    count++;
    if(n==1)
    {
        printf("Move disc from %c to %c \n",S,D);
        return;
    }
        hanoi(n-1,S,D,A);
        printf("Move disc from %c to %c \n",S,D);
        hanoi(n-1,A,S,D);
}

int main()
{
    int n;
    struct timespec start;
	struct timespec end;
    printf("Enter a number:");
    scanf("%d",&n);
    clock_gettime(CLOCK_REALTIME, &start);
    hanoi(n,'A','B','C');
	clock_gettime(CLOCK_REALTIME, &end);
    printf("time taken by recursive method: %lf \n", time_elapsed(start, end));
    printf("count recursive: %d \n",count);
    return 0;
}