// random array, random search, average of number of comparisons
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define SIZE 100000

double time_elapsed(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec);				   
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001;  
	return t;
}

int search(int a[], int key)
{
    int count=0;
    int i=0;
    while(a[i]!=key)
    {
        count++;
        i++;
    }
    return count;
}

int main()
{
    int a[SIZE];
    int sum;
    int count_arr[10000];
    struct timespec start;
	struct timespec end;

    srand(time(0));
    for(int i=0; i<SIZE; i++)
    {
        a[i] = rand() % 10000;
    }

    clock_gettime(CLOCK_REALTIME, &start);
    for(int i=0; i<10000; i++)
    {
        int key=rand() % 10000;
        count_arr[i]=search(a, key);
    }
    clock_gettime(CLOCK_REALTIME, &end);

    for(int i=0; i<10000; i++)
    {
        sum=sum+count_arr[i];
    }
    int avg=sum/10000;
    float time=time_elapsed(start, end)/10000;
    printf("Average number of comparisons: %d \n", avg);
    printf("Average time taken: %lf \n",time);
    printf("\n");
    return 0;
}