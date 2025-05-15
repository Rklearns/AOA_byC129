#include<stdio.h>
#define V 4 
#define INF 99999
int graph[V][V] = {
    {0,   5,  INF, 10},
    {INF, 0,   3, INF},
    {INF, INF, 0,   1},
    {INF, INF, INF, 0}
};  
void floyd();
int main()
{
    floyd();
    return 0;
}
void floyd()
{
    int dist[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(graph[i][j]==INF)
            {
                dist[i][j]=INF;
            }
            dist[i][j]=graph[i][j];
        }
    }
    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(dist[i][k]!=INF && dist[k][j]!=INF && (dist[i][k]+dist[k][j]<dist[i][j]))
            {
                dist[i][j]= dist[i][k]+dist[k][j];
            }
        }
    }
    }
    printf("All-pairs shortest distances:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}
