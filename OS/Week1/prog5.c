//introduction of getpid() and getppid() functions
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
    pid_t pid;
    int y=0;
    int c,p,p1,pp;
    pid =fork();
    if(pid < 0)
    {
        fprintf(stderr,"Fork failed \n");
        return 1;
    }
    else if(pid == 0)
    {
        y=y+1;
        c=getpid();
        p=getppid();
    }
    else
    {
        y=y-1;
        p1=getpid();
        pp=getppid();
    }
    printf("y value: %d \n",y);
    printf("child : %d \n",c);
    printf("parent : %d \n",p1);
    printf("child's parent : %d \n",p);
    printf("parent's parent : %d \n",pp);
    return 0;
}