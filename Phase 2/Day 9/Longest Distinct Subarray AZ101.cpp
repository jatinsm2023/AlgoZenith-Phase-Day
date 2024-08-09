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
        int dicnt = 0;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        map<int,int> mp;
        int tail = 0;int head= -1;
        int ans = 0;
        while(tail<n)
        {
            while(head+1<n && mp[a[head+1]]==0){
                dicnt++;
                head++;
                mp[a[head]]++;
            }
            ans = max(ans,dicnt);
            dicnt--;
            if(tail>head){
                tail++;
                head = tail-1;
            }
            else {
                mp[a[tail]]--;
                tail++;
            }
        }
        cout<<ans<<'\n';
    }
}