#include<iostream>
using namespace std;

void output()
{
    string a;
    cout << "Enter a string: ";
    cin >> a;
    for(int i=0; i<a.size(); i++)
    {
        if((a[i]>='A' && a[i]<='Z') || (a[i]>='a' && a[i]<='z'))
        {
            cout << "not numeric" << endl;
            return;
        }
    }
    cout << "numeric constant" << endl;
}

int main()
{
    output();
}
