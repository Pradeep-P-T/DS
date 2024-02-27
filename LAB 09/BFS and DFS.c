#include<stdio.h>
#define MAX_VERTICES 50
typedef struct Graph_t {
    int V;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;
int DFS_V[50];
Graph* Graph_create(int V)
{
    Graph* g = malloc(sizeof(Graph));
    g->V = V;

    for (int i = 0; i <=V; i++) {
        for (int j = 0; j <=V; j++) {
            g->adj[i][j] = 0;
        }
    }

    return g;
}
void Graph_addEdge(Graph* g, int v, int w)
{
    g->adj[v][w] = 1;
    g->adj[w][v] = 1;
}
void BFS(Graph* g, int root){
    int visited[g->V+1];
    for(int i=0;i<=g->V;i++)
            visited[i]=0;

    int queue[g->V+1];
    int front=0,rear=0;
    visited[root]=1;

    queue[rear++]=root;
    while(front!=rear){
            root=queue[front++];
        printf("%d ",root);
        for(int i=0;i<=g->V;i++){
            if(g->adj[root][i]==1 && visited[i]!=1){
                visited[i]=1;
                queue[rear++]=i;
            }
        }
    }

}
int DFS(Graph *g,int root){
    for(int i=0;i<=g->V;i++){
        if(g->adj[root][i]==1 && DFS_V[i]!=1){
            DFS_V[i]=1;
            DFS(g,i);
        }
    }
    int count=0;
    for(int i=0;i<=g->V;i++){
        if(DFS_V[i]==1){
         count++;
        }
    }
    return count;
}
int main()
{

    Graph* g = Graph_create(4);
    Graph_addEdge(g, 0, 1);
    Graph_addEdge(g, 0, 4);
    Graph_addEdge(g, 1, 3);
    Graph_addEdge(g, 1, 2);
    Graph_addEdge(g, 2, 3);
    Graph_addEdge(g, 4, 3);
    printf("BFS traversal: ");
    BFS(g,0);
    int count=DFS(g,0);
    if(count==g->V+1){
        printf("\nGraph is connected");
    }
    else{
        printf("\nGraph is disconnected");
    }
}
