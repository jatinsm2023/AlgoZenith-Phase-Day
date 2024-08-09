#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a == -1 || b == -1)
    {
        cout<<"F"<<endl;
        return;
    }
    if(a+b>=80){
        cout<<"A"<<endl;
        return;
    }
    if(a+b<80 && a+b>=65)
    {
        cout<<"B"<<endl;
        return;
    }
    if(a+b<65 && a+b>=50)
    {
        cout<<"C"<<endl;
        return;
    }
    if(a+b<50 && a+b>=30)
    {
        if(c>=50)
        {
            cout<<"C"<<endl;
            return;
        }
        cout<<"D"<<endl;
        return;
    }
    if(a+b<30)
    {
        cout<<"F"<<endl;
        return;
    }

    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}