#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, k;
vector<int> a, b;

int check(int mid) {
    int sol = 0;
    for (int i = 0; i < n; i++) {
        int lower = upper_bound(b.begin(), b.begin() + m, mid - a[i]) - b.begin();
        sol += lower;
    }
    return sol >= k;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        a.resize(n);
        b.resize(m);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int low = a[0] + b[0];
        int high = a[n - 1] + b[m - 1];
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
