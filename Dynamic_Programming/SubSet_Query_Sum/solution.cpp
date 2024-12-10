
#include <bits/stdc++.h>
using namespace std;

#define ll int64_t

int dp[110][100100];
int rec(int x, int sum, vector<int> &arr)
{
    // pruning and break
    if (sum < 0)
        return 0;
    if (x == -1)
    {
        if (sum == 0)
            return 1;
        return 0;
    }
    // check if ans exist
    if (dp[x][sum] != -1)
        return dp[x][sum];
    dp[x][sum] = rec(x - 1, sum, arr) | rec(x - 1, sum - arr[x], arr);
    return dp[x][sum];
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries)
{
    memset(dp, -1, sizeof(dp));
    int n = arr.size();
    vector<vector<int>> solution;
    for (int i = 0; i < queries.size(); i++)
    {
        if (rec(n - 1, queries[i], arr))
        {
            vector<int> ans;
            int y = queries[i];
            int j = n - 1;
            while (y)
            {
                if (rec(j - 1, y - arr[j], arr))
                {
                    y -= arr[j];
                    ans.push_back(j);
                }
                j--;
            }
            reverse(ans.begin(),ans.end());
            solution.push_back(ans);
        }
        else
        {
            solution.push_back({-1});
        }
    }
    return solution;
}

void solve()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)
        cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q)
    {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++)
    {
        auto x = ans[i];
        if (x.size() == 0)
        {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1)
        {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x)
        {
            if (y < 0 || y >= N || p >= y)
            { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i])
        {
            cout << 1 << endl;
        }
        else
            cout << 101 << endl;
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
