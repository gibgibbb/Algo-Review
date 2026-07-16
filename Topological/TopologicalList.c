#include <stdio.h>
#define MAX 10

// DFS Topological Sort

typedef struct node{
    int vertex;
    struct node *next;
}Node, *AdjList;

typedef struct{
    AdjList head[MAX];
    int vertices;
}Graph;

typedef struct{
    int data[MAX];
    int top;
}Stack;
