//what will happen if multiple forks are used
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    fork();
    fork();
    fork();
    printf("Hello World! \n");
    return 0;
}