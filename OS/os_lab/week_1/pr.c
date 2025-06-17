#include<stdio.h>
int main(){
    printf("Enter the no of processes\n");
    int n;
    scanf("%d",&n);
    float sum1=0,sum2=0;
    int p[n],b[n],w[n],t[n],pr[n];
    printf("Enter the time for each processes\n");
    for(int i=0;i<n;i++){
        p[i]=i+1;
        scanf("%d",&b[i]);
    }
    printf("Enter the priority for each process :\n");
    for(int i=0;i<n;i++){
        
        scanf("%d",&pr[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(pr[i]<pr[j]){
               int a=b[i];
               b[i]=b[j];
               b[j]=a;
               a=p[i];
               p[i]=p[j];
               p[j]=a;
               a=pr[i];
               pr[i]=pr[j];
               pr[j]=a;
            }
        }
    }
    w[0]=0;
    t[0]=b[0];
    sum2=sum2+t[0];
    for(int i=1;i<n;i++){
        w[i]=t[i-1];
        t[i]=w[i]+b[i];
        sum1=sum1+w[i];
        sum2=sum2+t[i];
    }
    printf("PID\tBT\tP\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",p[i],b[i],pr[i],w[i],t[i]);
    }
    printf("Average Waiting Time :\t%f\n",(sum1/n));
    printf("Average Turn Around Time :\t%f\n",(sum2/n));
    return 0;
}