//Dijkstra's Algorithm to find the shortest path single source
#include <limits.h> // to use INT_MAX as Infinity
#include <stdio.h> 
  
// Number of nodes in the graph 
#define Nodes 9 
  
// Funtion to find the next node which yields the shortest path from the current node
//SptSet is the set containing the vertices which yield the shortest path tree i.e the nodes traversed to yield the shortest path
//Shortest Path Tree = SPT
int minDistance(int distance[], bool sptSet[]) 
{ 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < Nodes; v++) 
        if (sptSet[v] == false && distance[v] <= min) 
            min = distance[v], min_index = v; 
  
    return min_index; 
} 
  
void print(int distance[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < Nodes; i++) 
        printf("%d \t\t %d\n", i, distance[i]); 
} 
  
void dijkstra(int graph[Nodes][Nodes], int src) 
{ 
    int distance[Nodes];
  
    bool sptSet[Nodes]; // sptSet[i] will be true if vertex i is included in shortest 
  
    // Initialize all distances as INFINITE i.e unreachable and sptSet[] as false 
    for (int i = 0; i < Nodes; i++) 
        distance[i] = INT_MAX, sptSet[i] = false; 
  
    // Distance of source to itself is 0 for obvious reasons
    distance[src] = 0; 
  
    // Find shortest path for all vertices 
    for (int count = 0; count < Nodes - 1; count++) { 
        //Loop and keep including nodes that yield the shortest path utltimately
        int u = minDistance(distance, sptSet); 
  
        // Include the selected vertex in the spanning tree 
        //Recall Dijkstra's is based on Prims's Algorithm
        sptSet[u] = true; 
  
        // Update the distance values of adjacent nodes of the newly selected vertex
        for (int v = 0; v < Nodes; v++) 
  
            //Update only if newer distance is less and node is not included on sptSet already
            if (!sptSet[v] && graph[u][v] && distance[u] != INT_MAX 
                && distance[u] + graph[u][v] < distance[v]) 
                distance[v] = distance[u] + graph[u][v]; 
    } 

    print(distance); 
} 
  

int main() 
{ 
    //Adjacency Matrix of a random graph
    int graph[Nodes][Nodes] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                                { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                                { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                                { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                                { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                                { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                                { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                                { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    //Distance from node 0
    dijkstra(graph, 0); 
  
    return 0; 
} 