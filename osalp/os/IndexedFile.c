// indexed file 
#include<stdio.h>
#include<stdlib.h>
#define max 50

void allocateIndex(int blocks[],int indexBlock)
{
	int numBlocks;
	int i;
	printf("Enter number of blocks needed for files:");
	scanf("%d",&numBlocks);
	int blockIndexes[numBlocks];
	printf("Enter block indexes:");
	for(i=0;i<numBlocks;i++)
	{
		scanf("%d",&blockIndexes[i]);
	}
	int freeBlocks=0;
	for(i=0;i<numBlocks;i++)
	{
		if(blocks[blockIndexes[i]]==0)
		freeBlocks++;
	}
	if(freeBlocks==numBlocks)
	{
		for(i=0;i<numBlocks;i++)
		{
			blocks[blockIndexes[i]]=1;
		}
		printf("Allocated");
		printf("File indexed");
		for(i=0;i<numBlocks;i++)
		{
			printf("%d > %d : %d \n",indexBlock,blockIndexes[i],blocks[blockIndexes[i]]);
		}
	}
	else
	{
		printf("File not allocated");
	}
}

int main()
{
	int blocks[max]={0};
	int choice;
	do
	{
		int indexBlock;
		printf("Enter index block:");
		scanf("%d",&indexBlock);
		if(blocks[indexBlock]==1)
		{
			printf("%d index is already been allocated",indexBlock);
			continue;
		}
		blocks[indexBlock]=1;
		allocateIndex(blocks,indexBlock);
		printf("Enter more files?(0-1)");
		scanf("%d",&choice);
	}while(choice==1);
	return 0;
}
