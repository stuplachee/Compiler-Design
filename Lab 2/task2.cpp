#include<iostream>
using namespace std;

void output()
{
    string a;
    cout << "Enter a string: ";
    cin >> a;
    string ans={};
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='+'||a[i]=='-'||a[i]=='/'||a[i]=='*'||a[i]=='%'||a[i]=='='||a[i]=='^')
        {
            ans+=a[i];
        }
    }
    int n=ans.size();
    for(int i=0;i<n;i++)
    {
        cout<<"operator"<<i+1<<" "<<ans[i]<<endl;
    }
}

int main()
{
    output();
}
