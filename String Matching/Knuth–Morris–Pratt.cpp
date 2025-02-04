#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void buildLPS(const char* pattern, vector<int>& lps, int m)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMP(const char* text, const char* pattern)
{
    int n = strlen(text);
    int m = strlen(pattern);
    vector<int> lps(m);
    buildLPS(pattern, lps, m);
    int i = 0, j = 0;
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }

        if (j == m)
        {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}
int main()
{
    string text, pattern;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;
    KMP(text.c_str(), pattern.c_str());
    return 0;
}
