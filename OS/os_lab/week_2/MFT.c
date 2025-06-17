#include<stdio.h>
int main(){
    int osm,part,totm,n,intfrag=0;
    printf("enter total available memory:");
    scanf("%d",&totm);
    printf("enter os memory:");
    scanf("%d",&osm);
    printf("enter no of partitions:");
    scanf("%d",&part);
    int bal=totm-osm;
    bal/=part;
    printf("the fixed size of each partition is %d\n",bal);
    printf("enter no of process:");
    scanf("%d",&n);
    int p[n];
    printf("enter process sizes:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);
    for(int i=0;i<n;i++){
        if(part>0 && bal>=p[i]){
            intfrag+=bal-p[i];
            printf("process %d is allowed\n",i+1 );
            part--;
        }
        else
        printf("process %d is blocked\n",i+1 );
    }
    printf("internal fragmentation is :%d",intfrag);
    return 0;
}