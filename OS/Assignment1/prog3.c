//program to create a file and directory using fork() and exec() 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
    pid=fork();
	if(pid<0)
    {
		printf("FAIL\n");
		return 0;
	}
	else if(pid==0)
    {
		printf("CHILD\n");
		execl("/bin/mkdir","mkdir","newdir",NULL);
		printf("exec not executed\n");
	}
	else
    {
        printf("PARENT\n");
        execl("/bin/ls","ls",NULL);
	}
	return 0;
}
