#include <iostream>
#include <list>
#include <cmath>
using namespace std;

void display(int *array, int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void radixSort(int *arr, int n, int maxDigits) {
    list<int> buckets[10];
    for (int i = 0; i < maxDigits; i++) {
        int divisor = pow(10, i);
        for (int j = 0; j < n; j++) {
            int bucketIndex = (arr[j] / divisor) % 10;
            buckets[bucketIndex].push_back(arr[j]);
        }
        int idx = 0;
        for (int j = 0; j < 10; j++) {
            while (!buckets[j].empty()) {
                arr[idx++] = buckets[j].front();
                buckets[j].pop_front();
            }
        }
    }
}

int main() {
    int n, maxDigits;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the maximum number of digits in elements: ";
    cin >> maxDigits;

    int arr[n];
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    radixSort(arr, n, maxDigits);
    cout << "Sorted Array: ";
    display(arr, n);

    return 0;
}
