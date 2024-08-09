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
        int n, m, r, c;
        cin >> n >> m >> c >> r;
        vector<pair<int, state>> g;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            g.push_back({r, {a, b}});
        }

        for (int i = 1; i <= n; i++)
        {
            g.push_back({c, {n + 1, i}});
        }
        sort(g.begin(), g.end());
        
        Union u(n + 1);
        int ans = 0;
        for (auto x : g)
        {
            int a = x.second.first;
            int b = x.second.second;
            int c = x.first;
            // cout<<a<<" "<<b<<' '<<c<<"\n";
            if (u.find(a) != u.find(b))
            {
                u.merge(a, b);
              
                ans += c;
            }
        }
        cout << ans << '\n';
    }
}