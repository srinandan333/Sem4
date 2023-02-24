//Johnson Trotter's algorithm to list substrings
#include<stdio.h>
#include<stdlib.h>

void johnson(int ele[], int arr[], int n)
{
    while(anymob(ele, arr, n))
    {
        int max=0;
        for(int i=0; i<n; i++)
        {
            if(ele[i]>ele[max] && mobile(ele, arr, i))
            {
                max=i;
            }
        }
        while(mobile(ele, arr, max))
        {
            if(arr[max]==0)
            {
                int temp=ele[max];
                ele[max]=ele[max];
                ele[max-1]=temp;
                max--;
            }
            else if(arr[max]==1)
            {
                int temp=ele[max];
                ele[max]=ele[max+1];
                ele[max+1]=temp;
                max++;
            }
            for(int i=0; i<n; i++)
            {
                printf("%d ", ele[i]);
            }
            printf("\n");
        }
        for(int i=0; i<n; i++)
        {
            if(ele[i]>ele[max] && arr[i]==1)
            {
                arr[i]==0;
            }
            else if(ele[i]>ele[max] && arr[i]==0)
            {
                arr[i]==1;
            }
        }
    }
}

int mobile(int ele[], int arr[], int i)
{
    if(arr[i]==0)
    {
        if(ele[i]>ele[i-1])
        {
            return 1;
        }
    }
    else if(arr[i]==1)
    {
        if(ele[i]>ele[i+1])
        {
            return 1;
        }
    }
    return 0;
}

int anymob(int ele[], int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(mobile(ele, arr, i))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    printf("Enter number of elements:");
    scanf("%d", &n);
    int ele[n];
    int arr[n];
    printf("Enter the elements:");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&ele[i]);
    }
    for(int i=0; i<n; i++)
    {
        arr[i]=0;
    }
    johnson(ele, arr, n);
    return 0;
}