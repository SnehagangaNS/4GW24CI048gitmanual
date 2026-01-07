#include <stdio.h>
void main()
{
    int n, m, i, j, k, y;
    int alloc[20][20], max[20][20], need[20][20];
    int available[20], f[20] = {0}, ans[20], ind = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    printf("Enter the value of allocation matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
        {
            printf("Enter the value at position (%d%d):", i+1, j+1);
            scanf("%d", &alloc[i][j]);
        }
    printf("Enter the value of max matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
        {
            printf("Enter the value at position (%d%d):", i+1, j+1);
            scanf("%d", &max[i][j]);
        }
    printf("Enter the value in available:\n");
    for(j = 0; j < m; j++)
    {
        printf("Enter the value at position (%d):", j+1);
        scanf("%d", &available[j]);
    }
    // Need matrix
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    // Banker's Algorithm
    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            if(f[i] == 0)
            {
                int flag = 0;
                for(j = 0; j < m; j++)
                    if(need[i][j] > available[j]) { flag = 1; break; }
                if(flag == 0)
                {
                    ans[ind++] = i;
                    for(y = 0; y < m; y++)
                        available[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
    // Output (MATCHES YOUR NOTEBOOK)
    printf("The safe sequence is : ");
    for(i = 0; i < n-1; i++)
        printf("P%d -> ", ans[i]);
    printf("P%d", ans[n-1]);
}