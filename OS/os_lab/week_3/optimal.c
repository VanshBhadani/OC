#include<stdio.h>
void optimal(int pages[],int n,int capacity){
    int frames[capacity],pagefaults=0;
    for(int i=0;i<capacity;i++) frames[i]=-1;
    for(int i=0;i<n;i++){
        printf("%d:",pages[i]);
        int found=0;
        for(int j=0;j<capacity;j++){
            if(frames[j]==pages[i]){
                found=1;
                break;
            }
        }
        if(!found){
            if(i<capacity)
                frames[i]=pages[i];
            else{
                int farthest=-1,replaceindex=-1;
                for(int j=0;j<capacity;j++){
                    int k;
                    for(k=i+1;k<n;k++){
                        if(frames[j]==pages[k]){
                            if(k>farthest){
                                farthest=k;
                                replaceindex=j;
                            }
                            break;
                        }
                    }
                    if(k==n){
                        replaceindex=j;
                        break;
                    }
                }
                frames[replaceindex]=pages[i];
            }
            pagefaults++;
        }
        for(int j=0;j<capacity;j++){
            printf("%d ",frames[j]);
        }
        printf("\n");
    }
    printf("no of page faults is : %d\n",pagefaults);
}
int main(){
    int n,capacity;
    printf("enter capaacity of frames\n");
    scanf("%d",&capacity);
    printf("enter length of references\n");
    scanf("%d",&n);
    int pages[n];
    printf("enter references\n");
    for(int i=0;i<n;i++)
        scanf("%d",&pages[i]);
    optimal(pages,n,capacity);
    return 0;
}