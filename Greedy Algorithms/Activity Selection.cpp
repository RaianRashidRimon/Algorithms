#include <iostream>
#include <algorithm>
using namespace std;
struct Activity {
    int start, end;
};
bool compare(Activity act1, Activity act2) {
    return act1.end < act2.end;
}
int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;
    Activity activities[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter start and end time for activity " << i + 1 << ":\n";
        cin >> activities[i].start >> activities[i].end;
    }
    sort(activities, activities + n, compare);
    int count = 1; 
    int lastSelected = 0;
    for (int j = 1; j < n; j++) {
        if (activities[j].start >= activities[lastSelected].end) {
            count++;
            lastSelected = j;
        }
    }
    cout << "\nTotal number of activities that can be done without overlapping is " << count << "\n";
    return 0;
}
