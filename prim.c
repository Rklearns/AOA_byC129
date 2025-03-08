#include<stdio.h>
#include<limits.h>//this is used taaki INT_MAX ham nikaal sake
#define MAX 5//NOTE- IN PRIM ALGO NO VERTEX REPEATS MORE THAN TWICE YE IMP POINT HAI 
void primMST(int adj[MAX][MAX], int n);
int mincost=0;
int near[MAX];
int main() {
    int n = MAX;

    // Hardcoded adjacency matrix 
    int adj[MAX][MAX] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
   

    primMST(adj, n);
    printf("%d ",mincost);
    

    return 0;
}
void primMST(int adj[MAX][MAX], int n)
{
    int near[MAX];
    int t[MAX-1][2];//so ye basically store karta hai saare vertices ka pair of n-1 edges
    //sabse pehele hame minimum weight se chalu karna hoga so lets find that 
    int mini=INT_MAX;
    int x=-1;//these will store the minimum weight waale vertices
    int y=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(adj[i][j]<mini && adj[i][j]!=0)
            {
                mini=adj[i][j];
                x=i;
                y=j;
            }
        }
    }
    t[0][0]=x;
    t[0][1]=y;
    mincost+=adj[x][y];
    
    for(int i=0;i<n;i++)
    {
        if(adj[i][x]>adj[i][y])
        {
            near[i]=y;
        }
        else{
            near[i]=x;
        }
    }
    near[x]=0;
    near[y]=0;
    //now for the next n-2 edges we have to find the vertices
    for(int i=1;i<n-1;i++)
    {
        mini=INT_MAX;
        int j;
        for(int m=0;m<n;m++)
        {
            if(near[m]!=0 && mini>adj[m][near[m]])
            {
                j=m;
                mini=adj[m][near[m]]; // ab hamko j milgaya hai that is the vertex that is attached to x or y which has minimum edge
            }
        }
        t[i][0]=j;
        t[i][1]=near[j];
        mincost+=adj[j][near[j]];
        near[j]=0;//this will never be used again cuz

        for (int k = 0; k < n; k++) {
            if (near[k] != 0 && adj[k][near[k]] > adj[k][j]) 
                near[k] = j;  
        }


    }




}
