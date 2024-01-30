#include<iostream>
using namespace std;

int main()
{
    int i,arr[10],max,min;
    cout<<"Enter elements of array: ";
    for(i=0; i<10; i++)
        cin>>arr[i];

    cout<<"array is: ";
    for(i=0; i<10; i++)
        cout<<arr[i]<<"  ";

    max=arr[0];
    min=arr[0];
    for(i=0; i<10; i++)
        if(max<arr[i])
            max=arr[i];
        else if(min>arr[i])
            min=arr[i];

    cout<<"\nMaximum element of Array is: "<<max;
    cout<<"\nMinimum element of Array is: "<<min;
    return 0;
}
