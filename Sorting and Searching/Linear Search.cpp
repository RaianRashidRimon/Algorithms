#include <iostream>
#include <vector>
using namespace std;

int main() {
    int count, num;

    cout << "Enter the number of elements in the array: ";
    cin >> count;

    if (count <= 0) {
        cout << "Invalid array size. Please enter a positive number." << endl;
        return 1;
    }

    vector<int> input(count);
    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < count; i++) {
        cin >> input[i];
    }

    cout << "Enter the number to find: ";
    cin >> num;

    vector<int> indices;
    for (int i = 0; i < count; i++) {
        if (input[i] == num) {
            indices.push_back(i);
        }
    }

    if (!indices.empty()) {
        cout << "Element " << num << " found at indices: ";
        for (int index : indices) {
            cout << index << " ";
        }
        cout << endl;
    } else {
        cout << "The requested number was not found in the array." << endl;
    }

    return 0;
}
