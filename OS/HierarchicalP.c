#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of items (files/folders):\n");
    scanf("%d", &n);

    int a[n], type[n], childCount[n];
    int File = 0, Folder = 1;

    for (int i = 0; i < n; i++)
    {
        printf("Enter name (number) for item %d:\n", i + 1);
        scanf("%d", &a[i]);
        printf("Is it file(0) or folder(1):\n");
        scanf("%d", &type[i]);
        if (type[i] == Folder)
        {
            printf("Enter number of items under this folder:\n");
            scanf("%d", &childCount[i]);
        }
        else
        {
            childCount[i] = 0;
        }
    }

    int search;
    printf("Enter name (number) to search:\n");
    scanf("%d", &search);

    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == search)
        {
            found = 1;
            printf("%d [%s]\n", a[i], type[i] == File ? "File" : "Folder");
            if (type[i] == Folder && childCount[i] > 0)
            {
                printf("Contains %d item(s)\n", childCount[i]);
            }
            break;
        }
    }
    if (!found)
    {
        printf("Item not found.\n");
    }
    return 0;
}