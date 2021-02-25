// Floyd Warshall Algorithm to find the shortest path using an intermediate node
#include <bits/stdc++.h> 
using namespace std; 

#define N 100 
// Infinity defined 
const int INF = 1e7; 

int dis[N][N]; 
int Next[N][N]; 

// Initializing the distance and 
// Next array
//vectors are used
void initialise(int V, 
				vector<vector<int> >& graph) 
{ 
	for (int i = 0; i < V; i++) { 
		for (int j = 0; j < V; j++) { 
			dis[i][j] = graph[i][j]; 

			// if no edge between nodes 
			if (graph[i][j] == INF) 
				Next[i][j] = -1; 
			else
                //distance between nodes = j
				Next[i][j] = j; 
		} 
	} 
} 

// Function constructs the shotest 
// path between nodes u and v 
vector<int> findPath(int u, 
						int v) 
{ 
	// If there's no path between 
	// node u and v, simply return 
	// an empty array 
	if (Next[u][v] == -1) 
		return {}; 

	// Storing the path in a vector 
	vector<int> path = { u }; 
	while (u != v) { 
		u = Next[u][v]; 
		path.push_back(u); 
	} 
	return path; 
} 

// Standard Floyd Warshall Algorithm 
void floydWarshall(int V) 
{ 
	for (int k = 0; k < V; k++) { 
		for (int i = 0; i < V; i++) { 
			for (int j = 0; j < V; j++) { 


				if (dis[i][k] == INF 
					|| dis[k][j] == INF) 
					continue; 

				if (dis[i][j] > dis[i][k] 
									+ dis[k][j]) { 
					dis[i][j] = dis[i][k] 
								+ dis[k][j]; 
					Next[i][j] = Next[i][k]; 
				} 
			} 
		} 
	} 
} 

void printPath(vector<int>& path) 
{ 
	int n = path.size(); 
	for (int i = 0; i < n - 1; i++) 
		cout << path[i] << " -> "; 
	cout << path[n - 1] << endl; 
} 

int main() 
{ 
	//Nodes
	int V = 25; 
    //Directed weighted graph
	
	vector<vector<int> > graph  = 
		{{ 0, 4, 3, INF, 7, 2, 3, INF, 7, INF, 3, INF, 7, 8, 3, INF, 7, 9, 3, INF, 7, INF, 3, INF, 7}, 
		{ 8, 0, 2, INF, 7, 3, INF, 7, 5, 3, INF, 7, 2, 3, INF, 7, INF, 3, INF, 7, 1, 3, INF, 7, 9}, 
		{ 5, INF, 0, 1, 7, 3, INF, 7, 5, 3, INF, 7, 8, 3, INF, 7, 4, 3, INF, 7, 5, 3, INF, 7, 9}, 
		{ 2, INF, INF, 0, 6, 3, INF, 7, 4, 3, 4, 7, INF, 3, 1, 7, 2, 3, 8, 7, INF, 3, INF, 7, 1},
		{ 3, 5, 3, INF, 0, INF, 3, INF, 7, 8, 3, 4, 7, INF, 3, 4, 7, 8, 3, 9, 7, INF, 3, INF, 7},
		{ 2, 3, 5, INF, 6, 0, 7, INF, 7, INF, 3, INF, 7, 6, 3, INF, 7, 4, 3, INF, 7, 9, 3, INF, 1}, 
		{ 8, 5, 2, INF, 8, 3, 0, 7, INF, 3, INF, 7, 6, 3, INF, 7, 3, 3, INF, 7, 8, 3, INF, 7, 6}, 
		{ 5, INF, 9, 1, 6, 1, INF, 0, 7, 3, INF, 7, INF, 3, INF, 9, 8, 3, INF, 7, 4, 3, INF, 7, INF}, 
		{ 2, INF, INF, 8, 5, 4, INF, 7, 2, 0, INF, 8, 5, 3, INF, 7, 7, INF, INF, 2, 4, 3, INF, 7, 8},
		{ 1, 5, 3, INF, 7, 8, 3, INF, 7, 0, 3, INF, 3,7, 3, INF, 7, INF, 3, INF, 7, 9, 3, INF, 7},
		{ 9, 7, 3, INF, 7, 5, 3, INF, 7, 5, 0, INF, 7, INF, 3, INF, 7, 2, 3, INF, 9, 5, 3, INF, 7}, 
		{ 8, 4, 2, INF, 6, 3, INF, 7, 9, 3, INF, 0, 3, 3, INF, 7, 2, 3, INF, 7, 7, 3, INF, 7, INF}, 
		{ 5, INF, 4, 1, 6, 3, INF, 7, 6, 3, INF, 7, 0, 3, INF, 7, 4, 3, INF, 7, INF, 3, INF, 7, 1}, 
		{ 2, INF, INF, 4, 5, 3, INF, 7, 8, 3, INF, 7, 4, 0, INF, 7, 5, 3, INF, 7, 6, 3, INF, 7, 2},
		{ 9, 2, 3, INF, 7, 6, 3, INF, 7, 4, 3, INF, 7, 3, 0, INF, 7, 2, 3, INF, 8, 4, 3, INF, 7},
		{ 8, 2, 3, INF, 7, 3, 3, INF, 9, 4, 3, INF, 7, 2, 3, 0, 7, INF, 3, INF, 7, INF, 3, INF, 7}, 
		{ 8, 3, 2, INF, 5, 3, INF, 7, 6, 3, INF, 7, 2, 3, INF, 7, 0, 3, INF, 7, 8, 3, INF, 7, 3}, 
		{ 5, INF, 4, 1, 7, 3, INF, 7, 6, 3, INF, 7, 2, 3, INF, 7, 1, 0, INF, 7, 2, 3, INF, 7, 5}, 
		{ 2, INF, INF, 4, 2, 3, INF, 7, 8, 3, INF, 7, 8, 3, INF, 7, 5, 3, 0, 7, 5, 3, INF, 7, 7},
		{ 6, 7, 3, INF, 7, 4, 3, INF, 7, 3, 3, INF, 7, 9, 3, INF, 7, 4, 3, 0, 7, INF, 3, INF, 7},
		{ 5, 2, 3, INF, 7, 9, 3, INF, 7, 4, 3, INF, 7, 3, 3, INF, 7, 6, 3, INF, 0, INF, 3, INF, 7}, 
		{ 8, 6, 2, INF, 2, 3, INF, 7, 7, 3, INF, 7, 4, 3, INF, 7, 2, 3, INF, 7, 8, 0, INF, 7, 3}, 
		{ 5, INF, 4, 1, INF, 3, INF, 7, 5, 3, INF, 7, 8, 3, INF, 7, 9, 3, INF, 7, 1, 3, 0, 7, 9}, 
		{ 2, INF, INF, 9, 2, 3, INF, 7, 4, 3, INF, 7, 6, 3, INF, 7, 1, 3, INF, 7, 7, 3, INF, 0, 8},
		{ 6, 4, 3, INF, 7, 2, 3, INF, 7, 9, 3, INF, 7, 8, 3, INF, 7, 6, 3, INF, 7, INF, 3, INF, 0}
		};
	initialise(V, graph); 

	floydWarshall(V); 
	vector<int> path; 

	//Random paths shown as output
	cout << "Shortest path from 1 to 3: "; 
	path = findPath(1, 3); 
	printPath(path); 

	cout << "Shortest path from 0 to 7: "; 
	path = findPath(0, 7); 
	printPath(path); 

	cout << "Shortest path from 3 to 10: "; 
	path = findPath(3, 2); 
	printPath(path); 

	return 0; 
} 
