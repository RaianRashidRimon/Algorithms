#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int K;
vector<int> a;
vector<vector<int>> table;

void buildSparseTable(int n)
{
    K = log2(n) + 1;
    table.assign(K, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        table[0][i] = a[i];
    }

    for (int k = 1; k < K; k++)
    {
        for (int i = 0; i + (1 << k) <= n; i++)
        {
            table[k][i] = min(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
        }
    }
}
int query(int L, int R)
{
    if (L > R)
        swap(L, R);
    int range = R - L + 1;
    int k = log2(range);
    return min(table[k][L], table[k][R - (1 << k) + 1]);
}

void printSparseTable(int n)
{
    cout << "   ";
    for (int j = 0; j < n; j++)
    {
        cout << setw(3) << j << " ";
    }
    cout << "\n=====================================\n";
    for (int i = 0; i < K; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < n; j++)
        {
            if (j + (1 << i) > n)
                cout << "  - ";
            else
                cout << setw(3) << table[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    a.resize(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    buildSparseTable(n);
    printSparseTable(n);
    int L, R;
    while (true)
    {
        cout << "Enter L and R for range minimum query (-1 -1 to exit): ";
        cin >> L >> R;
        if (L == -1 && R == -1)
            break;

        if (L < 0 || R >= n)
        {
            cout << "Invalid range! Please enter values between 0 and " << n - 1 << endl;
            continue;
        }
        cout << "Minimum in range [" << L << ", " << R << "] = " << query(L, R) << endl;
    }
    return 0;
}
