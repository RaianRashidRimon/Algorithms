#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 10005;
vector<int> adj[MAXN];
int dfs_num[MAXN], dfs_low[MAXN], parent[MAXN], articulation_point[MAXN];
int dfs_counter, root, root_children;

void articulationPoint(int u)
{
    dfs_num[u] = dfs_low[u] = ++dfs_counter;
    for (int v : adj[u])
    {
        if (dfs_num[v] == 0)
        {
            parent[v] = u;
            if (u == root)
                root_children++;
            articulationPoint(v);
            if (dfs_low[v] >= dfs_num[u] && u != root)
                articulation_point[u] = 1;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != parent[u])
        {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main()
{
    int n, m;

    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    cout << "Enter the edges in the format 'u v' where u and v are the vertices connected by an edge:\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dfs_num, 0, sizeof(dfs_num));
    memset(dfs_low, 0, sizeof(dfs_low));
    memset(parent, -1, sizeof(parent));
    memset(articulation_point, 0, sizeof(articulation_point));
    dfs_counter = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dfs_num[i] == 0)
        {
            root = i;
            root_children = 0;
            articulationPoint(root);
            articulation_point[root] = (root_children > 1);
        }
    }
    cout << "Articulation points are: ";
    for (int i = 1; i <= n; i++)
    {
        if (articulation_point[i])
            cout << i << " ";
    }
    cout << endl;
    return 0;
}
