#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int n;
#define MAX 100
int x[MAX];
void nqueen(int k);
int issafe(int i, int k);
int main()
{
    printf("enter number of queens\n");
    scanf("%d",&n);
    nqueen(1);
    return 0;
}
void nqueen(int k)
{
    for(int i=1;i<=n;i++)
    {
        //now we will have to see whether we can place the queen at i row and k colum
        if(issafe(i,k))//this means if it returns 1 
        {
            x[k]=i;
            if(k==n)//then just print
            {
                for(int j=1;j<=n;j++)
                {
                    printf("%d ",x[j]);
                }
                printf("\n");
            }
            else{
                nqueen(k+1);//ek k safe hogaya ab next k ki baari 
            }
            //abhi tak agar koi k safe nahi hai then dekhega kya next i se wo k safe ho sakta kinahi
        }
    }

}
int issafe(int i, int k)
{
    for(int j=1;j<=k-1;j++)//iterating through columns 1 to k-1 since those must already be filled
    {
        if(x[j]==i || abs(x[j]-i)==abs(j-k))
        {
            return 0;
        }
    }
    return 1;
}
