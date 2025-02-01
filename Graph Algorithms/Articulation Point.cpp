#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 10005;
vector<int> adj[MAXN];
int dfs_num[MAXN], dfs_low[MAXN], parent[MAXN], articulation_point[MAXN];
int dfs_counter, root, root_children;
void articulationPoint(int u) {
    dfs_num[u] = dfs_low[u] = ++dfs_counter;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (dfs_num[v] == 0) {
            parent[v] = u;
            if (u == root)
                root_children++;
            articulationPoint(v);
            if (dfs_low[v] >= dfs_num[u])
                articulation_point[u] = 1;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);} else if (v != parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]); }}}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);}
    root = 1;
    dfs_counter = 0;
    articulationPoint(root);
    articulation_point[root] = (root_children > 1);
    cout << endl;
    cout << "Articulation points are"<<endl;
    for (int i = 1; i <= n; i++) {
        if (articulation_point[i])
            cout << i << " ";}
    cout << endl;
    return 0;}
