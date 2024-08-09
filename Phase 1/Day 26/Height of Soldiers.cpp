#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int pge[n];
        int nge[n];
        for( int i=0; i<n ;i++)
        {
            int val = i-1;
            while(val>=0 && a[val]>=a[i]){
                val = pge[val];
            }
            pge[i]=val;
        }
        for( int i=n-1; i>=0 ;i--)
        {
            int val = i+1;
            while(val<n && a[val]>=a[i]){
                val = nge[val];
            }
            nge[i]=val;
        }
        int ans[n]={};
        for( int i=0; i<n;i++)
        {
            int x = nge[i]-pge[i]-2;
            ans[x]=max(ans[x],a[i]);
        }
        for( int i=n-2; i>=0; i--)
        {
            ans[i]=max(ans[i],ans[i+1]);
        }
        for( int i=0; i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<'\n'; 
    }
}