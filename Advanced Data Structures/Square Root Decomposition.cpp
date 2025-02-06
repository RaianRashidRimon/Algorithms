#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int arr[MAXN], block[MAXN], blk_sz;

void build(int n)
{
    blk_sz = sqrt(n);
    memset(block, 0, sizeof(block));
    for (int i = 0; i < n; i++)
    {
        block[i / blk_sz] += arr[i];
    }
}
int query(int l, int r)
{
    int sum = 0;
    while (l <= r && l % blk_sz != 0)
    {
        sum += arr[l++];
    }
    while (l + blk_sz - 1 <= r)
    {
        sum += block[l / blk_sz];
        l += blk_sz;
    }
    while (l <= r)
    {
        sum += arr[l++];
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(n);
    int q;
    cout << "Enter number of queries: ";
    cin >> q;
    while (q--)
    {
        int l, r;
        cout << "Enter range (l r): ";
        cin >> l >> r;
        cout << "Sum in range [" << l << ", " << r << "] = " << query(l, r) << endl;
    }
    return 0;
}
