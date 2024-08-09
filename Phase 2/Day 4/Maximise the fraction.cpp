#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double


int check(double mid, double a[], double b[],int k, int n){
    priority_queue<double> pq;
    double sol = 0.0;
    for( int i=0; i<n ;i++)
    {
        pq.push(a[i]-mid*b[i]);
    }
    for( int i=0 ; i<k ;i++)
    {
        sol+=pq.top();
        pq.pop();
    }
    return sol>=0;
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
        int n, k;
        cin >> n >> k;
        double a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        double ans = 0.0;
        double low = 0.0;
        double high = 10000;
        while (abs(high - low) > 1e-9)
        {
            double mid = (low + high) / 2;
            if (check(mid, a, b, k,n))
            {
                ans = mid;
                low = mid;
            }
            else high = mid;
        }
        cout<<fixed<<setprecision(6)<<ans<<'\n';
    }
}