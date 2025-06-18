#include <stdio.h>

#define MAX_PAGES 50
#define MAX_FRAMES 10

int main() {
    int pages[MAX_PAGES], frames[MAX_FRAMES];
    int n, f, pageFaults = 0;
    int frameIndex = 0;
    int i,j,k;
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page sequence: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of page frames: ");
    scanf("%d", &f);

    for ( i = 0; i < f; i++) {
        frames[i] = -1;
    }

    for (i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if page is already in frames
        for ( j = 0; j < f; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            pageFaults++;

            // If frames are not full, add page to frames
            if (frameIndex < f) {
                frames[frameIndex] = page;
                frameIndex++;
            } else {
                // Find the least recently used page
                int lruIndex = 0;
                for ( j = i - 1; j >= 0; j--) {
                    for (k = 0; k < f; k++) {
                        if (pages[j] == frames[k]) {
                            if (k == lruIndex) {
                                break;
                            } else if (k > lruIndex) {
                                lruIndex = k;
                            }
                        }
                    }
                    if (lruIndex != 0) {
                        break;
                    }
                }
                frames[lruIndex] = page;
            }
        }

        printf("Page %d: ", page);
        for ( j = 0; j < f; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", pageFaults);
    return 0;
}
