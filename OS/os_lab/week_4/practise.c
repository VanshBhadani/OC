#include <stdio.h>
int main()
{
    int n, i, j, k; 
    printf("no of users: ");
    scanf("%d", &n);
    int dirnum[n], username[n], dir[n][100], filenum[n][100], file[n][100][100];

    printf("enter user name: ");
    for(i = 0; i<n ; i++)
    {
        scanf("%d", &username[i]);
    }

    printf("enter directory");
    {
        
        for(i = 0; i<n ; i++)
        {
            scanf("%d", &dirnum[i]);
        }
    }

    printf("enter directory name");
    {
        
        for(i = 0; i<n ; i++)
        {
            for(j = 0; j< dirnum[i]; j++)
            {
                scanf("%d", &dir[i][j]);
            }
        }
    }
    printf("enter file size");
    {
        
        for(i = 0; i<n ; i++)
        {
            for(j = 0; j< dirnum[i]; j++)
            {
                scanf("%d", &filenum[i][j]);
            }
        }
    }

        printf("enter file name");
    {
        
        for(i = 0; i<n ; i++)
        {
            for(j = 0; j< dirnum[i]; j++)
            {
                for(k = 0; k < filenum[i][j]; k++)
                {
                    scanf("%d", &file[i][j][k]);
                }
            }
        }
    }


    printf("User\tDir_Size\tDir\t\tFile_Size\tFiles\n");

    for(i = 0; i< n ;i++)
    {
        printf("%d\t %d \t", username[i], dirnum[i]);

        for(j = 0; j< dirnum[i]; j++)
        {
            printf("%d \t %d \t", dir[i][j], filenum[i][j]);
        }

        for(k = 0; k< filenum[i][j]; k++)
        {
            printf("%d", file[i][j][k]);
        }

    }
}