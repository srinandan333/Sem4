#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define read_end 0
#define write_end 1

int main()
{
	//taking input of array from the user
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter elements: ");
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}

	//pipe creation 
    int fd[2];
    if (pipe(fd) == -1) 
    {
        printf("Pipe creation has failed");
        return 1;
    }
	
	//fork function call
	pid_t pid;
    pid = fork();
    if (pid < 0) 
    {
        fprintf(stderr, "Fork creation has failed");
        return 1;
    }

	//parent process 
    else if (pid > 0) 
    {
		int sum1=0;
		for(int i=0; i<n/2; i++)
		{	
			sum1=sum1+arr[i];
		}
        close(fd[read_end]);
        write(fd[write_end], &sum1, n);
        close(fd[write_end]);
    }

	//child process
    else 
    {
		int sum1;
        close(fd[write_end]);
        read(fd[read_end], &sum1, n);
		int sum2=sum1;
        for(int i=n/2; i<n; i++)
		{
			sum2=sum2+arr[i];
		}
        printf("Sum of all elements of the array: %d\n", sum2);
    }
	return 0;
}