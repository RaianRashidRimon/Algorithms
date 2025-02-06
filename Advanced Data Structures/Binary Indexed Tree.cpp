#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int BIT[MAXN];
int n;
void update(int idx, int val) {
    while (idx <= n) {
        BIT[idx] += val;
        idx += (idx & -idx);
    }
}
int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(i, x);}
        int l, r;
        cin >> l >> r;
        cout << query(r) - query(l-1) << endl;
    return 0;
}
