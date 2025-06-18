#include<stdio.h>
//MVT
int main()
{
	int totm,osm,n,i;
	int prom[n],alloc[10],p[10];
	printf("Enter total memory:");
	scanf("%d",&totm);
	printf("Enter os memory:");
	scanf("%d",&osm);
	printf("Enter number of processes:");
	scanf("%d",&n);
	printf("Enter memory allocated for each process");
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
		scanf("%d",&prom[i]);
		alloc[i]=0;
	}
	
	int bal=totm-osm;
	
	for(i=0;i<n;i++)
	{
		if(bal>=prom[i])
		{
			bal-=prom[i];
			printf("p[%d] is allocated",p[i]);
			alloc[i]=1;
		}
		else
		printf("p[%d] is not allocated",p[i]);
	}
	
	
	printf("External fragmentation is %d",bal);
	return 0;
}
