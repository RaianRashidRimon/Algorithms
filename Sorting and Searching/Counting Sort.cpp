#include<iostream>
#define MAX 255
using namespace std;

void countSort(int array[], int size)
{
    int output[MAX];
    int count[MAX];
    int max = array[0];
    for (int i = 1; i < size; i++){
        if (array[i] > max)
            max = array[i];}
    for (int i = 0; i <= max; ++i){
        count[i] = 0;}
    for (int i = 0; i < size; i++){
        count[array[i]]++;}
    for (int i = 1; i <= max; i++){
        count[i] += count[i - 1];}
    for (int i = size - 1; i >= 0; i--){
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;}
    for (int i = 0; i < size; i++){
        array[i] = output[i];}
}
void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array: \n";
    cin >> n;
    int array[n];
    cout<<"Enter array elements: \n";
    for(int i=0; i<n; i++)
    {
        cin >> array[i];
    }
    countSort(array, n);
    display(array, n);
    return 0;
}
