#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define size 25
#define read_end 0
#define write_end 1

int main()
{
    //pipe creation
    int fd[2];
    if (pipe(fd) == -1) 
    {
        printf("Pipe creation has failed");
        return 1;
    }

    //fork function call
    pid_t pid;
    pid = fork();
    if (pid < 0) 
    {
        fprintf(stderr, "Fork creation has failed");
        return 1;
    }

    //parent process
    else if (pid > 0) 
    {
        close(fd[read_end]);
        char str1[size];
        FILE *f1=fopen("input.txt","r");
        fgets(str1,100,f1);
        fclose(f1);
        write(fd[write_end], str1, strlen(str1) + 1);
        close(fd[write_end]);
        wait(NULL);
    }

    //child process
    else 
    {
        close(fd[write_end]);
        char str2[100];
        read(fd[read_end], str2, 100);
        int length = strlen(str2);
        printf("String read by the child process is: %s\n", str2);
        int space=0;
        for (int i = 0; i < length; i++)
        {
            if (str2[i] == ' ' || i == length - 1)
            {
                space++;
            }
        }
        printf("Number of spaces: %d\n", space);
        printf("Number of characters: %d\n", length);
    }
    return 0;
}