#include <bits/stdc++.h>
using namespace std;


void solve()
{
    string s;
    cin>>s;
    long long int sum =0;
    for( int i=0; i<s.length(); i++)
    {
        sum += s[i]-'0';
    }
    cout<<sum<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}