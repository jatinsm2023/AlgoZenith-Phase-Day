#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    for( auto i:mp)
    {
        if(i.second%2!=0)
        {
            cout<<i.first<<endl;
            break;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}