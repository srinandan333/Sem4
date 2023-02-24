//how to time a particular function
#include <stdio.h>
#include <time.h>

double time_elapsed(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec);

	t += (end.tv_nsec - start.tv_nsec) * 0.000000001;

	return t;
}

int fun(int n)
{
	printf("\n");
}

int main()
{
	long int s =0;

	struct timespec start;
	struct timespec	end;

	clock_gettime(CLOCK_REALTIME, &start);
	fun(n);
	clock_gettime(CLOCK_REALTIME, &end);
	printf("time %lf \n", time_elapsed(start, end));
	printf("s: %ld\n", s); 
}