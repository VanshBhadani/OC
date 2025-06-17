#include <stdio.h>
void fifo(int pages[], int n, int capacity) {
    int frame[capacity], count = 0, pageFaults = 0;
    for (int i = 0; i < capacity; i++) frame[i] = -1;
    for (int i = 0; i < n; i++) {
        printf("%d: ", pages[i]);
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            frame[count % capacity] = pages[i];
            count++;
            pageFaults++;
        }
        for (int j = 0; j < capacity; j++) {
            printf("%d",frame[j]);
        }
        printf("\n");
    }
    printf("\nNo of Page Faults with FIFO: %d\n", pageFaults);
}
int main() {
    int n, capacity;
    printf("Enter no of frames: ");
    scanf("%d", &capacity);
    printf("Enter reference string length: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    fifo(pages, n, capacity);
    return 0;
}