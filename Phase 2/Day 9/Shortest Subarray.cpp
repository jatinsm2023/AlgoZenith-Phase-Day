#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> mp1;
        int distinct_elements = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (mp1[a[i]] == 0)
                distinct_elements++;
            mp1[a[i]]++;
        }

        map<int, int> mp;
        int tail = 0, head = -1;
        int dicnt = 0;
        int ans = INT_MAX;

        while (tail < n) {
            while (head + 1 < n && dicnt < distinct_elements) {
                head++;
                if (mp[a[head]] == 0)
                    dicnt++;
                mp[a[head]]++;
            }
            if (dicnt == distinct_elements)
                ans = min(ans, head - tail + 1);

            if (tail > head) {
                tail++;
                head = tail - 1;
            } else {
                if (mp[a[tail]] == 1)
                    dicnt--;
                mp[a[tail]]--;
                tail++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
