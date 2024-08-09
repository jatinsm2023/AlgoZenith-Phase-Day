#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for (int  i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        int tail=0,head=-1;

        int Ksum=0;
        int ans =0;
        while(tail<n)
        {
            while(head+1<n && (Ksum+a[head+1]<=k ))
            {
                head++;
                Ksum+=a[head];
            }
            ans+=(head-tail+1);

            if(tail>head){
                tail++;
                head=tail-1;
            }
            else {
                Ksum-=a[tail];
                tail++;
            }
        }
        cout<<ans<<'\n';

    }
}