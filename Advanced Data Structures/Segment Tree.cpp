#include <iostream>
using namespace std;

const int MAX = 100001;
int arr[MAX], tree[4 * MAX];
void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

int query(int node, int start, int end, int l, int r)
{
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
        int leftSum = query(2 * node, start, mid, l, r);
        int rightSum = query(2 * node + 1, mid + 1, end, l, r);
        return leftSum + rightSum;
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if (start == end)
    {
        arr[idx] = val;
        tree[node] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid)
        {
            update(2 * node, start, mid, idx, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

int main()
{
    int n, q;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter " << n << " elements of the array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    cout << "Enter the number of queries: ";
    cin >> q;
    cout << "Queries:\n";
    cout << "1 idx val - Update value at position idx to val (1-based index)\n";
    cout << "2 l r    - Query sum in range [l, r] (1-based index)\n";
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int idx, val;
            cout << "Enter index and new value: ";
            cin >> idx >> val;
            update(1, 0, n - 1, idx - 1, val);
        }
        else if (type == 2)
        {
            int l, r;
            cout << "Enter range [l, r] to query sum: ";
            cin >> l >> r;
            cout << "Sum in range [" << l << ", " << r << "] = " << query(1, 0, n - 1, l - 1, r - 1) << endl;
        }
        else
        {
            cout << "Invalid query type! Use 1 for update and 2 for sum query.\n";
        }
    }
    return 0;
}
