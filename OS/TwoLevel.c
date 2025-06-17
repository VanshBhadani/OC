#include <stdio.h>
int main()
{
	int n;
	printf("Enter number of Users:");
	scanf("%d", &n);
	int a[n], b[n], dir[n][100], file_size[n][100], files[n][100][100];

	printf("Enter number of Directories:");
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("Enter User names:");
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);

	printf("Enter Directory Names:");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a[i]; j++)
			scanf("%d", &dir[i][j]);
	}

	printf("Enter File Sizes:");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a[i]; j++)
			scanf("%d", &file_size[i][j]);
	}

	printf("Enter File Names:");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a[i]; j++)
		{
			for (int k = 0; k < file_size[i][j]; k++)
				scanf("%d", &files[i][j][k]);
		}
	}

	printf("User\tDir_Size\tDir\t\tFile_Size\tFiles\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t%d\t\t", b[i], a[i]);
		// Print all directories for this user
		for (int j = 0; j < a[i]; j++)
			printf("%d ", dir[i][j]);
		printf("\t");
		// Print all file sizes for this user
		for (int j = 0; j < a[i]; j++)
			printf("%d ", file_size[i][j]);
		printf("\t");
		// Print all files for this user
		for (int j = 0; j < a[i]; j++)
			for (int k = 0; k < file_size[i][j]; k++)
				printf("%d ", files[i][j][k]);
		printf("\n");
	}
	return 0;
}