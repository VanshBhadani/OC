#include<string.h> 
#include<stdio.h>

#define maxf 10
#define maxlen 10

int main(){
char directoryname[maxlen];
char filenames[maxf][maxlen]={{0}}; // initialized to 0 to avoid garbage value
char file[maxlen];
int numfiles=0;            //assuming no. of files in directory initially is 0
int i,choice;
printf("Enter directory name:");
scanf("%s",&directoryname);
printf("Number of files to be added in directory");
scanf("%d",&numfiles);
do{
     printf("Enter the name of file to be created:");
     scanf("%s",&file);
     int exists=0;
     for(i=0;i<numfiles;i++)
      {
        if(strcmp(file,filenames[i])==0)
{
printf("file already exists");
exists=1;
break;
}
}
if(!exists && numfiles< maxf)
{
strcpy(filenames[numfiles],file);
numfiles++;
}
printf("Do you want more files?(0-1)");
scanf("%d",&choice);
}while(choice==1);
printf("Directory name:%s",directoryname);
printf("Files:");
for(i=0;i<numfiles;i++)
{
printf("%s \t \n",filenames[i]);
}
return 0;
}

