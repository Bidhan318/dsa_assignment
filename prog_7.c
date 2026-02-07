#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

// Find vertex with minimum distance from unvisited vertices
int minDistance(int dist[], int visited[], int vertices) {
    int min = INF;
    int minIndex = -1;
    
    for (int i = 0; i < vertices; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    
    return minIndex;
}

void printSolution(int dist[], int vertices, int source) {
    printf("\nShortest distances from source vertex %d:\n", source);
    printf("Vertex\t\tDistance from Source\n");
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INF)
            printf("%d\t\t\tINF\n", i);
        else
            printf("%d\t\t\t%d\n", i, dist[i]);
    }
}

// Dijkstra's algorithm implementation
void dijkstra(int graph[MAX][MAX], int vertices, int source) {
    int dist[MAX];
    int visited[MAX];
    
    // Initialize all distances as infinite and visited as false
    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    
    dist[source] = 0;
    
    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, visited, vertices);
        
        if (u == -1) break;
        
        visited[u] = 1;
        
        // Update distance of adjacent vertices
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] != 0 && 
                dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    printSolution(dist, vertices, source);
}

void displayGraph(int graph[MAX][MAX], int vertices) {
    printf("Adjacency Matrix (Weighted Graph):\n");
    printf("   ");
    for (int i = 0; i < vertices; i++)
        printf("%d  ", i);
    printf("\n");
    
    for (int i = 0; i < vertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < vertices; j++) {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices = 5;
    int graph[MAX][MAX] = {0};
    
    graph[0][1] = 10;
    graph[0][4] = 5;
    graph[1][2] = 1;
    graph[1][4] = 2;
    graph[2][3] = 4;
    graph[3][0] = 7;
    graph[3][2] = 6;
    graph[4][1] = 3;
    graph[4][2] = 9;
    graph[4][3] = 2;
    
    displayGraph(graph, vertices);
    
    dijkstra(graph, vertices, 0);
    
    return 0;
}