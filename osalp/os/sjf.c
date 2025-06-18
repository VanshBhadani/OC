#include<stdio.h> 
#include<string.h> 
int main() 
{ 
    int i,j,n,temp,p[10],bur[10],tat[10],wt[10]; 
    int totwt=0,tottat=0; 
    printf("Enter the number of processes:"); 
    scanf("%d",&n); 
    for(i=0; i<n; i++) 
    { 
        printf("Enter the ProcessName & Burst Time:"); 
        scanf("%d %d",&p[i],&bur[i]); 
    } 
    for(i=0; i<n; i++) 
    { 
        for(j=0; j<n-i-1; j++) 
        { 
            if(bur[j]>bur[j+1]) 
            { 
                temp=bur[j]; 
                bur[j]=bur[j+1]; 
                bur[j+1]=temp; 
   
                temp=p[j]; 
                p[j]=p[j+1]; 
                p[j+1]=temp; 
            } 
        } 
    }  
    printf("\nPName Burtime WaitTime TAT "); 
    for(i=0; i<n; i++) 
    { 
        wt[i]=0; 
        tat[i]=0; 
        for(j=0;j<i;j++) 
          { 
            wt[i]=wt[i]+bur[j]; 
          } 
        tat[i]=wt[i]+bur[i]; 
        totwt = totwt+wt[i]; 
        tottat = tottat+tat[i]; 
 
        printf("\n %d\t %d\t %d \t %d \n",p[i],bur[i],wt[i],tat[i]);       
    } 
    printf("\nAverage Waiting time:%f",(float)totwt/n); 
    printf("\nAverage Turn Around Time:%f",(float)tottat/n); 
    return 0; 
} 
