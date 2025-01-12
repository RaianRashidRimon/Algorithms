#include <bits/stdc++.h>
using namespace std;
struct Item
{
    float v;
    float w;
    float d;
};
bool compare(Item i1, Item i2)
{
    if(i1.d > i2.d)
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
    Item items[100];
    int W;
    cout<< "Enter Knapsack weight \n";
    cin >> W;
    int n;
    cout << "Enter the amount of items"<<"\n";
    cin >>n;
    for(int i=0; i<n; i++)
    {
        cout << "Enter Weight "<< i+1<<"\n";
        cin >> items[i].w;
        cout << "Enter Value "<< i+1<<"\n";
        cin >> items[i].v;
    }
    for (int i=0; i<n; i++)
    {
        items[i].d = items[i].v / items[i].w;
    }
    sort(items, items+n, compare);
    float totalValue = 0, totalWeight = 0;
     for(int i=0; i<n; i++)
    {
        if(totalWeight + items[i].w<= W)
        {
            totalValue += items[i].v ;
            totalWeight += items[i].w;
        }
        else
        {
            int wt = W-totalWeight;
            totalValue += (wt * items[i].d);
            totalWeight += wt;
            break;
        }
    }
    cout << "Max profit possible is "<< totalValue;
}
