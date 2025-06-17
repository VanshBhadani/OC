#include <stdio.h>
int main()
{
    printf("Enter no.of Files: ");
    int n;
    scanf("%d", &n);
    int i, blocksize[n], startblock[n], s; // Arrays for size and starting block, and variable for file name
    for (i = 0; i < n; i++)
    { // Loop starts from 0 and goes up to n-1
        printf("Enter no.of Block Occupied by  File%d:\t", i + 1);
        scanf("%d", &blocksize[i]); // Store size in array
        printf("Enter Starting Block of the File%d:\t", i + 1);
        scanf("%d", &startblock[i]); // Store starting block in array
    }
    printf("File\tStarting Block\tSize\n");
    for (i = 0; i < n; i++)
    { // Loop starts from 0 and goes up to n-1
        printf("%d\t%d\t\t%d\n", i + 1, startblock[i], blocksize[i]);
    }
    printf("Enter File name :");
    scanf("%d", &s);
    s--; // Adjust for 0-based indexing
    printf("File name is: %d\tFile size is: %d\t", s + 1, blocksize[s]);
    printf("Blocks occupied are: ");
    for (int k = startblock[s]; k < startblock[s] + blocksize[s]; k++)
    {
        printf("%d ", k);
    }
    printf("\n");
    return 0;
}
