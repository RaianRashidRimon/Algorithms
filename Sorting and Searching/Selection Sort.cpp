#include <iostream>
using namespace std;
void SelectionSort (int arr[], int n)
{
	int i, j;
	for (i = 0; i < n; ++i){
		for (j = i+1; j < n; ++j){
			if (arr[i] > arr[j]){
				arr[i] = arr[i]+arr[j];
				arr[j] = arr[i]-arr[j];
				arr[i] = arr[i]-arr[j];
			}
		}
	}
}

int main()
{
	int n, i;
	cout<<"Enter the array size: \n";
	cin>>n;
	int arr[n];
	cout<<"Enter array elements: \n";
	for(i = 0; i < n; i++){
		cin>>arr[i];
	}
	SelectionSort(arr, n);
	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
    cout<<arr[i]<<" ";
	return 0;
}
