#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        int swaps = 0;
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps = 1;
            }
        }
        if(!swaps)
            break;
    }
    cout << "Array after Sorting: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
