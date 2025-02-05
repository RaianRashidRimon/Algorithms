#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 10005;
int n;
char s[MAXN];
int sa[MAXN], rank[MAXN], tmp[MAXN];

bool cmp(int i, int j)
{
    if (rank[i] != rank[j])
        return rank[i] < rank[j];
    int ri = (i + n < MAXN) ? rank[i + n] : -1;
    int rj = (j + n < MAXN) ? rank[j + n] : -1;
    return ri < rj;
}
void buildSuffixArray()
{
    n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        sa[i] = i;
        rank[i] = s[i];
    }
    for (int k = 1; k < n; k <<= 1)
    {
        sort(sa, sa + n, cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        for (int i = 0; i < n; i++)
        {
            rank[i] = tmp[i];
        }
        if (rank[sa[n - 1]] == n - 1)
            break;
    }
}
int main()
{
    cout << "Enter a string: " ;
    cin >> s;
    buildSuffixArray();
    for (int i = 0; i < n; i++)
    {
        cout << sa[i] << " ";
    }
    cout << endl;
    return 0;
}
