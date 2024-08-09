#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int, int> mp;
        for( int i=0 ;i<n;i++)
        {
            int x;
            cin>>x;
            mp[x]++;
        }
        int sol = 0;
        for(auto x: mp)
        {
            if(x.first>x.second){
                sol+=x.second;
            }
            else if(x.first<x.second)
            {
                sol+=x.second-x.first;
            }
        }
        cout<<sol<<'\n';
    }
}