#include <stdio.h>

int main() {
    int n = 5; // Number of processes
    int m = 3; // Number of resources
    int i,j,k;

    // Allocation Matrix
    int alloc[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    // MAX Matrix
    int max[5][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    // Available Resources
    int avail[3] = {3, 3, 2};

    // Calculate Need Matrix
    int need[5][3];
    for (i = 0; i < n; i++) {
        for ( j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("Need Matrix:\n");
    for ( i = 0; i < n; i++) {
        printf("P%d: ", i);
        for ( j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Find Safe Sequence
    int finished[5] = {0};
    int safeSeq[5];
    int ind = 0;

    for ( k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (!finished[i]) {
                int canFinish = 1;
                for ( j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        canFinish = 0;
                        break;
                    }
                }

                if (canFinish) {
                    safeSeq[ind++] = i;
                    for (j = 0; j < m; j++) {
                        avail[j] += alloc[i][j];
                    }
                    finished[i] = 1;
                }
            }
        }
    }

    printf("Safe Sequence: ");
    for (i = 0; i < n; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");

    return 0;
}
