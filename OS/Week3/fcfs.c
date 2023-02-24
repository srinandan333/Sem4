//Program to demo "First Come First Serve" CPU scheduling

#include <stdio.h>
#include <string.h>

int main()
{
    char processname[10][10],t[10];
    int arrival[10],burst[10],start[10],finish[10],turnaround[10],waiting[10],i,j,n,temp;
    int totalwaiting = 0, totalturnaround = 0;

    printf("Enter the number of processes to schedule:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the Process Name, Arrival Time and Burst Time of the processes:");
        scanf("%s %d %d", processname[i], &arrival[i], &burst[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arrival[i] < arrival[j])
            {
	       temp = arrival[i];
	       arrival[i] = arrival[j];
	       arrival[j] = temp;
	       temp = burst[i];
	       burst[i] = burst[j];
	       burst[j] = temp;
	       strcpy(t, processname[i]);
	       strcpy(processname[i],processname[j]);
	       strcpy(processname[j],t);
	    }
	}
    }

    for (i = 0; i < n; i++)
    {
        if (i == 0)
	   start[i] = arrival[i];
        else
           start[i] = finish[i-1];

	waiting[i]=start[i]-arrival[i];
        finish[i]=start[i]+burst[i];
        turnaround[i]=finish[i]-arrival[i];
    }

    printf("\nProcessName\tArrivalTime\tBurstTime\tWaitTime\tStart\tTurnAroundTime\tFinish");
    printf("\n-----------\t-----------\t---------\t--------\t-----\t--------------\t------");

    for (i = 0; i < n; i++)
    {
        printf("\n%s\t\t%3d\t\t%3d\t\t%3d\t\t%3d\t%6d\t\t%6d",processname[i],arrival[i],burst[i],waiting[i],start[i],turnaround[i],finish[i]);
        totalwaiting += waiting[i];
        totalturnaround += turnaround[i];
    }

    printf("\n\nAverage Waiting time:%f",(float)totalwaiting/n);
    printf("\nAverage Turn Around Time:%f\n",(float)totalturnaround/n);
    return 0;
}
