//program to count number of function calls during calculation of tower of hanoi
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void hanoi(int n, char S, char A, char D, int *ptr_count)
{
    (*ptr_count)++;
    if(n==1)
    {
        printf("Move disc from %c to %c \n",S,D);
        return;
    }
        hanoi(n-1,S,D,A,ptr_count);
        printf("Move disc from %c to %c \n",S,D);
        hanoi(n-1,A,S,D,ptr_count);
}

int main()
{
    int n;
    int count=0;
    printf("Enter a number:");
    scanf("%d",&n);
    hanoi(n,'A','B','C', &count);
    printf("count : %d \n",count);
    return 0;
}