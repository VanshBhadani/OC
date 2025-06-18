#include<stdio.h>

int main()
{
	int totm,osm,n,i,epar,par;
	int prom[n],alloc[10],p[10];
	printf("Enter total memory:");
	scanf("%d",&totm);
	printf("Enter os memory:");
	scanf("%d",&osm);
	printf("Enter number of processes:");
	scanf("%d",&n);
		printf("Enter partition number:");
	scanf("%d",&par);
	printf("Enter memory of each partition:");
	scanf("%d",&epar);
	printf("Enter memory allocated for each process");
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
		scanf("%d",&prom[i]);
		alloc[i]=0;
	}
	
	
	int bal=0;
	int apar=par;   //available partitions
	
	for(i=0;i<n;i++)
	{
		if(apar>0)
		{
			if(prom[i]<=epar)   //memory of each process <= size of each partition 
			{
				apar--;
				bal+=(epar-prom[i]);
				printf("p[%d] is allocated",p[i]);
				alloc[i]=1;
			}
			else
			{
				printf("p[%d] is not allocated",p[i]);
			}
		}
		else
		{
			printf("p[%d] is allocated",p[i]);
		}
	}
	
	
	printf("Internal fragmentation is %d",bal);
	return 0;
}
