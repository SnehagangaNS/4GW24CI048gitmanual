#include <stdio.h>
int main()
{
    int bt[20], p[20], wt[20], tat[20], n;
    int total = 0, totalT = 0;
    float avg_wt, avg_tat;
    printf("Enter number of process:");
    scanf("%d", &n);
    printf("\nEnter Burst Time:\n");
    for(int i = 0; i < n; i++)
    {
        printf("p%d:", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }
    // Sorting processes based on burst time (SJF)
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(bt[i] > bt[j])
            {
                int t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = p[i]; p[i] = p[j]; p[j] = t;
            }
    wt[0] = 0;
    for(int i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        total += wt[i];
    }
    printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
    for(int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        totalT += tat[i];
        printf("\np%d\t\t %d\t\t %d\t\t\t%d", p[i], bt[i], wt[i], 
tat[i]);
    }
    avg_wt = (float)total / n;
    avg_tat = (float)totalT / n;
    printf("\n\nAverage Waiting Time=%f", avg_wt);
    printf("\nAverage Turnaround Time=%f", avg_tat);
    return 0;
}