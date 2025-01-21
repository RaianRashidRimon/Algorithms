#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    void addEdge(int v, int w);
    void DFS(int v);
};
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int v)
{
    visited[v] = true;
    cout << v << " ";

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}
int main()
{
    Graph g;
    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;
    cout << "Enter the edges (source destination):" << endl;
    for (int i = 0; i < numEdges; i++)
    {
        int v, w;
        cin >> v >> w;
        g.addEdge(v, w);
    }
    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;
    cout << "Following is Depth First Traversal (starting from vertex " << startVertex << "):" << endl;
    g.DFS(startVertex);
    return 0;
}
