#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
    int V;
    list<int>* adj;
    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
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

void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack)
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
            topologicalSortUtil(*i, visited, Stack);
        }
    }
    Stack.push(v);
}

void Graph::topologicalSort()
{
    stack<int> Stack;

    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, visited, Stack);
        }
    }
    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
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
    cout << "Topological Sort of the given graph is:" << endl;
    g.topologicalSort();
    return 0;
}
