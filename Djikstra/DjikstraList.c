#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INF 9999
#define SENTINEL -1

typedef struct node{
    int vertex;
    int weight;
    struct node *next;
}Node, *AdjList;

typedef struct{
    AdjList head[MAX];
    int vertices;
}Graph;

int minDistance(int dist[], int visited[], int vertices){
    int min = INF;
    int minIndex = SENTINEL;
    int x;

    for(x = 0; x < vertices; x++){
        if(!visited[x] && dist[x] < min){
            min = dist[x];
            minIndex = x;
        }
    }
    return minIndex;
}

void dijkstra(Graph G, int source){
    int dist[MAX];
    int visited[MAX];
    int parent[MAX];

    int x;
    int u;

    AdjList trav;

    /* Initialization */
    for(x = 0; x < G.vertices; x++){
        dist[x] = INF;
        visited[x] = 0;
        parent[x] = SENTINEL;
    }
    
    dist[source] = 0;

    /* Main Algorithm */
    for(x = 0; x < G.vertices - 1; x++){
    	u = minDistance(dist, visited, G.vertices);
    	if(u != SENTINEL){
    		visited[u] = 1;
    		for(trav = G.head[u]; trav != NULL; trav = trav->next){
    			if(!visited[trav->vertex] && dist[u] + trav->weight < dist[trav->vertex]){
    				dist[trav->vertex] = dist[u] + trav->weight;
    				parent[trav->vertex] = u;
				}
			}
		}
	}
	
    printf("Vertex\tDistance\tParent\n");
    for(x = 0; x < G.vertices; x++){
        printf("%c\t%d\t\t%d\n", 'A' + x, dist[x], parent[x]);
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

    dijkstra(G, 0);

    return 0;
}
