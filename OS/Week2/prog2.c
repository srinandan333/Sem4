//parent child using sleep() function
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
        for(int i=0; i<5; i++)
        {
            sleep(i);
            y=y+1;
        }
        printf("CHILD \n");
        printf("y : %d \n",y);
        printf("pid : %d \n",getpid());
        printf("ppid : %d \n",getppid());
    }
    else
    {
        for(int i=0; i<5; i++)
        {
            sleep(i);
            y=y-1;
        }
        printf("PARENT \n");
        printf("y : %d \n",y);
        printf("pid : %d \n",getpid());
        printf("ppid : %d \n",getppid());
    }
    return 0;
}