#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// --- Data Definitions ---

typedef struct node {
    int vertex;
    struct node *next;
} Node, *AdjList;

typedef struct {
    AdjList head[MAX];
    int vertices;
} Graph;

typedef struct {
    int elems[MAX];
    int front;
    int rear;
    int count;
} Queue;

// --- Circular Queue Operations ---

void initQueue(Queue *Q) {
    Q->front = 0;
    Q->rear = -1;
    Q->count = 0;
}

int isEmpty(Queue Q) {
    int empty = 0;
    if (Q.count == 0) {
        empty = 1;
    }
    return empty;
}

void enqueue(Queue *Q, int val) {
    if (Q->count < MAX) {
        Q->rear = (Q->rear + 1) % MAX;
        Q->elems[Q->rear] = val;
        Q->count++;
    }
}

int dequeue(Queue *Q) {
    int val = -1;
    if (Q->count > 0) {
        val = Q->elems[Q->front];
        Q->front = (Q->front + 1) % MAX;
        Q->count--;
    }
    return val;
}

// --- Graph Operations ---

void initGraph(Graph *G, int vertices) {
    int i;
    G->vertices = vertices;
    for (i = 0; i < vertices; i++) {
        G->head[i] = NULL;
    }
}

void addEdge(Graph *G, int src, int dest) {
    AdjList newNode = (AdjList)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->vertex = dest;
        newNode->next = G->head[src];
        G->head[src] = newNode;
    }
}

// --- Kahn's Algorithm (BFS-based) ---

void topoKahnList(Graph G) {
    int inDegree[MAX] = {0};
    int topo[MAX];
    int topoIdx = 0;
    int i;
    Queue Q;
    AdjList trav;

    initQueue(&Q);

    // 1. Calculate In-Degrees traversing all adj lists
    for (i = 0; i < G.vertices; i++) {
        for (trav = G.head[i]; trav != NULL; trav = trav->next) {
            inDegree[trav->vertex]++;
        }
    }

    // 2. Enqueue all vertices with an In-Degree of 0
    for (i = 0; i < G.vertices; i++) {
        if (inDegree[i] == 0) {
            enqueue(&Q, i);
        }
    }

    // 3. Process the queue
    while (isEmpty(Q) == 0) {
        int curr = dequeue(&Q);

        if (curr != -1) {
            topo[topoIdx] = curr;
            topoIdx++;

            // Decrease the in-degree of neighbors in the adjacency list
            for (trav = G.head[curr]; trav != NULL; trav = trav->next) {
                inDegree[trav->vertex]--;

                if (inDegree[trav->vertex] == 0) {
                    enqueue(&Q, trav->vertex);
                }
            }
        }
    }

    // Display Result
    printf("Kahn's Algorithm (Adjacency List): ");
    for (i = 0; i < topoIdx; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}

// --- DFS-based Topological Sort ---

// Recursive DFS helper
void dfsTopoHelperList(Graph G, int vertex, int visited[], int topo[], int *idx) {
    if (visited[vertex] == 0) {
        visited[vertex] = 1;

        AdjList trav;
        for (trav = G.head[vertex]; trav != NULL; trav = trav->next) {
            if (visited[trav->vertex] == 0) {
                dfsTopoHelperList(G, trav->vertex, visited, topo, idx);
            }
        }

        // Push to array on the way back up
        topo[*idx] = vertex;
        (*idx)--;
    }
}

void topoDFSList(Graph G) {
    int visited[MAX] = {0};
    int topo[MAX];
    int idx = G.vertices - 1;
    int i;

    // Call recursive DFS for all unvisited vertices
    for (i = 0; i < G.vertices; i++) {
        if (visited[i] == 0) {
            dfsTopoHelperList(G, i, visited, topo, &idx);
        }
    }

    // Display Result
    printf("DFS Algorithm   (Adjacency List): ");
    for (i = 0; i < G.vertices; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}

int main() {
    Graph G;
    initGraph(&G, 6);

    // Build the same DAG as Program 1
    // Edges: 0->2, 0->3, 1->3, 1->4, 2->5, 3->5, 4->5
    addEdge(&G, 0, 2);
    addEdge(&G, 0, 3);
    addEdge(&G, 1, 3);
    addEdge(&G, 1, 4);
    addEdge(&G, 2, 5);
    addEdge(&G, 3, 5);
    addEdge(&G, 4, 5);

    topoKahnList(G);
    topoDFSList(G);

    return 0;
}
