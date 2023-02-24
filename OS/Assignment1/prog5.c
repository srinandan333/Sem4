//program to search for a key in an array in the child process
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    int n, key;
    printf("Enter number of elements:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter key to be searched:");
    scanf("%d", &key);
    pid_t pid;
    pid=fork();
    if(pid<0)
    {
		printf("FAIL\n");
		return 0;
	}
    else if(pid==0)
    {
        printf("CHILD \n");
        for(int i=0; i<n; i++)
        {
            if(arr[i]==key)
            {
                printf("Key found \n");
            }
        }
    }
    else
    {
        printf("PARENT \n");
        printf("Key to be searched:%d \n", key);
    }
    return 0;
}