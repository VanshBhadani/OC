#include<stdio.h>
#define max 50

void allocateFiles(int blocks[],int size)
{
	int start,len;
	printf("Enter the starting point and the length of files: \n");
	scanf("%d %d", &start, &len);
	int i;
	if(start+len>size)
	{
		printf("File exceeds the disc size");
		return ;
	}
	int freeBlocks=0;
	for(i=start;i<start+len;i++)
	{
		if(blocks[i]==0)
		freeBlocks++;
	}
	
	if(freeBlocks==len)
	{
		printf("Files allocated are: \n");
		for(i=start;i<start+len;i++)
		{
			blocks[i]=1;
			printf("%d \t \n",i);
		}
		printf("Files are allocated");
	}
	else
	printf("Files not allocated \n");
}


int main()
{
	int blocks[max]={0};
	int choice;
	do
	{
		allocateFiles(blocks,max);
		printf("Do you want to add more files?(0-1)");
		scanf("%d",&choice);
	} while(choice==1);
}
