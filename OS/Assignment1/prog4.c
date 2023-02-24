//program to sort an array taken as user input in child and parent processes
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    int n;
    printf("Enter number of elements:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
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
        int min, temp;
        for(int i=0; i<n; i++)
        {
            min=i;
            for(int j=i; j<n; j++)
            {
                if(arr[j]<arr[min]) 
                {
                    min=j;
                }
            }
            temp= arr[min];
            arr[min]= arr[i];
            arr[i]= temp;
        }
        for(int i=0; i<n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("PARENT \n");
        int max, temp;
        for(int i=0; i<n; i++)
        {
            max=i;
            for(int j=i; j<n; j++)
            {
                if(arr[j]>arr[max]) 
                {
                    max=j;
                }
            }
            temp= arr[max];
            arr[max]= arr[i];
            arr[i]= temp;
        }
        for(int i=0; i<n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}