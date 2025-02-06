#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int arr[MAXN], block[MAXN], blk_sz;
void build(int n) {
    blk_sz = sqrt(n);
    for (int i = 0; i < n; i++) {
        block[i/blk_sz] += arr[i];
    }
}
int query(int l, int r) {
    int sum = 0;
    while (l < r and l%blk_sz != 0 and l != 0) {
        sum += arr[l++];}
    while (l+blk_sz <= r) {
        sum += block[l/blk_sz];
        l += blk_sz;}
    while (l <= r) {
        sum += arr[l++];}
    return sum;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];}
    build(n);
    int l, r;
    cin >> l >> r;
    cout << query(l, r) << endl;
    return 0;
}
