#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k;
int v[100100];

int check(int x) {
    int k_taken = 1; // Start with one subarray
    int current_sum = 0;
    
    for (int i = 0; i < n; i++) {
        if (current_sum + v[i] <= x) {
            current_sum += v[i];
        } else {
            k_taken++;
            current_sum = v[i];
        }
        if (k_taken > k) {
            return 0;
        }
    }
    return 1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n >> k;
        int mx = INT_MIN;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            mx = max(mx, v[i]);
            sum += v[i];
        }

        int low = mx, high = sum;
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
