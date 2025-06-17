#include<stdio.h>
int main() {
    printf("Enter no.of Files: ");
    int n;
    scanf("%d", &n);
    int i, index[n], size[n], blocks[n][20]; // Arrays for index, size, and blocks
    for (i = 0; i < n; i++) {
        printf("Enter Index Block of File%d:\t", i + 1);
        scanf("%d", &index[i]); // Store index block
        printf("Enter no.of Blocks Occupied by File%d:\t", i + 1);
        scanf("%d", &size[i]); // Store size
        printf("Enter Blocks Occupied by File%d:\t", i + 1);
        for (int j = 0; j < size[i]; j++) {
            scanf("%d", &blocks[i][j]); // Store block numbers
        }
    }
    printf("File\tIndex Block\tSize\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i + 1, index[i], size[i]);
    }
    printf("Enter File name :", n);
    int s;
    scanf("%d", &s);
    s--; // Adjust for 0-based indexing
    printf("File name is: %d\t", s + 1);
    printf("Index block is: %d\t", index[s]);
    printf("Blocks occupied are: ");
    for (int j = 0; j < size[s]; j++) {
        printf("%d ", blocks[s][j]);
    }
    printf("\n");
    return 0;
}