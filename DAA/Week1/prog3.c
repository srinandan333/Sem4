//program to time the multiplication of two matrices
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void multiply_matrix(int n; int a[n][n],int b[n][n],int c[n][n],int n)
{
    for(int i=0;i<n;i++)    
    {    
        for(int j=0;j<n;j++)    
        {    
            c[i][j]=0;    
            for(int k=0;k<n;k++)    
            {    
            c[i][j]+=a[i][k]*b[k][j];    
            }    
        }    
    }    
}

void fill_matrix(int n; int x[n][n], int n)
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			x[i][j] = rand() % 10000;
		}
	}
}

void disp_matrix(int n; int x[n][n], int n)
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			printf("%5d ", x[i][j]);
		}
		printf("\n");
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
	struct timespec start;
	struct timespec end;
	int n;
	printf("enter the size of matrix : ");
	scanf("%d", &n);
	int a[n][n];
    int b[n][n];
  	int c[n][n];
 	srand(time(0));
    fill_matrix(a, n);
    fill_matrix(b, n);
  	clock_gettime(CLOCK_REALTIME, &start);
    	multiply_matrix(a, b, c, n);
	clock_gettime(CLOCK_REALTIME, &end);	
    //   disp_matrix(a, n);
    //   disp_matrix(b, n);
    //   disp_matrix(c, n);
	printf("time %lf \n", time_elapsed(start, end));
}