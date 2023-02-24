#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int * generateArray(int n)
{
	int *array;
    	int i, candidate;

   	 array = malloc(n * sizeof(*array));

    	for (i = 0; i < n; i++) 
	{
        	candidate = rand() % 100000;
        	array[i] = candidate;
   	}

    return array;
}

//sequential search
int searchElement(int *array, int searchKey, int arraySize)
{
	for(int i = 0; i < arraySize; i++)
	{
		if(array[i] == searchKey)
			return i;
	}
	return -1;
}

// bubble sort
void bubble_sort(int *array, int n)
{
	int temp;	
	for (int i = 0; i <  n-1; i++)
	{
		for (int j=0; j < n-i-1; j++)
		{
			if(array[j] > array[j+1])
			{	
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

void selection_sort(int* a, int n)
{   
	int min; int temp;
	for(int i=0; i< n-1; i++)
	{
		min= i;
		for(int j=i;j<n-1;j++)
		{
			if(a[j]<a[min]) min=j;
		}
		temp= a[min];
		a[min]= a[i];
		a[i]= temp;
	}
}

double time_elapsed(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec);

	t += (end.tv_nsec - start.tv_nsec) * 0.000000001;

	return t;
}

int main()
{
	int n;
	int searchKey;
	int isSuccess;
	double totalTimeWithSorting;
	double totalTimeWithOutSorting;
	
	struct timespec start;
	struct timespec	end;

	int *array;
	
	n = 10000;
	

	int searchkey = rand() % 10000;

	for (int times = 0; times < 1000; times++)
	{
		srand(time(0));
		array = generateArray(n);

		clock_gettime(CLOCK_REALTIME, &start);
			searchElement(array, searchKey, n);
		clock_gettime(CLOCK_REALTIME, &end);
		totalTimeWithOutSorting = totalTimeWithOutSorting + time_elapsed(start, end);

		bubble_sort(array,n);	
		selection_sort(array,n);

		clock_gettime(CLOCK_REALTIME, &start);
			searchElement(array, searchKey, n);
		clock_gettime(CLOCK_REALTIME, &end);
		totalTimeWithSorting = totalTimeWithSorting + time_elapsed(start, end);
		
	}
	
	printf("\n The average time taken without sorting -- with sorting: %lf -- %lf\n", 
		totalTimeWithOutSorting/1000, totalTimeWithSorting/1000);
	
	return 1;	
}
