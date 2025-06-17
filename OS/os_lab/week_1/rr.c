#include<stdio.h>
int main(){
    int n,q,c=0,tt=0;float sum1=0,sum2=0;
    printf("enter no of processes:");scanf("%d",&n);
    int b[n],w[n],t[n],r[n];
    printf("enter time of each processes:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
        r[i]=b[i];
    }
    printf("enter time quantum\n");
    scanf("%d",&q);
    while(c<n){
        for(int i=0;i<n;i++){
            if(r[i]>0){
                if(r[i]>q){
                    tt+=q;
                    r[i]-=q;
                }else{
                    tt+=r[i];
                    r[i]=0;
                    t[i]=tt;
                    sum2+=t[i];
                    c++;
                }
            }
        }
    }
    printf("pid\tbt\twt\ttat\n");
    for(int i=0;i<n;i++){
        w[i]=t[i]-b[i];
        sum1+=w[i];
        printf("%d\t%d\t%d\t%d\n",i+1,b[i],w[i],t[i]);
    }
    printf("average wait time:%.2f",sum1/n);
    printf("average turn around time:%.2f",sum2/n);
    return 0;
}