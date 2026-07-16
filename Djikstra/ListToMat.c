#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INF 9999
#define SENTINEL -1

typedef struct{
    int adj[MAX][MAX];
    int vertices;
}GraphMatrix;

typedef struct node{
    int vertex;
    int weight;
    struct node *next;
}Node, *AdjList;

typedef struct{
    AdjList head[MAX];
    int vertices;
}GraphList;

void initGraphList(GraphList *G, int vertices){

    int x;
    G->vertices = vertices;

    for(x = 0; x < vertices; x++){
        G->head[x] = NULL;
    }
}

void initGraphMatrix(GraphMatrix *G, int vertices){

    int i, j;

    G->vertices = vertices;

    for(i = 0; i < vertices; i++){
        for(j = 0; j < vertices; j++){
            G->adj[i][j] = 0;
        }
    }
}

void insertEdge(GraphList *G, int src, int dest, int weight){

    AdjList temp;

    temp = (AdjList)malloc(sizeof(Node));

    if(temp != NULL){
        temp->vertex = dest;
        temp->weight = weight;
        temp->next = G->head[src];
        G->head[src] = temp;
    }
}

void listToMatrix(GraphList L, GraphMatrix *M){

    int i;
    AdjList trav;

	// Initialization
	//initGraphMatrix(M, L.vertices);
	int x, y;
	M->vertices = L.vertices;
	for(x = 0; x < L.vertices; x++){
		for(y = 0; y < L.vertices; y++){
			M->adj[x][y] = 0;
		}
	}
	
    for(i = 0; i < L.vertices; i++){
        for(trav = L.head[i]; trav != NULL; trav = trav->next){
			M->adj[i][trav->vertex] = trav->weight;
        }
    }
}

void displayMatrix(GraphMatrix G){

    int i, j;

    printf("Adjacency Matrix\n");
    for(i = 0; i < G.vertices; i++){
        for(j = 0; j < G.vertices; j++){
            printf("%3d", G.adj[i][j]);
        }
        printf("\n");
    }
}

void displayList(GraphList G){

    int i;

    AdjList trav;
    printf("Adjacency List\n");
    for(i = 0; i < G.vertices; i++){
        printf("%d :", i);
        for(trav = G.head[i]; trav != NULL; trav = trav->next){
            printf(" -> (%d,%d)", trav->vertex, trav->weight);
        }
        printf("\n");
    }
}

int main(){

    GraphList L;
    GraphMatrix M;

    initGraphList(&L, 5);

    insertEdge(&L, 0, 1, 4);
    insertEdge(&L, 0, 2, 2);
    insertEdge(&L, 0, 3, 5);

    insertEdge(&L, 1, 0, 4);
    insertEdge(&L, 1, 2, 1);
    insertEdge(&L, 1, 4, 10);

    insertEdge(&L, 2, 0, 2);
    insertEdge(&L, 2, 1, 1);
    insertEdge(&L, 2, 3, 3);

    insertEdge(&L, 3, 0, 5);
    insertEdge(&L, 3, 2, 3);
    insertEdge(&L, 3, 4, 4);

    insertEdge(&L, 4, 1, 10);
    insertEdge(&L, 4, 3, 4);

    displayList(L);

    listToMatrix(L, &M);

    printf("\n");

    displayMatrix(M);

    return 0;
}
