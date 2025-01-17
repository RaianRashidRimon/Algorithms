#include<bits/stdc++.h>
using namespace std;
string Frame;
string Requests;
bool SearchRequests(string s, char x)
{
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]==x)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int FrameSize;
    cin >> FrameSize;
    cin>>Frame;
    cin>>Requests;

    int miss = 0;
    for (int i=0; i< Requests.size(); i++)
    {
        bool a = SearchRequests(Frame, Requests[i]);
        if (!a)
        {
            char x = Requests[i];
            int mx = 0, idx = 0;
            for (int j=0; j<Frame.size(); j++)
            {
                char ch = Frame[j];
                bool found = false;
                int p = 0;
                for (int k=i+1; k<Requests.size(); k++, p++)
                {
                    if (ch == Requests[k])
                    {
                        found = true;
                        break;
                    }
                }
                if (found == false)
                {
                    p = INT_MAX;
                }
                if (p > mx)
                {
                    mx = p;
                    idx = j;
                }
            }
            Frame[idx] = x;
            miss++;
        }
    }
    int h = Requests.size();
    int hits = h-miss;
    cout << endl;
    cout << "The Final Optimal Cache: " << Frame << "\n";
    cout << "Number of hits: " << hits << "\n";
    cout << "Number of misses: " << miss << "\n";
}
