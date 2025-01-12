#include<iostream>
#include<vector>
#include<algorithm> // For sorting the array
using namespace std;

int main()
{
    int sizee;
    cout << "Enter the size of the array: ";
    cin >> sizee;

    if (sizee <= 0) {
        cout << "Array size should be greater than zero!" << endl;
        return 1;
    }

    vector<int> arr(sizee);
    int num, first, last, middle;

    cout << "Enter array elements: ";
    for (int i = 0; i < sizee; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    cout << "\nEnter Element to be Search: ";
    cin >> num;

    first = 0;
    last = sizee - 1;
    middle = (first + last) / 2;

    while (first <= last)
    {
        if (arr[middle] < num)
            first = middle + 1;
        else if (arr[middle] == num)
        {
            cout << "\nThe number, " << num << " found at Position " << middle + 1 << endl;
            break;
        }
        else
            last = middle - 1;

        middle = (first + last) / 2;
    }

    if (first > last)
        cout << "\nThe requested number is not in the array" << endl;

    return 0;
}
