#include <stdio.h>

#define MAX 10

typedef struct {
    int pid;
    int size;
    int allocated;
} Process;

void worstFit(Process p[], int np, int mem[], int nb) {
    int i, j, index;

    for (i = 0; i < np; i++) {
        index = -1;

        for (j = 0; j < nb; j++) {
            if (mem[j] >= p[i].size) {
                if (index == -1 || mem[j] > mem[index]) {
                    index = j;
                }
            }
        }

        if (index != -1) {
            p[i].allocated = 1;
            mem[index] -= p[i].size;
            printf("Process %d allocated to Block %d\n", p[i].pid, index + 1);
        } else {
            printf("Process %d cannot be allocated\n", p[i].pid);
        }
    }
}

int main() {
    int mem[MAX], nb, np;
    Process p[MAX];

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter sizes of memory blocks:\n");
    for (int i = 0; i < nb; i++) {
        scanf("%d", &mem[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter sizes of processes:\n");
    for (int i = 0; i < np; i++) {
        scanf("%d", &p[i].size);
        p[i].pid = i + 1;
        p[i].allocated = 0;
    }

    printf("\nWorst Fit Allocation:\n");
    worstFit(p, np, mem, nb);

    return 0;
}
