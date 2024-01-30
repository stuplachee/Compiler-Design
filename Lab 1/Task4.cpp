#include <iostream>

using namespace std;

int main()
{
    int i, num, fact = 1;

    cout << "Enter any positive number: ";
    cin >> num;
    cout<<"\n";

    for (int i = 1; i <= num; i++)
    {
        fact = fact*i;
    }

    cout << "Factorial of " << num << " is " << fact << endl;

    return 0;
}
