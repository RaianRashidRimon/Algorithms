#include<iostream>
using namespace std;
int main()
{
    int sizee;
    cout << "Enter the size of the array: \n";
    cin >> sizee;
    int i, arr[sizee], num, first, last, middle;
    cout<<"Enter array elements in a sorted manner: \n";
    for(i=0; i<sizee; i++)
        cin>>arr[i];
    cout<<"\nEnter Element to be Search: ";
    cin>>num;
    first = 0;
    last = sizee-1;
    middle = (first+last)/2;
    while(first <= last)
    {
        if(arr[middle]<num)
            first = middle+1;
        else if(arr[middle]==num)
        {
            cout<<"\nThe number, "<<num<<" found at Position "<<middle+1;
            break;
        }
        else
            last = middle-1;
        middle = (first+last)/2;
    }
    if(first>last)
        cout<<"\nThe requested number is not in the array";
    cout<<endl;
    return 0;
}
