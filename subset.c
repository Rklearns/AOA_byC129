#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void subset(int s, int r, int k); 
#define MAX 100
int m;
int x[MAX];// stores whether wts including or not like 1 0 1 1
int w[MAX];

int main()
{
    printf("enter the target\n");
    scanf("%d",&m);
    printf("enter 5 wts");
    int total=0;
    for(int i=0;i<5;i++)
    {
        scanf("%d",&w[i]);
        total+=w[i];
    }
    if(m>total)
    {
        printf("invalid pls enter proper wts\n");
    }
    else{subset(0,total,0);}   
    return 0;
}
void subset(int s, int r, int k)
{
    x[k]=1;
    if(s+w[k]==m)
    {
        printf("subset is\n");
        for(int i=0;i<=k;i++)
        {
            if(x[i]==1)
            {
            printf("%d ",w[i]);
            }
        }
        printf("\n");
    }
    else if(s+w[k]+w[k+1]<=m)
    {
        subset(s+w[k],r-w[k],k+1);
    }
    if(s-w[k]+r>=m && s+w[k+1]<=m)
    {
        x[k]=0;
        subset(s,r-w[k],k+1);
    }
}
