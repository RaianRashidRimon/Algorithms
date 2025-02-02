#include <bits/stdc++.h>
using namespace std;

vector<int> RabinKarp(string const& pattern, string const& text)
{
    const int p = 37;
    const int m = 1e9 + 7;
    int pattern_size = pattern.size(), text_size = text.size();
    vector<long long> p_pow(max(pattern_size, text_size));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;
    vector<long long> h(text_size + 1, 0);
    for (int i = 0; i < text_size; i++)
        h[i + 1] = (h[i] + (text[i] - 'a' + 1) * p_pow[i]) % m;
    long long h_pattern = 0;
    for (int i = 0; i < pattern_size; i++)
        h_pattern = (h_pattern + (pattern[i] - 'a' + 1) * p_pow[i]) % m;
    vector<int> occurrences;
    for (int i = 0; i + pattern_size - 1 < text_size; i++)
    {
        long long cur_h = (h[i + pattern_size] + m - h[i]) % m;
        if (cur_h == h_pattern * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}

int main()
{
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern to search: ";
    cin >> pattern;
    vector<int> occurrences = RabinKarp(pattern, text);
    if (occurrences.empty())
    {
        cout << "Pattern not found in the text.\n";
    }
    else
    {
        cout << occurrences.size() << " occurrences found at indices: ";
        for (size_t i = 0; i < occurrences.size(); i++)
        {
            cout << occurrences[i];
            if (i < occurrences.size() - 1)
                cout << ", ";
        }
        cout << endl;
    }
    return 0;
}
