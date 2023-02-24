#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define size 25
#define read_end 0
#define write_end 1

int main()
{
	//initializations
	char str1[size] = "hello";
	char str2[size] = "world";
	char str3[size] = "pes";
	char read1[strlen(str1)];
	char read2[strlen(str2)];
	char read3[strlen(str3)];

	//pipe creation
	int fd[2];
	if (pipe(fd) == -1) 
	{
		printf("Pipe failed\n");
		return 1;
	}

	//fork function call
	pid_t  pid; 
	pid = fork();
	if (pid < 0) 
    {
        fprintf(stderr, "Fork creation has failed");
        return 1;
    }

	// parent process
	if (pid > 0)  
	{	
		close(fd[read_end]);
		write(fd[write_end], str1, strlen(str1)+1);
		write(fd[write_end], str2, strlen(str2)+1);
		write(fd[write_end], str3, strlen(str3)+1);
		close(fd[write_end]);
	}

	//child process 
	else 
	{
		close(fd[write_end]);
		read(fd[read_end], read1, strlen(str1)+1);
		read(fd[read_end], read2, strlen(str2)+1);
		read(fd[read_end], read3, strlen(str3)+1);
		printf("%s %s %s",read3,read2,read1);
		printf("\n");
		close(fd[read_end]);
	}
	return 0;
}