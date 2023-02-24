//program to count number of function calls during calculation of the power of a number
#include<stdio.h>
#include<stdlib.h>

int power(int a, int n)
{
	int res = 1;
	if(n == 0)
	{
		res = 1;
	}
	else
	{
		res = a * power(a,n-1);
	}
	return res;
}

int power_count(int a, int n, int *ptr_count)
{ 
	int res = 1;
	if(n == 0)
	{
		res = 1;
		*ptr_count = 1;
	}
	else
	{	 		
		res = a * power_count(a, n-1, ptr_count);
		(*ptr_count)++; 
	}
	return res;
}

int main()
{
	int a;
	int n;
	int count = 0;
	scanf("%d %d", &a, &n);
	int res = power_count(a,n, &count);
	printf("res: %d\n",res);
	printf ("# of times the function was called is %d\n", count);
	return 0;
}