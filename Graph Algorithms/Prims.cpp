#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
void printMST(vector<int>& parent, vector<vector<int> >& graph, int V)
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}
int minKey(vector<int>& key, vector<bool>& mstSet, int V)
{
    int min = INF, min_index;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}
void primMST(vector<vector<int> >& graph, int V)
{
    vector<int> parent(V);
    vector<int> key(V, INF);
    vector<bool> mstSet(V, false);
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph, V);
}
int main()
{
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    vector<vector<int> > graph(V, vector<int>(V, 0));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];
    cout << "\nMinimum Spanning Tree (MST) using Prim's Algorithm:\n";
    primMST(graph, V);
    return 0;
}
