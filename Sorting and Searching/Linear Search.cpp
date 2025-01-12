#include <iostream>
using namespace std;

int main(){
    int input[100], count, i, num;
    cout << "Enter number of elements in array\n";
    cin >> count;
    cout << "Enter elements of the array\n";
    for(i = 0; i < count; i++){
        cin >> input[i];
    }
    cout << "Enter the requested number to find\n";
    cin >> num;
    for(i = 0; i < count; i++){
        if(input[i] == num){
            cout << "Element found at index " << i;
            break;
        }
    }
    if(i == count){
        cout  << "Element not found\n";
    }
    return 0;
}
