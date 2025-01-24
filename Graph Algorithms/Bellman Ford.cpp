#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void BellmanFord(vector<vector<int>>& graph, int V, int E, int src)
{
    vector<int> dis(V, INT_MAX);
    dis[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];
            if (dis[u] != INT_MAX && dis[u] + weight < dis[v])
            {
                dis[v] = dis[u] + weight;
            }
        }
    }
    for (int i = 0; i < E; i++)
    {
        int u = graph[i][0];
        int v = graph[i][1];
        int weight = graph[i][2];
        if (dis[u] != INT_MAX && dis[u] + weight < dis[v])
        {
            cout << "Graph contains a negative weight cycle" << endl;
            return;
        }
    }
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t\t" << dis[i] << endl;
    }
}
int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    vector<vector<int>> graph(E, vector<int>(3));
    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < E; i++)
    {
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
    }
    int src;
    cout << "Enter the source vertex: ";
    cin >> src;
    BellmanFord(graph, V, E, src);
    return 0;
}
