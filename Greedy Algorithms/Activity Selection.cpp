#include<iostream>
#include<algorithm>
using namespace std;
struct Activitiy
{
    int start, end;
};
bool comp(Activitiy act1, Activitiy act2)
{
    if(act1.end < act2.end)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    Activitiy act[100];
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cout << "Enter start time for task " << i+1 << "\n";
        cin >> act[i].start;
        cout << "Enter end time for task " << i+1 << "\n";
        cin >> act[i].end;
    }
    sort(act, act+n, comp);
    int i = 0, count = 1;
    for (int j = 1; j < n; j++)
    {
        if (act[j].start >= act[i].end)
        {
            count = count+1;
            i=j;
        }
    }
    cout << "\n";
    cout << "Total number of activities that can be done without overlapping is " << count <<"\n";
    return 0;
}
