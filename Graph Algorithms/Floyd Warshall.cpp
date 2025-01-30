#include <iostream>
#include <vector>
using namespace std;
#define INF 99999

void printSolution(vector<vector<int> >& dist, int V);
void floydWarshall(vector<vector<int> >& graph, int V)
{
    vector<vector<int> > dist = graph;
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                        dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist, V);
}
void printSolution(vector<vector<int> >& dist, int V)
{
    cout << "The shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}
int main()
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    vector<vector<int> > graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix (use " << INF << " for infinity):\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }
    floydWarshall(graph, V);
    return 0;
}
