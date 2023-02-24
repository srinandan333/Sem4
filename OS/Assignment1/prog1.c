//take argument from command line and execute a function
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(char argc, char *argv[])
{
    pid_t pid;
    pid=fork();
    if(pid==0)
    {
        printf("CHILD \n");
        char link[]="/bin/";
        strcat(link,argv[1]);
        execl(link,argv[1],NULL);
    }
    else
    {
        printf("PARENT \n");
    }
    return 0;
}