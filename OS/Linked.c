#include <stdio.h>

int main() {
    printf("Enter no.of Files: ");
    int n;
    scanf("%d", &n);

    int i, size[n], start[n], blocks[n][100], s;

    for (i = 0; i < n; i++) {
        printf("Enter no.of Blocks Occupied by File%d:\t", i + 1);
        scanf("%d", &size[i]);
        printf("Enter Starting Block of File%d:\t", i + 1);
        scanf("%d", &start[i]);
        printf("Enter Block Numbers for File%d (in order of linkage):\t", i + 1);
        for (int j = 0; j < size[i]; j++) {
            scanf("%d", &blocks[i][j]);
        }
    }

    printf("File\tStarting Block\tSize\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i + 1, start[i], size[i]);
    }

    printf("Enter File name :");
    scanf("%d", &s);
    s--; // Adjust for 0-based indexing

    printf("File name is: %d\tFile size is: %d\t", s + 1, size[s]);
    printf("Blocks occupied are: ");
    printf("%d", start[s]);
    for (int j = 0; j < size[s]; j++) {
        printf(" --> %d", blocks[s][j]);
    }
    printf("\n");
    return 0;
}