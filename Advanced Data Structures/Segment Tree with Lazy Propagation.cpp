#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000001;
int a[MAX], tree[4 * MAX], lazy[4 * MAX];

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

void propagate(int node, int start, int end)
{
    if (lazy[node] != 0)
    {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end)
        {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int l, int r, int val)
{
    propagate(node, start, end);
    if (r < start || end < l)
    {
        return;
    }
    else if (l <= start && end <= r)
    {
        lazy[node] += val;
        propagate(node, start, end);
    }
    else
    {
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

int query(int node, int start, int end, int l, int r)
{
    propagate(node, start, end);
    if (r < start || end < l)
    {
        return 0;
    }
    else if (l <= start && end <= r)
    {
        return tree[node];
    }
    else
    {
        int mid = (start + end) / 2;
        int left_sum = query(2 * node, start, mid, l, r);
        int right_sum = query(2 * node + 1, mid + 1, end, l, r);
        return left_sum + right_sum;
    }
}

int main()
{
    int n, q;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    cout << "Enter number of queries: ";
    cin >> q;
    while (q--)
    {
        int type;
        cout << "Enter query type (1 for update, 2 for sum query): ";
        cin >> type;

        if (type == 1)
        {
            int l, r, val;
            cout << "Enter update range (l r) and value to add: ";
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        }
        else if (type == 2)
        {
            int l, r;
            cout << "Enter range (l r) to get sum: ";
            cin >> l >> r;
            cout << "Sum in range [" << l << ", " << r << "] is: " << query(1, 1, n, l, r) << endl;
        }
        else
        {
            cout << "Invalid query type! Please enter 1 or 2.\n";
        }
    }
    return 0;
}
