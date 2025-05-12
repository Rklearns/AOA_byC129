#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void printlcs(int i, int j);
#define MAX 100
char arrow[MAX][MAX];//this indicates the arrow of the table 
int l[MAX][MAX];//this stores the length of the lcs
char x[MAX];//character array of both the elements
char y[MAX];

int main()
{
    printf("enter string1\n");
    scanf("%s",&x);
    printf("enter string 2\n");
    scanf("%s",&y);

    int m=strlen(x);
    int n=strlen(y);



    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                l[i][j]=0;
            }
            else if (x[i-1]==y[j-1])
            {
                l[i][j]=l[i-1][j-1]+1;
                arrow[i][j]='d';
            }
            else if(l[i-1][j]>l[i][j-1])
            {
                l[i][j]=l[i-1][j];
                arrow[i][j]='l';
            }
            else{
                l[i][j]=l[i][j-1];
                arrow[i][j]='u';
            }
        }
    }
    printf("therefore the length of the lcs is %d\n",l[m][n]);
    printf("therefore the lcs is\n");
    printlcs(m,n);
    return 0;
}
void printlcs(int i, int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    else if(arrow[i][j]=='d')
    {
        printlcs(i-1,j-1);
        printf("%c",x[i-1]);
      
    }
    else if(arrow[i][j]=='l')
    {
        printlcs(i-1,j);
    }
    else{
        printlcs(i,j-1);
    }
}