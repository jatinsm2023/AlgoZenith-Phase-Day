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
    int n, setsize;
    vector<int> parent, rank;

public:
    Union(int a)
    {
        n = a;
        setsize = a;
        parent.assign(n + 1, 0);
        rank.assign(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (x == parent[x])
            return x;
        else
            return parent[x] = find(parent[x]);
    }
    void merge(int x, int y)
    {
        int xroot = find(x);
        int yroot = find(y);
        if (xroot != yroot)
        {
            if (rank[xroot] >= rank[yroot])
            {
                parent[yroot] = xroot;
                rank[xroot] += rank[yroot];
            }
            else
            {
                parent[xroot] = yroot;
                rank[yroot] += rank[xroot];
            }
            setsize -= 1;
        }
    }
    int getsize()
    {
        return setsize;
    }
};

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    Union uf(n);
    vector<pair<int, state>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    int cost = 0;
    for (auto x : edges)
    {
        if (uf.find(x.second.first) != uf.find(x.second.second))
        {
            uf.merge(x.second.first, x.second.second);
            cost += x.first;
            ans++;
        }
    }
    if (ans != n - 1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << cost << '\n';
    }
}