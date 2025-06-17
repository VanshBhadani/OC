#include<stdio.h>
void Lru(int pages[],int n,int capacity){
    int frames[capacity],recent[capacity],pagefaults=0;
    for(int i=0;i<capacity;i++) frames[i]=recent[i]=-1;
    for(int i=0;i<n;i++){
        int found=0;
        for(int j=0;j<capacity;j++){
            if(frames[j]==pages[i]){
                found=1;
                recent[j]=i;
                break;
            }
        }
        if(!found){
            int lruindex=0;
            for(int j=1;j<capacity;j++){
                if(recent[j]<recent[lruindex]){
                    lruindex=j;
                }
            }
            frames[lruindex]=pages[i];
            recent[lruindex]=i;
            pagefaults++;
        }
        for(int j=0;j<capacity;j++)
            printf("%d ",frames[j]);
        printf("\n");
    }
    printf("no of page faults is:%d",pagefaults);
}
int main() {
    int n, capacity;
    printf("Enter no of frames: ");
    scanf("%d", &capacity);
    printf("Enter reference string length: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &pages[i]);
    Lru(pages, n, capacity);
    return 0;
}