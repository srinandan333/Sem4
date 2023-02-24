//introduction of wait() function
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>

int main()
{
    pid_t a;
    a=fork();
    if(a==0)
    {
        printf("Hello from child \n");
        execlp("/bin/ls","ls",NULL);
    }
    else
    {
        wait(NULL);
        printf("Hello from parent \n");
    }
    return 0;
}