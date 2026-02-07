Question 7 documentation:

DIJKSTRA'S ALGORITHM - SHORTEST PATH

Graph Representation:
- Weighted graph using adjacency matrix
- graph[i][j] contains weight of edge from vertex i to j
- graph[i][j] = 0 means no edge exists
- Uses INF (INT_MAX) to represent infinity

Algorithm Purpose:
- Finds shortest path from source vertex to all other vertices
- Works only with non-negative edge weights
- Greedy algorithm approach

Data Structures:
- dist[] - Stores shortest distance from source to each vertex
- visited[] - Tracks whether vertex is processed or not

Basic Functions:
- minDistance() - Finds unvisited vertex with minimum distance
  * Searches through all vertices
  * Returns vertex with smallest distance value
  * Returns -1 if no unvisited vertex found

- displayGraph() - Prints adjacency matrix
- printSolution() - Displays shortest distances from source

Dijkstra's Algorithm Steps:
1. Initialize all distances as INF, visited as false
2. Set distance of source vertex to 0
3. For each vertex:
   - Find unvisited vertex with minimum distance (u)
   - Mark vertex u as visited
   - Update distances of all adjacent vertices of u:
     * If edge exists and new path is shorter
     * dist[v] = dist[u] + graph[u][v]
4. Repeat until all vertices are visited


MAIN METHOD ORGANIZATION

1. Create weighted graph with 5 vertices (0 to 4)
2. Add weighted edges:
   (0,1)=10, (0,4)=5, (1,2)=1, (1,4)=2
   (2,3)=4, (3,0)=7, (3,2)=6, (4,1)=3
   (4,2)=9, (4,3)=2
3. Display adjacency matrix
4. Run Dijkstra's algorithm from source vertex 0
5. Display shortest distances to all vertices


SAMPLE OUTPUT

Adjacency Matrix (Weighted Graph):
   0  1  2  3  4  
0: 0  10  0  0  5  
1: 0  0  1  0  2  
2: 0  0  0  4  0  
3: 7  0  6  0  0  
4: 0  3  9  2  0  

Shortest distances from source vertex 0:
Vertex		Distance from Source
0			0
1			8
2			9
3			7
4			5

SHORTEST PATHS FROM VERTEX 0

To vertex 0: 0 (distance = 0)
To vertex 1: 0 -> 4 -> 1 (distance = 8)
To vertex 2: 0 -> 4 -> 1 -> 2 (distance = 9)
To vertex 3: 0 -> 4 -> 3 (distance = 7)
To vertex 4: 0 -> 4 (distance = 5)


Explanation:
- Algorithm selects minimum distance vertex each iteration
- Updates distances of neighbors if shorter path found
- Greedy choice leads to globally optimal solution
- Time complexity: O(V²) where V is number of vertices
- Works only with non-negative weights
