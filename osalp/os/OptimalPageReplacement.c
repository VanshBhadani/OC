#include <stdio.h>

#define MAX_PAGES 50
#define MAX_FRAMES 20

int main() {
    int pages[MAX_PAGES], frames[MAX_FRAMES];
    int n, f, pageFaults = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int i, j, k;
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
        int page = pages[i];
        int found = 0;

        // Check if page is already in frames
        for (j = 0; j < f; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            pageFaults++;

            // If frames are not full, add page to frames
            if (i < f) {
                frames[i] = page;
            } else {
                // Find page that will not be used for the longest duration
                int maxDistance = -1, replaceIndex = 0;
                for (j = 0; j < f; j++) {
                    int distance = 0;
                    for (k = i + 1; k < n; k++) {
                        if (pages[k] == frames[j]) {
                            break;
                        }
                        distance++;
                    }
                    if (distance > maxDistance) {
                        maxDistance = distance;
                        replaceIndex = j;
                    }
                }
                frames[replaceIndex] = page;
            }
        }

        // Print frames
        printf("Page %d: ", page);
        for (j = 0; j < f; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("Number of page faults: %d\n", pageFaults);
    return 0;
}
