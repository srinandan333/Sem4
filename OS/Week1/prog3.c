//parent->child relationship
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    pid_t a;
    a=fork();
    if(a==0)
    {
        printf("Hello from child \n");
    }
    else
    {
        printf("Hello from parent \n");
    }
    printf("Hello World! \n");
    return 0;
}