#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;                  
    list<int>* adj;         
public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int s)
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    delete[] visited;
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    Graph g(V);
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the edges (source destination):" << endl;
    for (int i = 0; i < E; i++)
    {
        int v, w;
        cin >> v >> w;
        g.addEdge(v, w);
    }
    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;
    cout << "Breadth First Traversal (starting from vertex " << startVertex << "):" << endl;
    g.BFS(startVertex);
    return 0;
}
