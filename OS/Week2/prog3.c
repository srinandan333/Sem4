//parent->child using wait() function
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
        y=y+1;
        printf("CHILD \n");
        printf("y : %d \n",y);
        printf("pid : %d \n",getpid());
        printf("ppid : %d \n",getppid());
    }
    else
    {
        wait(NULL);
        y=y-1;
        printf("PARENT \n");
        printf("y : %d \n",y);
        printf("pid : %d \n",getpid());
        printf("ppid : %d \n",getppid());
    }
    return 0;
}