#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 9999
#define SENTINEL -1

typedef struct node{
    int vertex;
    int weight;
    struct node *next;
}Node,*AdjList;

typedef struct{
    AdjList head[MAX];
    int vertices;
}Graph;

void bellmanFord(Graph G, int source){

    int dist[MAX];
    int parent[MAX];

    int i, u;

    AdjList trav;
    for(i = 0; i < G.vertices; i++){
        dist[i] = INF;
        parent[i] = SENTINEL;
    }

    dist[source] = 0;

    /* Relax edges */
    for(i = 0; i < G.vertices - 1; i++){
        for(u = 0; u < G.vertices; u++){
            for(trav = G.head[u]; trav != NULL; trav = trav->next){
                if(dist[u] != INF && dist[u] + trav->weight < dist[trav->vertex]){
					dist[trav->vertex] = dist[u] + trav->weight;
					parent[trav->vertex] = u;
                }
            }
        }
    }

    /* Negative Cycle */
    for(u = 0; u < G.vertices; u++){
        for(trav = G.head[u]; trav != NULL; trav = trav->next){
            if(dist[u] != INF && dist[u] + trav->weight < dist[trav->vertex]){
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

void insertEdge(Graph *G, int src, int dest, int weight){

    AdjList temp;

    /* src -> dest */
    temp = (AdjList)malloc(sizeof(Node));
    if(temp != NULL){
        temp->vertex = dest;
        temp->weight = weight;
        temp->next = G->head[src];
        G->head[src] = temp;
    }

    /* dest -> src */
    temp = (AdjList)malloc(sizeof(Node));
    if(temp != NULL){
        temp->vertex = src;
        temp->weight = weight;
        temp->next = G->head[dest];
        G->head[dest] = temp;
    }
}

void initGraph(Graph *G, int vertices){

    int x;

    G->vertices = vertices;

    for(x = 0; x < vertices; x++){
        G->head[x] = NULL;
    }
}

int main(){

    Graph G;

    initGraph(&G, 5);

    insertEdge(&G, 0, 1, 4);
    insertEdge(&G, 0, 2, 2);
    insertEdge(&G, 0, 3, 5);
    insertEdge(&G, 1, 2, 1);
    insertEdge(&G, 1, 4, 10);
    insertEdge(&G, 2, 3, 3);
    insertEdge(&G, 3, 4, 4);

	bellmanFord(G, 0);

    return 0;
}
