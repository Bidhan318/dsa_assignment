#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

// Function to find vertex with minimum distance
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

// Display distance array
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

int main() {
    int vertices = 5;
    int graph[MAX][MAX] = {0};
    
    // Example weighted graph (adjacency matrix)
    // 0 means no edge
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
    
    return 0;
}