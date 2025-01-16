#include <iostream>
using namespace std;

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int start, int end) {
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

int main() {
    int n, arr[1000];
    cout << "Enter array size: \n";
    cin >> n;
    cout << "Enter the array elements: \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
