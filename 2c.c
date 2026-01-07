#include <stdio.h>
int main()
{
    int n;
    printf("Enter Total Number of Processes:");
    scanf("%d", &n);
    int arr[n], bt[n], temp[n];
    int wait = 0, tat = 0, x = n;
    for(int i = 0; i < n; i++)
    {
        printf("Enter Details of Process %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arr[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }
    int tq;
    printf("Enter Time Slot:");
    scanf("%d", &tq);
    int total = 0, i = 0, flag = 0;
    printf("Process ID Burst Time Turnaround Time Waiting Time\n");
    while(x != 0)
    {
        if(temp[i] <= tq && temp[i] > 0)
        {
            total += temp[i];
            temp[i] = 0;
            flag = 1;
        }
        else if(temp[i] > 0)
        {
            temp[i] -= tq;
            total += tq;
        }
        if(temp[i] == 0 && flag == 1)
        {
            x--;
            printf("\nProcess No %d \t\t %d\t\t\t\t %d\t\t\t %d",
                   i + 1, bt[i], total - arr[i], total - arr[i] - bt[i]);
            wait += total - arr[i] - bt[i];
            tat += total - arr[i];
            flag = 0;
        }
        if(i == n - 1)
            i = 0;
        else if(arr[i + 1] <= total)
            i++;
        else
            i = 0;
    }
    printf("\nAverage Waiting Time:%f", (float)wait / n);
    printf("\nAvg Turnaround Time:%f", (float)tat / n);
    return 0;
}