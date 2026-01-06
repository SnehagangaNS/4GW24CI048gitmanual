#include <stdio.h>

int main() {
    int frames, pages;
    int pageFaults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int reference[pages];
    printf("Enter page reference string:\n");
    for (int i = 0; i < pages; i++) {
        scanf("%d", &reference[i]);
    }

    int memory[frames];
    for (int i = 0; i < frames; i++) {
        memory[i] = -1;   // Empty frames
    }

    int fifoIndex = 0;

    printf("\nPage\tMemory Frames\n");
    printf("-------------------------\n");

    for (int i = 0; i < pages; i++) {
        int page = reference[i];
        int found = 0;

        // Check if page already exists in memory
        for (int j = 0; j < frames; j++) {
            if (memory[j] == page) {
                found = 1;
                break;
            }
        }

        // Page Fault
        if (!found) {
            memory[fifoIndex] = page;
            fifoIndex = (fifoIndex + 1) % frames;
            pageFaults++;
        }

        // Display memory status
        printf("%d\t", page);
        for (int j = 0; j < frames; j++) {
            if (memory[j] != -1)
                printf("%d ", memory[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}

