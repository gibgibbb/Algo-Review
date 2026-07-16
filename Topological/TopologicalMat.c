#include <stdio.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int count;
} Queue;

typedef struct {
    int adj[MAX][MAX];
    int vertices;
} Graph;

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

void enqueue(Queue *Q, int elem) {
    if (Q->count < MAX) {
        Q->rear = (Q->rear + 1) % MAX;
        Q->data[Q->rear] = elem;
        Q->count++;
    }
}

int dequeue(Queue *Q) {
    int val = -1;
    if (Q->count > 0) {
        val = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAX;
        Q->count--;
    }
    return val;
}

// --- Kahn's Algorithm (BFS-based) ---

void topoKahn(Graph G) {
    int inDegree[MAX] = {0};
    int topo[MAX];
    int topoIdx = 0;
    int i, j;
    Queue Q;

    initQueue(&Q);

    // 1. Calculate In-Degrees for all vertices
    for (i = 0; i < G.vertices; i++) {
        for (j = 0; j < G.vertices; j++) {
            if (G.adj[i][j] != 0) {
                inDegree[j]++;
            }
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

            // Decrease the in-degree of all adjacent vertices
            for (i = 0; i < G.vertices; i++) {
                if (G.adj[curr][i] != 0) {
                    inDegree[i]--;
                    // If in-degree becomes 0, enqueue it
                    if (inDegree[i] == 0) {
                        enqueue(&Q, i);
                    }
                }
            }
        }
    }

    // Display Result
    printf("Kahn's Algorithm (Adjacency Matrix): ");
    for (i = 0; i < topoIdx; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}

// --- DFS-based Topological Sort ---

// Recursive DFS helper
void dfsTopoHelper(Graph G, int vertex, int visited[], int topo[], int *idx) {
    if (visited[vertex] == 0) {
        visited[vertex] = 1;

        int i;
        for (i = 0; i < G.vertices; i++) {
            if (G.adj[vertex][i] != 0 && visited[i] == 0) {
                dfsTopoHelper(G, i, visited, topo, idx);
            }
        }

        // Push to array on the way back up the recursive stack
        topo[*idx] = vertex;
        (*idx)--;
    }
}

void topoDFS(Graph G) {
    int visited[MAX] = {0};
    int topo[MAX];
    int idx = G.vertices - 1; // Start inserting from the end of the array
    int i;

    // Call recursive DFS for all unvisited vertices
    for (i = 0; i < G.vertices; i++) {
        if (visited[i] == 0) {
            dfsTopoHelper(G, i, visited, topo, &idx);
        }
    }

    // Display Result
    printf("DFS Algorithm   (Adjacency Matrix): ");
    for (i = 0; i < G.vertices; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}

int main() {
    // Directed Acyclic Graph (DAG) for testing
    // Edges: 0->2, 0->3, 1->3, 1->4, 2->5, 3->5, 4->5
    Graph G = {
        {
            {0, 0, 1, 1, 0, 0},
            {0, 0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0}
        }, 6
    };

    topoKahn(G);
    topoDFS(G);

    return 0;
}
