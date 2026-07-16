#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    int adj[MAX][MAX];
    int vertices;
}Graph;

void dfs(Graph G, int vertex, int visited[]){

    int i;

    visited[vertex] = 1;

    printf("%c ", 'A' + vertex);

    for(i = 0; i < G.vertices; i++){
        if(G.adj[vertex][i] != 0 && !visited[i]){
            dfs(G, i, visited);
        }
    }
}

void DFS(Graph G){

    int visited[MAX] = {0};
    int i;

    for(i = 0; i < G.vertices; i++){
        if(!visited[i]){
            dfs(G, i, visited);
        }
    }

    printf("\n");
}

int main(){

    Graph G = {
        {
            {0,1,1,1,0,0},
            {1,0,0,0,0,0},
            {1,0,0,0,1,0},
            {1,0,0,0,0,1},
            {0,0,1,0,0,1},
            {0,0,0,1,1,0}
        },6
    };

    DFS(G);

    return 0;
}
