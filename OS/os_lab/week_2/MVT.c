#include<stdio.h>
int main(){
    int totm,osm,n;
    rintf("enter total available memory:");
    scanf("%d",&totm);
    printf("enter os memory:");
    scanf("%d",&osm);
    printf("enter no of processes:");
    scanf("%d",&n);
    int bal=totm-osm;
    int p[n];
    printf("enter process sizes:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);
    for(int i=0;i<n;i++){
        if(p[i]<=bal){
            bal-=p[i];
            printf("process %d is allowed\n",i+1);
        }
        else
        printf("process %d is blocked\n",i+1);
    }
    printf("external fragmentation is :%d",bal);
    return 0;
}