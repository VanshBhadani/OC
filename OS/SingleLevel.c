#include <stdio.h>
int main()
{
	printf("Enter number of Users:");
	int n;
	scanf("%d", &n);
	int a[n], b[n], files[n][100];
	printf("Enter number of files for each user:\n");
	for (int i = 0; i < n; i++)
	{
		printf("User %d:\n", i + 1);
		scanf("%d", &a[i]);
	}
	printf("Enter User names:");
	for (int i = 0; i < n; i++)
	{
		printf("User %d:\n", i + 1);
		scanf("%d", &b[i]);
	}
	printf("Enter file names:");
	for (int i = 0; i < n; i++)
	{
		printf("User %d\n", b[i]);
		for (int j = 0; j < a[i]; j++)
		{
			printf("File %d:", j + 1);
			scanf("%d", &files[i][j]);
		}
		printf("\n");
	}
	printf("User\tFiles\tFile Names\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t%d\t", b[i], a[i]);

		for (int j = 0; j < a[i]; j++)
		{
			printf("%d\t", files[i][j]);
		}
		printf("\n");
	}
}
