#include <stdio.h>
#include <stdlib.h>

struct fcfs
{
    int pid;
    int btime;
    int wtime;
    int ttime;
} p[10];

int main()
{
    int i, n;
    int totwtime = 0, totttime = 0;

    printf("\nFCFS scheduling...\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("\nBurst time of process %d: ", p[i].pid);
        scanf("%d", &p[i].btime);
    }

    p[0].wtime = 0;
    p[0].ttime = p[0].btime;
    totttime += p[0].ttime;

    for (i = 1; i < n; i++)
    {
        p[i].wtime = p[i - 1].wtime + p[i - 1].btime;
        p[i].ttime = p[i].wtime + p[i].btime;
        totwtime += p[i].wtime;
        totttime += p[i].ttime;
    }

    printf("\nPID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].btime, p[i].wtime, p[i].ttime);
    }

    printf("\nTotal waiting time: %d", totwtime);
    printf("\nAverage waiting time: %f", (float)totwtime / n);
    printf("\nTotal turnaround time: %d", totttime);
    printf("\nAverage turnaround time: %f", (float)totttime / n);

    return 0;
}

