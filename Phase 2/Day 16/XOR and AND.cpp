#include <bits/stdc++.h>
using namespace std;

#define int long long
const int m = 1e9+7;
int Sum( int a, int b)
{
    return (a%m+b%m)%m;
}
int nc2( int n){
    return (n*(n-1)/2)%m;
}
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
        int a[n];
        int pow2[n+1];
        pow2[0]=1;
        for( int i=1; i<=n ;i++)
        {
            pow2[i]=Sum(pow2[i-1],pow2[i-1]);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int sumXor = 0;
        int subsetXor = 0;
        int sumAnd = 0;
        int subsetAnd = 0;

        for( int i=0; i<31; i++)
        {
            int cnt =0;
            for( int j=0;j<n; j++)
            {
                if(a[j]&(1LL<<i))cnt++;
            }
            sumXor = Sum(sumXor, (1LL<<i)*(cnt%m*(n-cnt)%m));
            if(cnt)
            subsetXor = Sum(subsetXor, (1LL<<i)*(pow2[n-1]%m));
            sumAnd = Sum(sumAnd , (1LL<<i)*nc2(cnt)%m)%m;
            subsetAnd = Sum(subsetAnd, (1LL<<i)*(pow2[cnt]-1+m)%m);
        }
        cout<<sumXor<<" "<<subsetXor<<" "<<sumAnd<<" "<<subsetAnd<<'\n';
    }
}