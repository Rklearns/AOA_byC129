#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void kmp();
void prefix();

int m; int n;
#define MAX 100
char T[MAX]="abcedbababd";
char P[MAX]="ababd";
int pi[MAX];


int main()
{
  
    m=strlen(P);
    n=strlen(T);
    kmp();
}
void kmp()
{
   prefix();
   int q=0;
   for(int i=1;i<=n;i++)
   {
    while(q>0 && T[i]!=P[q+1])
    {
        q=pi[q];
    }
    if(T[i]==P[q+1])
    {

        q++;
    }
    if(q==m)
    {
        printf("pattern found to start at position %d",(i-m));//this is one based indexing therefore we give position instead of index
        q=pi[q];
    }
   }

}
void prefix()
{
    int k=0;
    pi[1]=0;
    for(int q=2;q<=m;q++)
    {
        while(k>0 && P[k+1]!=P[q])
        {
            k=pi[k];
        }
        if(P[k+1]==P[q])
        {
            k++;
        }
        pi[q]=k;

    }
   
}