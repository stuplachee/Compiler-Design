#include <iostream>
using namespace std;

int main()
{
    int a;
    double num[50],avg,sum = 0 ;

    cout << "Enter the number of elements: ";
    cin >> a;

    for (int i = 0; i < a; ++i)
    {
        cout << i + 1 << "Enter number: ";
        cin >> num[i];
        sum += num[i];
    }

    avg = sum /a;
    cout << "The average is = " << avg;
    return 0;
}
