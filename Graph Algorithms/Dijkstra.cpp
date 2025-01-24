#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define INF INT_MAX
int V;
int minDistance(vector<int>& dist, vector<bool>& sptSet)
{
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
void printSolution(vector<int>& dist)
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}
void dijkstra(vector<vector<int> >& graph, int src)
{
    vector<int> dist(V, INF);
    vector<bool> sptSet(V, false);
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    printSolution(dist);
}
int main()
{
    cout << "Enter the number of vertices: ";
    cin >> V;
    vector<vector<int> > graph(V, vector<int>(V, 0));
    int E;
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the edges in the format (source destination weight):" << endl;
    for (int i = 0; i < E; i++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src][dest] = weight;
        graph[dest][src] = weight;
    }
    int source;
    cout << "Enter the source vertex: ";
    cin >> source;
    dijkstra(graph, source);
    return 0;
}
