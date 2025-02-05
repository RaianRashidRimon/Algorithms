#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1000;
const int LOG = 10;
vector<int> tree[MAXN];
int parent[MAXN][LOG];
int depth[MAXN];
int n;

void dfs(int node, int par, int d) {
    parent[node][0] = par;
    depth[node] = d;
    for (int child : tree[node]) {
        if (child != par) {
            dfs(child, node, d + 1);
        }
    }
}

void preprocessLCA() {
    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 0; i < n; i++) {
            if (parent[i][j - 1] != -1) {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

int findLCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for (int i = 0; (1 << i) <= diff; i++) {
        if (diff & (1 << i)) {
            u = parent[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main() {
    cout << "Enter number of nodes: ";
    cin >> n;
    memset(parent, -1, sizeof(parent));
    cout << "Enter " << n - 1 << " edges (parent child):\n";
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(0, -1, 0);
    preprocessLCA();
    int q;
    cout << "Enter number of queries: ";
    cin >> q;
    cout << "Enter " << q << " queries (node1 node2):\n";
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << "LCA of " << u << " and " << v << " is: " << findLCA(u, v) << endl;
    }
    return 0;
}
