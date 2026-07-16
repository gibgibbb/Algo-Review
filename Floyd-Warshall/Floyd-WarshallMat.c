#include <stdio.h>
#include <stdlib.h>

#define SENTINEL -1
#define MAX 10
#define INF 9999

typedef struct{
    int adj[MAX][MAX];
    int vertices;
}Graph;

void printPath(int next[][MAX], int start, int end){

    if(next[start][end] == SENTINEL){
        printf("No Path\n");
        return;
    }

    printf("%d", start);

    while(start != end){
        start = next[start][end];
        printf(" -> %d", start);
    }
    printf("\n");
}

void floydWarshall(Graph G){

    int dist[MAX][MAX];
    int next[MAX][MAX];

    int i, j, k;

    /* Initialize */
    for(i = 0; i < G.vertices; i++){
        for(j = 0; j < G.vertices; j++){
            if(i == j){
                dist[i][j] = 0;
                next[i][j] = SENTINEL;
            }else if(G.adj[i][j] != 0){
                dist[i][j] = G.adj[i][j];
                next[i][j] = j;
            }else{
                dist[i][j] = INF;
                next[i][j] = SENTINEL;
            }
        }
    }

    /* Floyd-Warshall */

    for(k = 0; k < G.vertices; k++){
        for(i = 0; i < G.vertices; i++){
            for(j = 0; j < G.vertices; j++){
                if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    /* Display Distance Matrix */

    printf("Distance Matrix\n");

    for(i = 0; i < G.vertices; i++){
        for(j = 0; j < G.vertices; j++){
            if(dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    /* Display All Paths */
    printf("Shortest Paths\n");
    for(i = 0; i < G.vertices; i++){
        for(j = 0; j < G.vertices; j++){
            if(i != j){
                printf("%d -> %d : ", i, j);
                printPath(next, i, j);
            }
        }
    }
}


int main(){

    // Initializing a test graph
    // 0 represents no direct edge between the nodes
    Graph G = {
        {
            {0, 3, 0, 7, 0}, // Edges from Node 0 (A): to 1(B)=3, to 3(D)=7
            {8, 0, 2, 0, 0}, // Edges from Node 1 (B): to 0(A)=8, to 2(C)=2
            {5, 0, 0, 1, 0}, // Edges from Node 2 (C): to 0(A)=5, to 3(D)=1
            {2, 0, 0, 0, 0}, // Edges from Node 3 (D): to 0(A)=2
            {0, 0, 0, 0, 0}  // Node 4 (E): Unused in this 4-vertex example
        },
        4 // Number of vertices we want the algorithm to process
    };

    floydWarshall(G);

    return 0;
}
