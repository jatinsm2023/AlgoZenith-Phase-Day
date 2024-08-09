#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long a, b,c;
        cin>>a>>b>>c;
        if(c%__gcd(a,b)==0){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
}