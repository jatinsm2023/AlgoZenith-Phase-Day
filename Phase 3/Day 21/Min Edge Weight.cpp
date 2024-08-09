#include <bits/stdc++.h>
using namespace std;

#define int long long
#define print(v)          \
    for (auto x : v)      \
        cout << x << ' '; \
    cout << endl;
#define yes() cout << 'YES<<endl';
#define no() cout << 'NO<<endl';
using state = pair<int, int>;

class Union
{
public:
    int n, size;
    vector<int> parent, rank;

    Union(int n)
    {
        this->n = n;
        size = n;
        parent.resize(n + 1);
        rank.assign(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int x, int y)
    {
        int xroot = find(x);
        int yroot = find(y);

        if (xroot != yroot)
        {
            if (rank[x] > rank[y])
            {
                parent[yroot] = xroot;
                rank[xroot] += rank[yroot];
            }
            else
            {
                parent[xroot] = yroot;
                rank[yroot] += rank[xroot];
            }
            size--;
        }
    }
};
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
        vector<pair<int, state>> g;
        for( int i=0; i<n-1; i++){
            int u, v, w;
            cin >> u >> v >> w;
            g.push_back({w, {u, v}});
        }
        sort(g.begin(), g.end());
        reverse(g.begin(),g.end());
        Union dsu(n);
        int ans = 0;
        for (auto x : g)
        {
            int u = x.second.first;
            int v = x.second.second;
            int w = x.first;
            if (dsu.find(u) != dsu.find(v))
            {
                ans+=w*(dsu.rank[dsu.find(u)]*dsu.rank[dsu.find(v)]);
                dsu.merge(u, v);
            }
        }
        cout << ans << '\n';
    }
}