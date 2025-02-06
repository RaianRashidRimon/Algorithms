#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int BIT[MAXN];
int n;

void update(int idx, int val)
{
    while (idx <= n)
    {
        BIT[idx] += val;
        idx += (idx & -idx);
    }
}
int query(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += BIT[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int rangeQuery(int l, int r)
{
    return query(r) - query(l - 1);
}

int main()
{
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        update(i, x);
    }
    int q;
    cout << "Enter number of queries: ";
    cin >> q;
    while (q--)
    {
        int l, r;
        cout << "Enter range (l r): ";
        cin >> l >> r;
        cout << "Sum in range [" << l << ", " << r << "] = " << rangeQuery(l, r) << endl;
    }
    return 0;
}
