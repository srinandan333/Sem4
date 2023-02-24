/*Write a program which illustrates barber and customer problem of 
synchronization with these semaphore variables semaphore sem =1, count=1
(note: at a time barber is allowed to do barbing for a single customer)*/
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

void wait(int s)
{
    while(s<=0);
    s--;
}

void signal(int s)
{
    s++;
}

int main()
{
    int s=0;
    pid_t pid=fork();
    if(pid==0)
    {
        signal(s);
    }
    else
    {
        wait(s);
    }
    return 0;
}