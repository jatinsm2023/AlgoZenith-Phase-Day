#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
 int digit( int n){
    int sum = 0;
    int r;
    while(n>0){
        r = n%10;
        sum+=r;
        n/=10;
    }
    return sum;
 }
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,s;
        cin>>n>>s;
        int low = 1, high = n;
        int ans = n+1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(abs(digit(mid)-mid)<s){
                low = mid + 1;
            }
            else {
                ans = mid;
                high = mid -1 ;
            }
        }
        cout<<n-ans+1<<'\n';
    }
}