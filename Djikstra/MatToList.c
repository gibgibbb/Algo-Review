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

//void matrixToList(GraphMatrix M, GraphList *L){
//
//    int i, j;
//
//    initGraphList(L, M.vertices);
//    for(i = 0; i < M.vertices; i++){
//        for(j = M.vertices - 1; j >= 0; j--){
//            if(M.adj[i][j] != 0){
//                insertEdge(L, i, j, M.adj[i][j]);
//            }
//        }
//    }
//}

void matrixToList(GraphMatrix M, GraphList *L){

    int i, j;

	// Initialization
    int x;
    L->vertices = M.vertices;
    for(x = 0; x < M.vertices; x++){
    	L->head[x] = NULL;
	}
    
    for(i = 0; i < M.vertices; i++){
        for(j = M.vertices - 1; j >= 0; j--){
            if(M.adj[i][j] != 0){
                AdjList temp;
                temp = (AdjList)malloc(sizeof(struct node));
                
                if(temp != NULL){
                	temp->vertex = j;
                	temp->weight = M.adj[i][j];
                	temp->next = L->head[i];
                	L->head[i] = temp;
				}
            }
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

    GraphMatrix M = {
        {
            {0,4,2,5,0},
            {4,0,1,0,10},
            {2,1,0,3,0},
            {5,0,3,0,4},
            {0,10,0,4,0}
        }, 5
    };

    GraphList L;
    displayMatrix(M);
    
    printf("\n");

    matrixToList(M, &L);
    displayList(L);

    return 0;
}
