#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 9999
#define SENTINEL -1

typedef struct{
    int adj[MAX][MAX];
    int vertices;
}Graph;

void bellmanFord(Graph G, int source){

    int dist[MAX];
    int parent[MAX];
    int i, u, v;

    /* Initialization */
    for(i = 0; i < G.vertices; i++){

        dist[i] = INF;
        parent[i] = SENTINEL;
    }
    
    dist[source] = 0;

    /* Relax all edges V-1 times */
    for(i = 0; i < G.vertices - 1; i++){
        for(u = 0; u < G.vertices; u++){
            for(v = 0; v < G.vertices; v++){
                if(G.adj[u][v] != 0 && dist[u] != INF && dist[u] + G.adj[u][v] < dist[v]){
                    dist[v] = dist[u] + G.adj[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    /* Negative Cycle Check */
    for(u = 0; u < G.vertices; u++){
        for(v = 0; v < G.vertices; v++){
            if(G.adj[u][v] != 0 && dist[u] != INF && dist[u] + G.adj[u][v] < dist[v]){
                printf("Negative Weight Cycle Detected!\n");
                return;
            }
        }
    }

    printf("Vertex\tDistance\tParent\n");

    for(i = 0; i < G.vertices; i++){
        printf("%c\t%d\t\t%d\n", 'A' + i, dist[i], parent[i]);
    }
}

int main(){

	Graph G = {
        {
            {0,4,2,5,0},
            {4,0,1,0,10},
            {2,1,0,3,0},
            {5,0,3,0,4},
            {0,10,0,4,0}
        }, 5
    };

    bellmanFord(G, 0);

	return 0;
}
