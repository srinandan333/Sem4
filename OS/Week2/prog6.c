//orphan process
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t p1;
    int y=0;
    p1 =fork();
    if(p1 == 0)
    {
        sleep(10);
        printf("CHILD \n");
        printf("pid : %d \n",getpid());
        printf("ppid : %d \n",getppid());
    }
    else
    {
        printf("PARENT \n");
        printf("pid : %d \n",getpid());
        printf("ppid : %d \n",getppid());
    }
    return 0;
}