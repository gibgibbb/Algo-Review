#include <stdio.h>
#define MAX 10
#define INF 9999

typedef struct{
    int adj[MAX][MAX];
    int vertices;
}Graph;

int minDistance(int dist[], int visited[], int vertices){
    int min = INF;
    int minIndex = -1;
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

    int x, y, u;

    /* Initialization */
    for(x = 0; x < G.vertices; x++){
        dist[x] = INF;
        visited[x] = 0;
        parent[x] = -1;
    }

    dist[source] = 0;

    /* Main Algorithm */
    for(x = 0; x < G.vertices - 1; x++){
        /* Select smallest unvisited vertex */
        u = minDistance(dist, visited, G.vertices);

        if(u != -1){
        	visited[u] = 1;
        	for(y = 0; y < G.vertices; y++){
        		if(!visited[y] && G.adj[u][y] != 0 && dist[u] != INF && dist[u] + G.adj[u][y] < dist[y]){
        			dist[y] = dist[u] + G.adj[u][y];
                    parent[y] = u;
				}
			}
		}
    }

    /* Display Result */
    printf("Vertex\tDistance\tParent\n");
	for(x = 0; x < G.vertices; x++){
		printf("%c\t%d\t\t", 'A' + x, dist[x]);
    	if(parent[x] == -1){
        	printf("-\n");
    	}else{
        	printf("%c\n", 'A' + parent[x]);
    	}
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
    
    dijkstra(G, 0);
    
	return 0;
}
