#include<stdio.h>
int main()
{
	int i,j,n,temp,p[10],pri[10],bt[10],wt[10],tat[10],awt,atat; 
	printf("Enter no. of processes");
	scanf("%d",&n);
	printf("Enter the burst time and priority");
	for(i=0;i<n;i++)
	{
		printf("process number: %d",i+1);
		scanf("%d %d",&bt[i],&pri[i]);
		p[i]=i;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(pri[i]<pri[j])
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
				
				temp=pri[i];
				pri[i]=pri[j];
				p[j]=temp;
				
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
			}
		}
	}
	wt[0]=0;
	awt=0;
	tat[0]=bt[0];
	atat=tat[0];
	
	
	for(i=1;i<n;i++)
	{
		wt[i]=tat[i-1];
		awt=awt+wt[i];
		tat[i]=wt[i]+bt[i];
		atat=atat+tat[i];
	}
	
	printf(" JOB BT WT TAT P");
	for(i=0;i<n;i++)
	{
		printf("%d %d %d %d",p[i],bt[i],wt[i],tat[i],pri[i]);
	}
}

