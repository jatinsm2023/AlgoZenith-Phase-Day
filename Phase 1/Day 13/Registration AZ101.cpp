#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        map<string, int> mp;
        while(q--)
        {
            string s;
            cin>>s;
            if(!mp.count(s)){
                cout<<"OK\n";
            }
            else {
                cout<<s<<mp[s]<<'\n';
            }
            mp[s]++;
        }
    }
}