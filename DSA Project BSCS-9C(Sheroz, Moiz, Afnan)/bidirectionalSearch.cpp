//Bidirectional Search Algorithm to find the shortest path
#include <bits/stdc++.h>
using namespace std;
 
// class representing undirected graph
// using adjacency list representation
class Graph
{
    //number of nodes in graph
    int V;
 
    // Adjacency list of the nodes
    list<int> *AdjacencyList;
public:
    Graph(int V);
    int isIntersecting(bool *source_visited, bool *target_visited);
    void addEdge(int u, int v);
    void printPath(int *source_parent, int *target_parent, int s,
                             int t, int intersectNode);
    void BFS(list<int> *queue, bool *visited, int *parent);
    int BDS(int s, int t);
};
 
//Constructor 
Graph::Graph(int V)
{
    this->V = V;
    AdjacencyList = new list<int>[V];
};
 
void Graph::addEdge(int u, int v)
{
    this->AdjacencyList[u].push_back(v);
    this->AdjacencyList[v].push_back(u);
};
 
// Breath Fisrt Search using an iterator
void Graph::BFS(list<int> *queue, bool *visited,
                                    int *parent)
{
    int current = queue->front();
    queue->pop_front();
    list<int>::iterator i;
    for (i=AdjacencyList[current].begin();i != AdjacencyList[current].end();i++)
    {
        // If adjacent vertex is not visited earlier
        // mark it visited by assigning true value
        if (!visited[*i])
        {
            // set current node as parent of this vertex
            parent[*i] = current;
 
            // Mark this vertex visited i.e colour grey
            visited[*i] = true;
 
            queue->push_back(*i);
        }
    }
};
 
// check for intersecting point and return the node at which both the BFS meet
int Graph::isIntersecting(bool *source_visited, bool *target_visited)
{
    int intersectNode = -1;
    for(int i=0;i<V;i++)
    {
        // if a vertex is visited by both front
        // and back BFS search return that node
        // else return -1
        if(source_visited[i] && target_visited[i])
            return i;
    }
    return -1;
};
 

void Graph::printPath(int *source_parent, int *target_parent,
                  int s, int t, int intersectNode)
{
    vector<int> path;
    path.push_back(intersectNode);
    int i = intersectNode;
    while (i != s)
    {
        path.push_back(source_parent[i]);
        i = source_parent[i];
    }
    reverse(path.begin(), path.end());
    i = intersectNode;
    while(i != t)
    {
        path.push_back(target_parent[i]);
        i = target_parent[i];
    }
 
    vector<int>::iterator it;
    cout<<"*****Path*****\n";
    for(it = path.begin();it != path.end();it++)
        cout<<*it<<" ";
    cout<<"\n";
};
 
// Bidirectional Search
int Graph::BDS(int s, int t)
{

    bool source_visited[V], target_visited[V];
 
    // Keep track on parents of nodes
    // for front and backward search
    int source_parent[V], target_parent[V];
 
    // queue for front and backward search
    list<int> s_queue, t_queue;
 
    int intersectNode = -1;
 
    // no nodes visited initially
    for(int i=0; i<V; i++)
    {
        source_visited[i] = false;
        target_visited[i] = false;
    }
 
    s_queue.push_back(s);
    source_visited[s] = true;
 
    // parent of source is set to -1
    source_parent[s]=-1;
 
    t_queue.push_back(t);
    target_visited[t] = true;
 
    // parent of target is set to -1
    target_parent[t] = -1;
 
    while (!s_queue.empty() && !t_queue.empty())
    {
        // Do BFS from source and target nodes
        BFS(&s_queue, source_visited, source_parent);
        BFS(&t_queue, target_visited, target_parent);
 
        // check for intersecting node
        intersectNode = isIntersecting(source_visited, target_visited);
 
        // If intersecting node is found
        // that means there exist a path
        if(intersectNode != -1)
        {
            cout << "Path exist between " << s << " and "
                 << t << "\n";
            cout << "Intersection at: " << intersectNode << "\n";
 
            // print the path
            printPath(source_parent, target_parent, s, t, intersectNode);
            exit(0);
        }
    }
    return -1;
}
 

int main()
{
    // no of vertices in graph
    int n=100;
    int source, target;
    cout<<"Kindly enter the source and targer vertex: ";
    cin>>source>>target;
 
    // Undirected graph
    Graph g(n);
    g.addEdge(0, 4);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    g.addEdge(8, 10);
    g.addEdge(9, 11);
    g.addEdge(9, 12);
    g.addEdge(10, 13);
    g.addEdge(10, 14);
    g.addEdge(15, 16);
    g.addEdge(15, 18);
    g.addEdge(18, 25);
    g.addEdge(19, 26);
    g.addEdge(21, 23);
    g.addEdge(25, 24);
    g.addEdge(26, 37);
    g.addEdge(27, 18);
    g.addEdge(28, 29);
    g.addEdge(28, 10);
    g.addEdge(29, 31);
    g.addEdge(29, 42);
    g.addEdge(30, 33);
    g.addEdge(30, 14);
    g.addEdge(40, 64);
    g.addEdge(41, 54);
    g.addEdge(42, 55);
    g.addEdge(43, 65);
    g.addEdge(44, 76);
    g.addEdge(45, 86);
    g.addEdge(46, 83);
    g.addEdge(47, 80);
    g.addEdge(48, 96);
    g.addEdge(48, 90);
    g.addEdge(49, 67);
    g.addEdge(49, 87);
    g.addEdge(40, 81);
    g.addEdge(50, 14);
    g.addEdge(50, 24);
    g.addEdge(51, 34);
    g.addEdge(52, 45);
    g.addEdge(53, 55);
    g.addEdge(54, 66);
    g.addEdge(55, 76);
    g.addEdge(56, 87);
    g.addEdge(57, 98);
    g.addEdge(58, 49);
    g.addEdge(58, 30);
    g.addEdge(59, 41);
    g.addEdge(59, 72);
    g.addEdge(60, 93);
    g.addEdge(60, 4);
    g.addEdge(70, 14);
    g.addEdge(71, 24);
    g.addEdge(72, 35);
    g.addEdge(73, 45);
    g.addEdge(74, 56);
    g.addEdge(75, 66);
    g.addEdge(76, 77);
    g.addEdge(77, 88);
    g.addEdge(78, 59);
    g.addEdge(78, 40);
    g.addEdge(79, 61);
    g.addEdge(79, 72);
    g.addEdge(80, 23);
    g.addEdge(80, 94);
    g.addEdge(90, 4);
    g.addEdge(91, 14);
    g.addEdge(92, 25);
    g.addEdge(93, 35);
    g.addEdge(94, 46);
    g.addEdge(95, 56);
    g.addEdge(96, 67);
    g.addEdge(97, 78);
    g.addEdge(98, 89);
    g.addEdge(98, 90);
    g.addEdge(99, 11);
    g.addEdge(99, 32);
    g.addEdge(90, 63);
    g.addEdge(90, 84);
    if (g.BDS(source, target) == -1)
        cout << "Path don't exist between "
             << source << " and " << target << "\n";
 
    return 0;
}