//grandparent->parent->child using execl() function
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t p1, p2;
    int y=0;
    p1 =fork();
    if(p1 == 0)
    {
        p2=fork();
        if(p2 == 0)
        {
            y=y+5;
            printf("CHILD \n");
            printf("y : %d \n",y);
            printf("pid : %d \n",getpid());
            printf("ppid : %d \n",getppid());
            execl("/bin/ls","ls",NULL);
        }
        else
        {
            wait(NULL);
            y=y+1;
            printf("PARENT \n");
            printf("y : %d \n",y );
            printf("pid : %d \n",getpid());
            printf("ppid : %d \n",getppid());
            execl("/bin/ls","ls","-r",NULL);
        }
    }
    else
    {
        wait(NULL);
        y=y-1;
        printf("GRANDPARENT \n");
        printf("y : %d \n",y);
        printf("pid : %d \n",getpid());
        printf("ppid : %d \n",getppid());
        execl("/bin/ls","ls",NULL);
    }
    return 0;
}