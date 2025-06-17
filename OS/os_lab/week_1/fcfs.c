#include<stdio.h>
int main(){
    printf("Enter the no of processes\n");
    int n;
    scanf("%d",&n);
    float sum1=0,sum2=0;
    int p[n],b[n],w[n],t[n];
    printf("Enter the time for each processes\n");
    for(int i=0;i<n;i++){
        p[i]=i+1;
        scanf("%d",&b[i]);
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
    printf("PID\tB\tWT\tT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\n",p[i],b[i],w[i],t[i]);
    }
    printf("Average Waiting Time :\t%f\n",(sum1/n));
    printf("Average Turn Around Time :\t%f\n",(sum2/n));
    return 0;
}