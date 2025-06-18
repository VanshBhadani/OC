#include <stdio.h>

#define MAX_PAGES 50
#define MAX_FRAMES 20

int main() {
    int pages[MAX_PAGES], frames[MAX_FRAMES];
    int n, f, pageFaults = 0;
    int i, j, k, found, front = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the sequence of page numbers referenced: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of page frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        frames[i] = -1;
    }

    for (i = 0; i < n; i++) {	
        found = 0;
        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            pageFaults++;
            frames[front] = pages[i];
            front = (front + 1) % f;
        }

        printf("Page %d: ", pages[i]);
        for (j = 0; j < f; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("\nNumber of Page Faults: %d", pageFaults);
    return 0;
}
