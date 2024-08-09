#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for( int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        int psm[n],nsm[n];
        for( int i=0; i<n ; i++)
        {
            int val = i-1;
            while(val>=0 && a[val]>=a[i]){
                val = psm[val];
            }
            psm[i] = val;
        }
        for( int i=n-1; i>=0 ; i--)
        {
            int val = i+1;
            while(val<n && a[val]>=a[i]){
                val = nsm[val];
            }
            nsm[i] = val;
        }

        int area = 0;
        for( int i=0; i<n; i++)
        {
            int height = a[i];
            int width = nsm[i]-psm[i]-1;
            area = max(area, height*width);
        }
        cout<<area<<"\n";
    }
}