Question 5 documentation:

UNDIRECTED GRAPH USING ADJACENCY MATRIX

Graph Structure:
- 2D array where adjMatrix[i][j] = 1 means edge exists between vertex i and j
- adjMatrix[i][j] = 0 means no edge
- For undirected graph: adjMatrix[i][j] = adjMatrix[j][i]

Queue Structure (for BFS):
- Has 'items' array to store elements
- Has 'front' pointer for dequeue operation
- Has 'rear' pointer for enqueue operation

Basic Functions:
- addEdge() - Adds edge between two vertices
- displayMatrix() - Prints the adjacency matrix

BFS Function:
- Uses Queue (FIFO - First In First Out)
- Explores vertices level by level
- Uses visited array to track visited vertices
- Steps:
  * Mark start vertex as visited and enqueue it
  * While queue not empty:
    - Dequeue vertex and print it
    - Visit all unvisited adjacent vertices
    - Mark them visited and enqueue them

DFS Function:
- Uses Recursion (Stack - Last In First Out)
- Explores as deep as possible before backtracking
- Uses visited array to track visited vertices
- Steps:
  * Mark current vertex as visited and print it
  * Recursively visit all unvisited adjacent vertices


MAIN METHOD ORGANIZATION

1. Initialize adjacency matrix with all zeros
2. Create graph with 6 vertices (0 to 5)
3. Add edges: (0,1), (0,3), (1,2), (1,4), (3,4), (4,5)
4. Display adjacency matrix
5. Perform BFS from vertex 0
6. Perform BFS from vertex 2
7. Perform DFS from vertex 0
8. Perform DFS from vertex 2


SAMPLE OUTPUT

Adjacency Matrix:
   0 1 2 3 4 5 
0: 0 1 0 1 0 0 
1: 1 0 1 0 1 0 
2: 0 1 0 0 0 0 
3: 1 0 0 0 1 0 
4: 0 1 0 1 0 1 
5: 0 0 0 0 1 0 

BFS Traversal starting from vertex 0: 0 1 3 2 4 5 
BFS Traversal starting from vertex 2: 2 1 0 4 3 5 

DFS Traversal starting from vertex 0: 0 1 2 4 3 5 
DFS Traversal starting from vertex 2: 2 1 0 3 4 5 


GRAPH VISUALIZATION

       0 --- 1 --- 2
       |     |
       3 --- 4 --- 5


Explanation:
- BFS explores neighbors level by level using queue
- DFS explores depth first using recursion
- Both visit all vertices exactly once
- Different traversal orders based on exploration strategy