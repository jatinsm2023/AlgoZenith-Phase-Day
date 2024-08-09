#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x;
    string y;
    cin >> x >> y;
    string y1,y2;
    for( int i=0 ;i<y.length(); i++)
    {
        if(y[i]=='.'){
            y1=y.substr(0,i);
            y2=y.substr(i+1,y.length()-i-1);
            break;
        }
    }
    int z1 = 0;
    for( int i=0; i<y1.size(); i++)
    {
        z1 += y1[i]-'0';
        z1 *= 10;
    }
    int z2 = 0;
    for( int i=0; i<y2.size(); i++)
    {
        z2 += y2[i]-'0';
        z2 *= 10;
    }
    z1/=10;
    z2/=10;
    cout<<(x+z2)<<"."<<(x+z1)<<endl;
    
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