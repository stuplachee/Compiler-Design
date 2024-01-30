#include <iostream>
using namespace std;
#include <stack>

int main()
{
    string firstname, lastname;
    stack<char> Stack;


    cout << "Enter your first name: ";
    cin >> firstname;


    cout << "Enter your last name: ";
    cin >> lastname;


    for (char ch : firstname)
    {
        Stack.push(ch);
    }


    Stack.push(' ');


    for (char ch : lastname)
    {
        Stack.push(ch);
    }


    string fullName;
    while (!Stack.empty())
    {
        fullName = Stack.top() + fullName;
        Stack.pop();
    }


    cout << "Full name is: " << fullName <<endl;

    return 0;
}
