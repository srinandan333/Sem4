//Program to demo "Shortest Job First" CPU scheduling

#include <stdio.h>
#include <string.h>

void main()
{
    int execution[20],arrival[10],n,i,j,temp,start[10],finish[10],waiting[10],turnaround[10];
    int totalwaiting = 0, totalturnaround = 0;
    float averagewaiting, averageturnaround;
    char processname[10][10], t[10];
			    
    printf("Enter the number of processes to schedule:");
    scanf("%d",&n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the process name, arrival time and execution time of each process:");
        scanf("%s %d %d", processname[i], &arrival[i], &execution[i]);
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (execution[i] < execution[j])
            {
	        temp = arrival[i];
	        arrival[i] = arrival[j];
	        arrival[j] = temp;
	        temp = execution[i];
	        execution[i] = execution[j];
	        execution[j] = temp;
	        strcpy(t, processname[i]);
	        strcpy(processname[i], processname[j]);
	        strcpy(processname[j], t);
	    }
	}

    for (i = 0; i < n; i++)
    {
        if (i == 0)
	   start[i] = arrival[i];
        else
           start[i] = finish[i-1];

	waiting[i] = start[i] - arrival[i];
	finish[i] = start[i] + execution[i];
	turnaround[i] = finish[i] - arrival[i];
	totalwaiting += waiting[i];
	totalturnaround += turnaround[i];
    }

    averagewaiting = (float)totalwaiting/n;
    averageturnaround = (float)totalturnaround/n;

    printf("\nProcess\tArrivalTime\tExecutionTime\tWaitingTime\tTurnAroundTime");
    printf("\n-------\t-----------\t-------------\t-----------\t--------------");

    for (i = 0; i < n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d",processname[i],arrival[i],execution[i],waiting[i],turnaround[i]);

    printf("\nAverage waiting time is: %f", averagewaiting);
    printf("\nAverage turnaround time is: %f\n", averageturnaround);
}
