#include<bits/stdc++.h>
using namespace std;

struct Event
{
    int time;
    int deadline;
    Event() {}
    Event(int t, int d)
    {
        time = t;
        deadline = d;
    }
};
bool com(Event a, Event b)
{
    return a.deadline < b.deadline;
}
int main()
{
    Event e[500];
    int n, ans1 = 0, require_time = 0;
    cout << "Enter the number of events: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter duration of event " << i + 1 << ": ";
        cin >> e[i].time;
        cout << "Enter deadline of event " << i + 1 << ": ";
        cin >> e[i].deadline;
    }
    sort(e, e + n, com);
    for (int i = 0; i < n; i++)
    {
        require_time += e[i].time;
        int lateness = max(0, require_time - e[i].deadline);
        ans1 = max(ans1, lateness);
    }
    cout << "\nMaximum Lateness: " << ans1 << endl;
    return 0;
}
