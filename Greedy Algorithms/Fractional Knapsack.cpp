#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    float v;
    float w;
    float d;
};

bool compare(Item i1, Item i2) {
    return i1.d > i2.d;
}

int main() {
    int W;
    cout << "Enter Knapsack weight: ";
    cin >> W;

    if (W <= 0) {
        cout << "Knapsack weight must be a positive value!" << endl;
        return 1;
    }

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of items must be positive!" << endl;
        return 1;
    }

    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter Weight of item " << i + 1 << ": ";
        cin >> items[i].w;
        if (items[i].w <= 0) {
            cout << "Weight must be positive!" << endl;
            return 1;
        }
        cout << "Enter Value of item " << i + 1 << ": ";
        cin >> items[i].v;
        if (items[i].v <= 0) {
            cout << "Value must be positive!" << endl;
            return 1;
        }
        items[i].d = items[i].v / items[i].w;
    }

    sort(items.begin(), items.end(), compare);

    float totalValue = 0, totalWeight = 0;

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].w <= W) {
            totalValue += items[i].v;
            totalWeight += items[i].w;
        } else {
            int wt = W - totalWeight;
            totalValue += wt * items[i].d;
            totalWeight += wt;
            break;
        }
    }

    cout << fixed << setprecision(2) << "Max profit possible is " << totalValue << endl;

    return 0;
}
