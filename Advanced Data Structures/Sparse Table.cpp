#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int K = 20;
int a[N], table[K][N];
void buildSparseTable(int n) {
    for (int i = 0; i < n; i++) {
        table[0][i] = a[i];}
    for (int k = 1; k < K; k++) {
        for (int i = 0; i + (1 << k) <= n; i++) {
            table[k][i] = min(table[k-1][i], table[k-1][i+(1<<(k-1))]);
        }
    }
}
int query(int L, int R) {
    int range = R - L + 1;
    int k = 31 - __builtin_clz(range);
    return min(table[k][L], table[k][R-(1<<k)+1]);}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    buildSparseTable(n);
    for(int j=0;j<=n-1;j++)
        {
            cout<<setw(3)<<fixed<<j<<" ";
        }
        cout<<"\n=====================================\n";
    for(int i=0;i<=log2(n);i++)
    {
        cout<<i<<": ";
        for(int j=0;j<=n-1;j++)
        {
            cout<<setw(3)<<fixed<<table[i][j]<<" ";
        }
        cout<<endl;
    }
        int L, R;
        cin >> L >> R;
        cout << query(L, R) << endl;
    return 0;
}

