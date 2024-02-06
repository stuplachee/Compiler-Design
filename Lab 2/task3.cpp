#include<iostream>
using namespace std;

void output()
{
    string a;
    cin >> a;
    if(a[0] == '/' && a[1] == '/'){
        cout << "single line comment" << endl;
    }
    else if(a[0] == '/' && a[1] == '*' && a[a.size()-2] == '*' && a[a.size()-1] == '/'){
        cout << "Multiple line comment" << endl;
    }
    else{
        cout << "Not comment line" << endl;
    }

}

int main()
{
    output();
    return 0;
}
