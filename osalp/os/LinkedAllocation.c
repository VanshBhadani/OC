// linked allocation execution
#include <stdio.h>
#define max 30

void allocateBlocks(int blocks[]) {
    int start, len;
    printf("Enter start block: ");
    scanf("%d", &start);
    printf("Enter length: ");
    scanf("%d", &len);

    if (blocks[start] == 1) {
        printf("%d block is already allocated\n", start);
        return;
    }

    int i;
    for (i = start; i < start + len; i++) {
        if (blocks[i] == 1) {
            printf("%d block is already allocated\n", i);
            len++;
        } else {
            blocks[i] = 1;
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int blocks[max] = {0};
    int choice;
    int n;
    printf("How many blocks are already allocated: ");
    scanf("%d", &n);
    printf("Enter blocks already allocated: ");
    int i;
    for (i = 0; i < n; i++) {
        int block;
        scanf("%d", &block);
        blocks[block] = 1;
    }
    do {
        allocateBlocks(blocks);
        printf("More files? (0/1): ");
        scanf("%d", &choice);
    } while (choice == 1);
    return 0;
}
