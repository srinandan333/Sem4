//tower of hanoi(iterative method)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

double time_elapsed(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec);				   
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001;  
	return t;
}

int hanoi(int n, char S, char A, char D)
{
    int mov=1;
    for(int i=1; i<=n; i++)
    {
        mov=mov*2;
    }
    mov=mov-1;
    int temp;
    if(n%2==0)
    {
        temp=A;
        A=D;
        D=temp;
    }
    for(int i=1; i<=mov; i++)
    {
        if(i%3==1)
        {
            printf("Move disc from %c to %c \n",S,D);
        }
        if(i%3==2)
        {
            printf("Move disc from %c to %c \n",S,A);
        }
        if(i%3==0)
        {
            printf("Move disc from %c to %c \n",D,A);
        }
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
    hanoi(n,'A','B','C');
	clock_gettime(CLOCK_REALTIME, &end);
    printf("time taken by iterative method: %lf \n", time_elapsed(start, end));
    return 0;
}