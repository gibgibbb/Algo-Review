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

// Circular Queue

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

void BFS(Graph G, int start) {
    Queue Q;
    int visited[MAX] = {0};
    int i;
    int vertex;

    initQueue(&Q);

    if (start >= 0 && start < G.vertices) {
        visited[start] = 1;
        enqueue(&Q, start);

        while (isEmpty(Q) == 0) {
            vertex = dequeue(&Q);

            if (vertex != -1) {
                printf("%d ", vertex);

                for (i = 0; i < G.vertices; i++) {
                    if (G.adj[vertex][i] != 0 && visited[i] == 0) {
                        visited[i] = 1;
                        enqueue(&Q, i);
                    }
                }
            }
        }
        printf("\n");
    }
}

int main() {
    Graph G = {
        {
            {0, 1, 1, 1, 0, 0},
            {1, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 1, 0},
            {1, 0, 0, 0, 0, 1},
            {0, 0, 1, 0, 0, 1},
            {0, 0, 0, 1, 1, 0}
        }, 6
    };

    printf("BFS Traversal starting from vertex 0:\n");
    BFS(G, 0);

    return 0;
}
