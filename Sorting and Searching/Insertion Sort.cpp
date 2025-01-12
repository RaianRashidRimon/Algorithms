#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int array[n];
    cout << "Enter " << n << " elements: \n";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    for (int k = 1; k < n; k++) {
        int temp = array[k];
        int j = k - 1;
        while (j >= 0 && temp < array[j]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }

    cout << "\nSorted list is: \n";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
