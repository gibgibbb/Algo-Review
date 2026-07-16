#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int vertex;
    int weight;
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

void initGraph(Graph *G, int vertices) {
    int i;
    G->vertices = vertices;
    for (i = 0; i < vertices; i++) {
        G->head[i] = NULL;
    }
}

void addEdge(Graph *G, int src, int dest, int weight) {
    AdjList newNode = (AdjList)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->vertex = dest;
        newNode->weight = weight;
        newNode->next = G->head[src];
        G->head[src] = newNode;
    }
}


void BFS(Graph G, int start) {
    Queue Q;
    int visited[MAX] = {0};
    int vertex;
    AdjList trav;

    initQueue(&Q);

    if (start >= 0 && start < G.vertices) {
        visited[start] = 1;
        enqueue(&Q, start);

        printf("BFS Traversal starting from vertex %d:\n", start);

        while (isEmpty(Q) == 0) {
            vertex = dequeue(&Q);
            if (vertex != -1) {
                printf("%d ", vertex);
                for (trav = G.head[vertex]; trav != NULL; trav = trav->next) {
                    if (visited[trav->vertex] == 0) {
                        visited[trav->vertex] = 1;
                        enqueue(&Q, trav->vertex);
                    }
                }
            }
        }
        printf("\n");
    }
}

int main() {
    Graph G;

    initGraph(&G, 6);

    addEdge(&G, 0, 1, 1);
    addEdge(&G, 0, 2, 1);
    addEdge(&G, 1, 3, 1);
    addEdge(&G, 1, 4, 1);
    addEdge(&G, 2, 5, 1);

    BFS(G, 0);

    return 0;
}
