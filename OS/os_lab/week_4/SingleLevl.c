#include <stdio.h>
int main()
{
	printf("Enter number of Users:");
	int n;
	scanf("%d", &n);
	int filenum[n], username[n], files[n][100];
	printf("Enter number of files for each user:\n");
	for (int i = 0; i < n; i++)
	{
		printf("User %d:\n", i + 1);
		scanf("%d", &filenum[i]);
	}
	printf("Enter User names:");
	for (int i = 0; i < n; i++)
	{
		printf("User %d:\n", i + 1);
		scanf("%d", &username[i]);
	}
	printf("Enter file names:");
	for (int i = 0; i < n; i++)
	{
		printf("User %d\n", username[i]);
		for (int j = 0; j < filenum[i]; j++)
		{
			printf("File %d:", j + 1);
			scanf("%d", &files[i][j]);
		}
		printf("\n");
	}
	printf("User\tFiles\tFile Names\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t%d\t", username[i], filenum[i]);

		for (int j = 0; j < filenum[i]; j++)
		{
			printf("%d\t", files[i][j]);
		}
		printf("\n");
	}
}