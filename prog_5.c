#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure for BFS
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return item;
}

// Add edge to undirected graph
void addEdge(int adjMatrix[][MAX], int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

// Display adjacency matrix
void displayMatrix(int adjMatrix[][MAX], int numVertices) {
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < numVertices; i++)
        printf("%d ", i);
    printf("\n");
    
    for (int i = 0; i < numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// BFS traversal using queue
void BFS(int adjMatrix[][MAX], int numVertices, int startVertex) {
    Queue q;
    initQueue(&q);
    
    int visited[MAX] = {0};
    
    visited[startVertex] = 1;
    enqueue(&q, startVertex);
    
    printf("BFS Traversal starting from vertex %d: ", startVertex);
    
    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);
        
        // Visit all adjacent vertices
        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

// DFS helper function using recursion
void DFSUtil(int adjMatrix[][MAX], int numVertices, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    // Visit all adjacent vertices
    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(adjMatrix, numVertices, i, visited);
        }
    }
}

// DFS traversal using recursion
void DFS(int adjMatrix[][MAX], int numVertices, int startVertex) {
    int visited[MAX] = {0};
    
    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFSUtil(adjMatrix, numVertices, startVertex, visited);
    printf("\n");
}

int main() {
    int adjMatrix[MAX][MAX] = {0};
    int numVertices = 6;
    
    /* Example Graph:
           0 --- 1 --- 2
           |     |
           3 --- 4 --- 5
    */
    
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 3, 4);
    addEdge(adjMatrix, 4, 5);
    
    displayMatrix(adjMatrix, numVertices);
    
    printf("\n");
    BFS(adjMatrix, numVertices, 0);
    BFS(adjMatrix, numVertices, 2);
    
    printf("\n");
    DFS(adjMatrix, numVertices, 0);
    DFS(adjMatrix, numVertices, 2);
    
    return 0;
}